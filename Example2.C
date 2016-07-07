#include "TH1F.h"
#include "TH2F.h"
#include "TCanvas.h"

//Empezamos con el mismo codigo que antes
Int_t Example2 () {
  TH1F * hist = new TH1F ("hist","Title",100,0.,50.);
  //¡Ahora si no olvides los punto y comas!
  for (Int_t i=0;i<100;i++ ){
     //Como pasado i=50 caen fuera del rango
     //entonces no entran en el histograma.
     hist->Fill(i);
  }
  
Float_t ancho = 600;
Float_t alto = 400;

TCanvas * c1 = new TCanvas();
//Root dibuja sobre el canvas activo.
//En este caso es el unico que hemos definido.
c1->SetCanvasSize(ancho,alto);
hist->Draw();
TCanvas * c2 = new TCanvas();
c2->SetCanvasSize(ancho,alto);
//Solo podemos tener un canvas activo.
//Cuando se define un nuevo canvas, ese es el activo.
//Pero podemos cambiar de canvas usando:
c1->cd();

//Tambien podemos dividir el canvas en pads.
Int_t nColumnas = 3;
Int_t nFilas = 2;
c2->Divide(nColumnas,nFilas);
//Y cambiamos el subcanvas activo con:
c2->cd(1);
hist->Draw();
c2->cd(3);
hist->Draw();
c2->cd(5);
hist->Draw();
//Por cierto, aunque solo uno de los subcanvas este activo, 
//al usar Draw se dibujaran todos los subcanvas juntos.

  return 1;
}
