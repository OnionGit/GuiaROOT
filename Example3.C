#include "TH1F.h"
#include "TH2F.h"
#include "TF1.h"
#include "TMath.h"
#include "TCanvas.h"
#include <stdio.h>
#include <fstream>
#include "TStyle.h"

Int_t Example3()
{
TH1F * hist = new TH1F("hist","Ejemplo",5,0.,5.);
//Aqui hay algo muy raro. Los intervalos se empiezan a contar
//desde el 1, no desde 0. El 0 y el N+1 estan reservados para
//valores por debajo o por encima del rango, respectivamente.
hist->SetBinContent(1,100.);
hist->SetBinContent(2,50.);
hist->SetBinContent(3,25.);
hist->SetBinContent(4,10.);
hist->SetBinContent(5,5.);
//Esta opcion es para dibujar con errores.
hist->Draw("E1");
return 1;
}
