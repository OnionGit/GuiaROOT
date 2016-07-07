#include "TH1F.h"
#include "TH2F.h"
#include "TF1.h"
#include "TMath.h"
#include "TGraph.h"
#include "TString.h"
#include "TCanvas.h"
#include <stdio.h>
#include <TRandom3.h>
#include <fstream>

Int_t Example8()
{

TRandom * generadorX = new TRandom3();
//Podemos definir mas de un generador de numeros aleatorios.
//Esto es para probar la aletoriedad de nuestro generador.
//Puedes elegir otros generadores para compararlos.
TRandom * generadorY = new TRandom3();
TH2F * hist = new TH2F ("hist","Titulo",1000,0.,1.,1000,0.,1.);
Float_t x;
Float_t y;
//Hacemos avanzar el generador un paso.
x=generadorX->Rndm();
for (Int_t i = 0;i<3000000;i++){
//Vemos correlacion entre randoms consecutivos.
	x = generadorX->Rndm();
	y = generadorY->Rndm();
	hist->Fill(x,y);
}
//Esto dibuja el eje Z con colores.
hist->Draw("COLZ");
return 1;

}
