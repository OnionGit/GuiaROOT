#include "TH1F.h"
#include "TH2F.h"
#include "TF1.h"
#include "TFile.h"
#include "TTree.h"
#include "TRandom.h"
#include "TRandom1.h"
#include "TRandom2.h"
#include "TRandom3.h"
#include "TMath.h"
#include "TGraph.h"
#include "TString.h"
#include "TCanvas.h"
#include <stdio.h>
#include <fstream>

Int_t Example10W () {

TH2F * hist = new TH2F ("hist","Titulo",1000,0.,1.,1000,0.,1.);
//Este codigo puede tardar bastante si se aumenta el sample.
//Asi que definimos un archivo donde guardar los histogramas.
TFile *arxiv = new TFile("example.root","RECREATE");
//Definimos el tree, que es el objeto que almacenara
//todos los objetos que queremos guardar.
TTree *tree  = new TTree("tree","Ejemplo");
//La direccion del objeto a guardar.
tree->Branch("hist","TH2F",&hist);

//Regresamos al ejemplo de los numeros aleatorios.

TRandom * generadorX = new TRandom();
TRandom * generadorY = new TRandom();

TRandom1 * generadorX1 = new TRandom1();
TRandom1 * generadorY1 = new TRandom1();

TRandom2 * generadorX2 = new TRandom2();
TRandom2 * generadorY2 = new TRandom2();

TRandom3 * generadorX3 = new TRandom3();
TRandom3 * generadorY3 = new TRandom3();

Float_t x;
Float_t y;

x=generadorX->Rndm();
for (Int_t i = 0;i<1000000;i++){
	x = generadorX->Rndm();
	y = generadorY->Rndm();
        //Llenamos la rama del tree.
	hist->Fill(x,y);
}
tree->Fill();
hist->Reset();
x=generadorX1->Rndm();
for (Int_t i = 0;i<1000000;i++){
	x = generadorX1->Rndm();
	y = generadorY1->Rndm();
        //Cada vez que la llamas, copia la forma
        //actual del objeto.
	hist->Fill(x,y);
}
tree->Fill();
hist->Reset();
x=generadorX2->Rndm();
for (Int_t i = 0;i<1000000;i++){
	x = generadorX2->Rndm();
	y = generadorY2->Rndm();
	hist->Fill(x,y);
}
tree->Fill();
hist->Reset();
x=generadorX3->Rndm();
for (Int_t i = 0;i<1000000;i++){
	x = generadorX3->Rndm();
	y = generadorY3->Rndm();
	hist->Fill(x,y);
}
tree->Fill();

//Aqui lo escribimos al archivo.
tree->Write();
tree->Print();

return 1;
}
