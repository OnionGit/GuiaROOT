#include <string>
#include <vector>
#include <TCanvas.h>
#include <Riostream.h>
#include <TGraph.h>
#include <TGraphErrors.h>
#include <TMultiGraph.h>
#include <TString.h>
#include <TLegend.h>
#include <TH2F.h>
#include <TH1F.h>
#include <math.h>

//Datos extraidos del experimento AMS
Int_t Elements (){
Float_t electrons [74];
Float_t electronsFlux[74];
Float_t protons[72];
Float_t protonsFlux[72];
Float_t EMIN, EMAX, EMEAN, Y, STATMIN, STATMAX, SYSMIN ,SYSMAX;
Int_t count=0;

  FILE *fpElectrons = fopen("./electrons.txt", "r");
  while (fscanf (fpElectrons,"%f %f %f %f %f %f %f %f ", 
  &EMIN,&EMAX,&EMEAN,&Y,&STATMIN,&STATMAX,&SYSMIN,&SYSMAX)==8) 
  {
			electrons[count]=EMEAN;
			electronsFlux[count]=Y;
			count++;
			cout<<EMEAN<<endl;
  }
  fclose(fpElectrons);
  count = 0;
  FILE *fpProtons = fopen("./protons.txt", "r");
  while (fscanf (fpElectrons,"%f %f %f %f %f %f %f %f ", 
  &EMIN,&EMAX,&EMEAN,&Y,&STATMIN,&STATMAX,&SYSMIN,&SYSMAX)==8) 
  {
			protons[count]=EMEAN;
			protonsFlux[count]=Y;
			count++;
  }
  fclose(fpProtons);

  TMultiGraph *mg=new TMultiGraph();
  TCanvas *CanvasGraph = new TCanvas();

  TGraph* graficoElectrons=new TGraph(74,electrons,electronsFlux);
  graficoElectrons->SetMarkerStyle(21);
  graficoElectrons->SetMarkerColor(1);
  graficoElectrons->SetMarkerStyle(21);
  graficoElectrons->SetLineColor(kBlack);
  graficoElectrons->SetLineWidth(2);
  mg->Add(graficoElectrons,"P");

  TGraph* graficoProtons=new TGraph(72,protons,protonsFlux);
  graficoProtons->SetMarkerStyle(21);
  graficoProtons->SetMarkerColor(6);
  graficoProtons->SetMarkerStyle(21);
  graficoProtons->SetLineColor(kBlack);
  graficoProtons->SetLineWidth(2);
  mg->Add(graficoProtons,"P");

mg->SetTitle("Flux vs Energies");
gPad->Modified();
mg->Draw("A");
mg->GetXaxis()->SetTitle("Energia Cinetica[GeV]");
mg->GetYaxis()->SetTitle("Flujo[m^{-2}sr^{-1}s^{-1}GeV^{-1}]");

  TLegend *leg = new TLegend(0.65,0.6,0.9,0.9);
  leg->AddEntry(graficoElectrons,"e^{-} e^{+}: AMS-02", "p");
  leg->AddEntry(graficoProtons,"Protons: AMS-02", "p");
  leg->Draw();

  CanvasGraph-> SaveAs("./Graph.png");
return 1;
}
