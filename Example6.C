#include "TH1F.h"
#include "TH2F.h"
#include "TF1.h"
#include "TMath.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TString.h"
#include "TCanvas.h"
#include <stdio.h>
#include <fstream>

Int_t Example6()
{
Float_t x[5]={1.,2.,3.,4.,5.};
Float_t y[5]={1.,4.,3.,2.,1.};
Float_t errorx[5]={0.1,0.2,0.3,0.4,0.5};
Float_t errory[5]={0.5,0.4,0.3,0.2,0.1};
TGraphErrors* grafico = new TGraphErrors (5,x,y,errorx,errory);
grafico->SetMarkerColor(kRed);
grafico->SetMarkerStyle(kFullCircle);
grafico->SetLineStyle(9);
grafico->SetLineColor(kBlue);
TCanvas* c1 = new TCanvas();
grafico->Draw("APL");
return 1;
}
