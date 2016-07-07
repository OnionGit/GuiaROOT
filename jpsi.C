#include "TH1F.h"
#include "TH2F.h"
#include "TF1.h"
#include "TMath.h"
#include "TGraph.h"
#include "TString.h"
#include "TCanvas.h"
#include <stdio.h>
#include <fstream>
//Librerias utiles para lo que haremos.

Int_t jpsi() {
//El nombre y direccion del archivo de donde leemos los datos
TString fName = "./jpsi.dat";
//Abrimos la comunicacion con el archivos
ifstream rawfile(fName.Data());
//En caso el programa no encuentre el archivo, dara este error. 
//Si no esta esto la terminal se cuelga.
if(!rawfile.good()) {
        cout << "File not found!" << endl;
        return 0;
}

//Definimos variables para leer los datos.
Int_t Run;
Double_t Event;
Float_t E1;
Float_t E2;
Float_t PX1;
Float_t PZ1;
Float_t PT1;
Float_t PX2;
Float_t PZ2;
Float_t PT2;

TH1F *jpsi =
new TH1F("jpsi","J/Psi;Mass[GeV/c2];Counts",250,2.,5.)
//El punto y coma en el titulo es una forma
//rapida de poner titulos a los ejes.
while(rawfile >> Run>>Event>>E1>>PX1>>PY1>>PZ1
>>PT1>> E2>>PX2>>PY2>>PZ2>>PT2 && rawfile.good()){
        //La funcion pow es 'elevado a la...'
	Float_t mass = pow((pow((E1+E2),2)-pow((PX1+PX2),2) 
	-pow((PY1+PY2),2)-pow((PZ1+PZ2),2)),0.5);
	jpsi->Fill(mass);
}

TCanvas * c1 = new TCanvas();
c1->SetCanvasSize(1200,700);
jpsi->SetLineWidth(2.5);
jpsi->SetLineColor(kRed);
jpsi->SaveAs("./JPSI.sh")
c1->Draw();

return 1;
}
