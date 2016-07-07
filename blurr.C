#include "TH1F.h"
#include "TH2F.h"
#include "TF1.h"
#include "TFile.h"
#include "TTree.h"
#include "TMath.h"
#include "TGraph.h"
#include "TString.h"
#include "TCanvas.h"
#include <stdio.h>
#include <fstream>
#include "TStyle.h"
#include "TASImage.h"

void blurr(TString fName, UInt_t kN = 5)
{
   //El parametro es el nombre de la imagen + direccion.
   TASImage image(fName);
   //Obtenemos las dimensiones de la imagen
   UInt_t yPixels = image.GetHeight();
   UInt_t xPixels = image.GetWidth();
   //Sacamos el ARGB de la imagen. Esto incluye RGB + Alpha.
   UInt_t *argb   = image.GetArgbArray();

   TH2D* h = new TH2D("h","Image Histogram",xPixels,-1,1,yPixels,-1,1);

   for (UInt_t row=0; row<xPixels; ++row) {
      for (UInt_t col=0; col<yPixels; ++col) {
         //Colocamos el valor en cada punto.
         int index = col*xPixels+row;
         //Esto solo mide intensidad.
         //Del ARGB puedes sacar los colores tambien.
         float grey = float(argb[index]&0xff)/256;
	 //He agregado esta linea porque root
	 //No pone valores en cero con SetBinContent.
	 //En el original los puntos negros se vuelven blancos.
	 if(grey==0){grey = 0.000000001;}
	 grey = grey;
         h->SetBinContent(row+1,yPixels-col,grey);
      }
   }
   //Para que tenga algo de color.
   gStyle->SetPalette(53);


   for (UInt_t row=kN; row<xPixels-kN; ++row) {
      for (UInt_t col=kN; col<yPixels-kN; ++col) {
       int index = col*xPixels+row;
	   Float_t sum = 0;
	   for (UInt_t subrow = 0;subrow<=kN;subrow++){
		   for (UInt_t subcol=0;subcol<=kN;subcol++){
			if(subcol!=0||subrow!=0){
			sum = sum + float(argb[index+subrow+subcol*xPixels]&0xff)/256;
			sum = sum + float(argb[index-subrow+subcol*xPixels]&0xff)/256;
			if(subcol==0||subrow==0) {sum = sum + float(argb[index+subrow-subcol*xPixels]&0xff)/256;}
			if(subcol==0||subrow==0) {sum = sum + float(argb[index-subrow-subcol*xPixels]&0xff)/256;}
			}
		    
		   }	
		}
		Float_t original = float(argb[index]&0xff)/256;
	       if (sum!=0){
			Float_t blurry = (original + sum)/(pow(kN,2));
			h->SetBinContent(row+1,yPixels-col,blurry);	
			}
		else {h->SetBinContent(row+1,yPixels-col,original);}
      }
   }

   h->Draw("COLZ");
}
