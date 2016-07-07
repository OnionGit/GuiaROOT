#include "TH1F.h"
#include "TH2F.h"
#include "TF1.h"
#include "TRandom3.h"
#include "TMath.h"
#include "TGraph.h"
#include "TString.h"
#include "TCanvas.h"
#include <stdio.h>
#include <fstream>
#include "TStyle.h"
#include "TASImage.h"

Int_t Example9()
{
//Para hacer un fit definimos funciones con parametros libres.
TF1* f1 =new TF1("f1","[0]*x*x+sin(x*[1])",-5.,5.);
//Los numeros en corchetes son los parametros libres.
//Los podemos setear de la siguientes formas...
//Uno por uno:
f1->SetParameter(0,500.);
f1->SetParameter(1,350.);
//O todos de una sola vez:
f1->SetParameters(500.,350.);
//Cuando root intenta hacer el fit, busca desde este valor.
//Es mas rapido, encuentra mejor el punto que buscas.

TH1F * hist = new TH1F ("hist","Titulo",100,-3.,3.);
TRandom3 * r = new TRandom3();
Float_t x;
for (Int_t i = 0;i<10000;i++){
x=r->Gaus();
hist->Fill(x);
}
hist->Draw();
//La cual ajusta pesimamente.
hist->Fit("f1");
//Esta sale mejor. Porque de ahi sacamos los datos.
hist->Fit("gaus","+");
return 1;

}
