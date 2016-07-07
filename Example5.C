#include "TH1F.h"
#include "TH2F.h"
#include "TF1.h"
#include "TMath.h"
#include "TGraph.h"
#include "TCanvas.h"
#include <stdio.h>
#include <fstream>

Int_t Example5()
{
Float_t x[5]={1.,2.,3.,4.,5.};
Float_t y[5]={5.,4.,3.,2.,1.};
//Entra el numero de elementos, y los dos vectores.
TGraph * grafico = new TGraph (5,x,y);
//Esta parte es solo estetica. El color y forma de los puntos.
grafico->SetMarkerColor(kRed);
grafico->SetMarkerStyle(kFullCircle);
//Y dibujamos el grafico.
TCanvas * c1 = new TCanvas();
grafico->Draw("APL");
return 1;

}
