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

Int_t Example10R(Int_t entry){

TFile *arxiv = new TFile("example.root");
//sacamos el tree con su nombre.
TTree *tree = (TTree*)arxiv->Get("tree");
//Declaramos un espacio de memoria
//en donde entrara el objeto
//que recuperemos.
TH2F * hist;
//Indicamos la direccion dentro del tree
//que acabamos de recuperar y lo asociamos
//al espacio de memoria de arriba.
tree->SetBranchAddress("hist",&hist);
//Sacamos una entrada.
tree->GetEntry(entry);
//Este objeto tiene toda la informacion del objeto anterior.
hist->Draw("COLZ");

return 1;

}
