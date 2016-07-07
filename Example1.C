#include "TH1F.h"
#include "TH2F.h"
#include "TMath.h"
#include <stdio.h>
#include <fstream>

Int_t Example1 () {
  TH1F * hist = new TH1F ("hist","Title",100,0.,50.);
  //¡Ahora si no olvides los punto y comas!
  for (Int_t i;i<100;i++ ){
     //Como pasado i=50 caen fuera del rango
     //entonces no entran en el histograma.
     hist->Fill(i);
  }
  return 1;
}
