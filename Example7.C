#include "TH1F.h"
#include "TH2F.h"
#include "TF1.h"
#include "TFile.h"
#include "TTree.h"
#include "TMath.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TMultiGraph.h"
#include "TString.h"
#include "TCanvas.h"
#include <stdio.h>
#include <fstream>
#include "TStyle.h"
#include "TASImage.h"

Int_t Example7()
{
Float_t x[5]={1.,2.,3.,4.,5.};
Float_t y[5]={5.,4.,3.,2.,1.};
Float_t errorx[5]={0.1,0.2,0.3,0.4,0.5};
Float_t errory[5]={0.5,0.4,0.3,0.2,0.1};
TMultiGraph *multi = new TMultiGraph();
TGraphErrors *grafico=new TGraphErrors(5,x,y,errorx,errory);
TGraphErrors *grafico2=new TGraphErrors(5,x,y,errorx,errory);
multi->Add(grafico,"LP");
multi->Add(grafico2,"P");
grafico->SetMarkerColor(kRed);
grafico->SetMarkerStyle(kFullCircle);
grafico->SetLineStyle(9);
grafico->SetLineColor(kBlue);
grafico2->SetMarkerColor(kRed);
grafico2->SetMarkerStyle(kFullCircle);
multi->Draw("A");
return 1;

}
