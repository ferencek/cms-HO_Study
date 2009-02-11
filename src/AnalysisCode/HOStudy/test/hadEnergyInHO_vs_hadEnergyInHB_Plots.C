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
   gStyle->SetPadLeftMargin(0.12);
   gStyle->SetPadRightMargin(0.12);
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

void producePlot(const string& fFile, const string& fTitleExt, const string& fNameExt, const string& fExt) {

   TFile file(fFile.c_str());
   TDirectoryFile *subDir = (TDirectoryFile*)file.Get("hoStudy");
   TNtuple *ntuple = (TNtuple*)subDir->Get("n_Ntuple"); 
   Int_t nEntries = ntuple->GetEntries();

   Float_t hadEnergyInHB, hadEnergyInHO;
   // ntuple is of the form "GenJetE:GenJetEta:GenJetPhi:CaloJetE:CaloJetEta:CaloJetPhi:CaloJetWithHOE:CaloJetWithHOEta:CaloJetWithHOPhi:HadEnergyInHB:HadEnergyInHO"
   ntuple->SetBranchAddress("HadEnergyInHB",&hadEnergyInHB);
   ntuple->SetBranchAddress("HadEnergyInHO",&hadEnergyInHO);

   if ( fTitleExt.find("0.1") != string::npos ) {
      TH2F *h_EHO_EHB = new TH2F("h_EHO_EHB",";hadEnergyInHB [GeV];hadEnergyInHO [GeV]",100,500.,7800.,100,0.,600.);
   }
   else if ( fTitleExt.find("0.5") != string::npos ) {
      TH2F *h_EHO_EHB = new TH2F("h_EHO_EHB",";hadEnergyInHB [GeV];hadEnergyInHO [GeV]",100,500.,7800.,100,0.,600.);
   }
   else {
      TH2F *h_EHO_EHB = new TH2F("h_EHO_EHB",";hadEnergyInHB [GeV];hadEnergyInHO [GeV]",100,500.,7800.,100,0.,600.);
   }

   for (Int_t ent = 0; ent < nEntries; ent++) {
      ntuple->GetEntry(ent);

      h_EHO_EHB->Fill( hadEnergyInHB, hadEnergyInHO );
   }

//    TCanvas *c = new TCanvas("c","",1120,800);
   TCanvas *c = new TCanvas("c","",800,750);
   c->cd();
   
   h_EHO_EHB->SetTitle(fTitleExt.c_str());
   h_EHO_EHB->SetTitleOffset(1.5,"Y");
   h_EHO_EHB->Draw("colz");
   
   string name = h_EHO_EHB->GetName();
   string fileName = name + "_" + fNameExt + "." + fExt;
   
   c->SaveAs(fileName.c_str());
   
   delete c;
}

void makePlots() {
   // batch mode
   gROOT->SetBatch(kTRUE);
   // set ROOT style
   style();
   gROOT->ForceStyle(); 
   //********************************************
   // root files
   //********************************************
   string hostudy_eta01 = "root_files/hoStudy_corr_eta0.1.root";
   string hostudy_eta05 = "root_files/hoStudy_corr_eta0.5.root";
   string hostudy_eta10 = "root_files/hoStudy_corr_eta1.0.root";
   //********************************************
   // make plots
   //********************************************
   producePlot(hostudy_eta01,"#eta=0.1","corr_eta0.1","eps");
   producePlot(hostudy_eta05,"#eta=0.5","corr_eta0.5","eps");
   producePlot(hostudy_eta10,"#eta=1.0","corr_eta1.0","eps");
}