#include "TCanvas.h"
#include "TH1D.h"
#include "TH2F.h"
#include "TF1.h"
#include "TGraphErrors.h"
#include "TNtuple.h"
#include "TLegend.h"
#include "TFile.h"
#include "TStyle.h"
#include "TROOT.h"
#include <fstream>
#include <string>


void style() {

   gStyle->Reset("Default");
   gStyle->SetCanvasColor(0);
   gStyle->SetPadColor(0);
   gStyle->SetTitleFillColor(10);
//    gStyle->SetTitleFont(42);
//    gStyle->SetTitleFont(42, "XYZ");
//    gStyle->SetTitleSize(0.04, "XYZ");
//    gStyle->SetTitleXOffset(1.);
//    gStyle->SetTitleYOffset(1.5);
//    gStyle->SetLabelFont(42, "XYZ");
//    gStyle->SetLabelSize(0.04, "XYZ");
   gStyle->SetCanvasBorderMode(0);
   gStyle->SetStatColor(0);
   gStyle->SetPadBorderMode(0);
   gStyle->SetPadLeftMargin(0.112);
   gStyle->SetPadRightMargin(0.128);
   gStyle->SetPadTickX(1);  // To get tick marks on the opposite side of the frame
   gStyle->SetPadTickY(1);
   gStyle->SetFrameBorderMode(0);
//    gStyle->SetStatFont(42);
//    gStyle->SetStatFontSize(0.05);
   gStyle->SetOptStat(111110);
   //gStyle->SetOptStat(111111);
   //gStyle->SetOptStat(kFALSE);
   gStyle->SetOptFit(1);

   
   gStyle->SetPalette(1);
   //gStyle->SetTitleX(0.10);
   //gStyle->SetTitleY(0.95);
   //gStyle->SetTitleW(0.40);
   //gStyle->SetTitleH(0.05);
   //gStyle->SetOptFit(111);
   gStyle->SetStatX(.88);
//    gStyle->SetStatY(1.);
//    gStyle->SetStatW(0.2);
   //gStyle->SetStatH(0.15);
}

void producePlot(const string& fFile, const Float_t fETMin, const Float_t fETMax, const string& fTitleExt, const string& fNameExt, const string& fExt) {

   TFile file(fFile.c_str());
   TDirectoryFile *subDir = (TDirectoryFile*)file.Get("hoStudy");
   TNtuple *ntuple = (TNtuple*)subDir->Get("n_Ntuple"); 
   Int_t nEntries = ntuple->GetEntries();

   Float_t genJetE, genJetEta, maxEnergyInHOChannel;
   // ntuple is of the form "GenJetE:GenJetEta:GenJetPhi:CaloJetE:CaloJetEta:CaloJetPhi:CaloJetWithHOE:CaloJetWithHOEta:CaloJetWithHOPhi:HadEnergyInHB:HadEnergyInHO:MaxEnergyInHOChannel"
   ntuple->SetBranchAddress("GenJetE",&genJetE);
   ntuple->SetBranchAddress("GenJetEta",&genJetEta);
   ntuple->SetBranchAddress("MaxEnergyInHOChannel",&maxEnergyInHOChannel);

   TH1F *h_MaxEInHOCh = new TH1F("h_MaxEInHOCh",";Max. E in HO Channel [GeV];Entries/(1 GeV)",500,0.,1000.);

   for (Int_t ent = 0; ent < nEntries; ent++) {
      ntuple->GetEntry(ent);

      Float_t genJetET = genJetE/cosh(genJetEta);
      if ( genJetET>fETMin && genJetET<fETMax ) h_MaxEInHOCh->Fill(maxEnergyInHOChannel);
   }

   TCanvas *c = new TCanvas("c","",1120,800);
//    TCanvas *c = new TCanvas("c","",800,750);
   c->cd();
   
   h_MaxEInHOCh->SetTitle(fTitleExt.c_str());
//    h_MaxEInHOCh->SetTitleOffset(1.5,"Y");
   h_MaxEInHOCh->Draw("");
   
   string name = h_MaxEInHOCh->GetName();
   string fileName = name + "_" + fNameExt + "." + fExt;
   
   c->SetLogy();
   c->SaveAs(fileName.c_str());
   
   delete c;
}

void makePlots() {
   // batch mode
   gROOT->SetBatch(kTRUE);
   // set ROOT style
   style();
//    gROOT->ForceStyle(); 
   //********************************************
   // root files
   //********************************************
   string hostudy_eta01 = "hoStudy_corr_eta0.1.root";
   string hostudy_eta05 = "hoStudy_corr_eta0.5.root";
   string hostudy_eta10 = "hoStudy_corr_eta1.0.root";
   //********************************************
   // make plots
   //********************************************
   producePlot(hostudy_eta01,40,60,"#eta=0.1, p_{T}=50 GeV/c","corr_eta0.1_pT50","png");
   producePlot(hostudy_eta01,90,110,"#eta=0.1, p_{T}=100 GeV/c","corr_eta0.1_pT100","png");
   producePlot(hostudy_eta01,290,310,"#eta=0.1, p_{T}=300 GeV/c","corr_eta0.1_pT300","png");
   producePlot(hostudy_eta01,490,510,"#eta=0.1, p_{T}=500 GeV/c","corr_eta0.1_pT500","png");
   producePlot(hostudy_eta01,990,1010,"#eta=0.1, p_{T}=1000 GeV/c","corr_eta0.1_pT1000","png");
   producePlot(hostudy_eta01,1990,2010,"#eta=0.1, p_{T}=2000 GeV/c","corr_eta0.1_pT2000","png");
   producePlot(hostudy_eta01,3990,4010,"#eta=0.1, p_{T}=4000 GeV/c","corr_eta0.1_pT4000","png");
   producePlot(hostudy_eta01,6990,7010,"#eta=0.1, p_{T}=7000 GeV/c","corr_eta0.1_pT7000","png");
   producePlot(hostudy_eta05,40,60,"#eta=0.5, p_{T}=50 GeV/c","corr_eta0.5_pT50","png");
   producePlot(hostudy_eta05,90,110,"#eta=0.5, p_{T}=100 GeV/c","corr_eta0.5_pT100","png");
   producePlot(hostudy_eta05,290,310,"#eta=0.5, p_{T}=300 GeV/c","corr_eta0.5_pT300","png");
   producePlot(hostudy_eta05,490,510,"#eta=0.5, p_{T}=500 GeV/c","corr_eta0.5_pT500","png");
   producePlot(hostudy_eta05,990,1010,"#eta=0.5, p_{T}=1000 GeV/c","corr_eta0.5_pT1000","png");
   producePlot(hostudy_eta05,1990,2010,"#eta=0.5, p_{T}=2000 GeV/c","corr_eta0.5_pT2000","png");
   producePlot(hostudy_eta05,3990,4010,"#eta=0.5, p_{T}=4000 GeV/c","corr_eta0.5_pT4000","png");
   producePlot(hostudy_eta05,6990,7010,"#eta=0.5, p_{T}=7000 GeV/c","corr_eta0.5_pT7000","png");
   producePlot(hostudy_eta10,40,60,"#eta=1.0, p_{T}=50 GeV/c","corr_eta1.0_pT50","png");
   producePlot(hostudy_eta10,90,110,"#eta=1.0, p_{T}=100 GeV/c","corr_eta1.0_pT100","png");
   producePlot(hostudy_eta10,290,310,"#eta=1.0, p_{T}=300 GeV/c","corr_eta1.0_pT300","png");
   producePlot(hostudy_eta10,490,510,"#eta=1.0, p_{T}=500 GeV/c","corr_eta1.0_pT500","png");
   producePlot(hostudy_eta10,990,1010,"#eta=1.0, p_{T}=1000 GeV/c","corr_eta1.0_pT1000","png");
   producePlot(hostudy_eta10,1990,2010,"#eta=1.0, p_{T}=2000 GeV/c","corr_eta1.0_pT2000","png");
   producePlot(hostudy_eta10,3990,4010,"#eta=1.0, p_{T}=4000 GeV/c","corr_eta1.0_pT4000","png");
   producePlot(hostudy_eta10,6990,7010,"#eta=1.0, p_{T}=7000 GeV/c","corr_eta1.0_pT7000","png");
}