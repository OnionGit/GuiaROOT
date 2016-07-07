#include "TH1F.h"
#include "TH2F.h"
#include "TF1.h"
#include "TMath.h"
#include <stdio.h>
#include <fstream>
#include "TStyle.h"

Int_t Example4()
{
Float_t x [5]= {100.,50.,25.,10.,50.};
Float_t errorx [5] = {1.,2.,3.,2.,1.};
TH1F * hist = new TH1F("hist","Ejemplo",5,0.,5.);
for (Int_t i = 1; i<=5;i++){
hist->SetBinContent(i,x[i-1]);
hist->SetBinError(i,errorx[i-1]);
}
hist->Draw("E");
//Y luego podemos recuperar un valor.
Float_t value = hist->GetBinContent(3);
cout<<"El valor del intervalo 3 es: "<< value<<endl;
return 1;
}
