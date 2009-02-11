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
#include <vector>


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
   gStyle->SetPadLeftMargin(0.14);
//    gStyle->SetPadRightMargin(0.05);
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
//    gStyle->SetStatX(1.);
//    gStyle->SetStatY(1.);
//    gStyle->SetStatW(0.2);
   //gStyle->SetStatH(0.15);
}

void resolutionPlots(const string& fFile, const vector<Double_t>& fWeights, const string& fTitleExt, const string& fNameExt, const string& fExt) {

   // Number of HO weight points
   Int_t nWeights = fWeights.size();

   TFile file(fFile.c_str());
   TDirectoryFile *subDir = (TDirectoryFile*)file.Get("hoStudy");
   TNtuple *ntuple = (TNtuple*)subDir->Get("n_Ntuple"); 
   Int_t nEntries = ntuple->GetEntries();

   Float_t genJetE, genJetEta, caloJetWithHOE, caloJetWithHOEta, hadEnergyInHO;
   // ntuple is of the form "GenJetE:GenJetEta:GenJetPhi:CaloJetE:CaloJetEta:CaloJetPhi:CaloJetWithHOE:CaloJetWithHOEta:CaloJetWithHOPhi:HadEnergyInHB:HadEnergyInHO"
   ntuple->SetBranchAddress("GenJetE",&genJetE);
   ntuple->SetBranchAddress("GenJetEta",&genJetEta);
   ntuple->SetBranchAddress("CaloJetWithHOE",&caloJetWithHOE);
   ntuple->SetBranchAddress("CaloJetWithHOEta",&caloJetWithHOEta);
   ntuple->SetBranchAddress("HadEnergyInHO",&hadEnergyInHO);

//    TCanvas *c = new TCanvas("c","",1120,800);
   TCanvas *c = new TCanvas("c","",800,800);
   c->cd();
   
   TH2F *h_ETRatioWithHO_ET[nWeights];

   for (Int_t wght = 0; wght < nWeights; wght++) {
      Double_t weight = fWeights[wght];
      char histName[1024];
      sprintf (histName, "h_ETRatioWithHO_ET_%i", wght);
      h_ETRatioWithHO_ET[wght] = new TH2F(histName,";E^{gen}_{T} [GeV];E^{calo,HO}_{T}/E^{gen}_{T}",7200,0.,7200.,150,0.,1.5);

      for (Int_t ent = 0; ent < nEntries; ent++) {
         ntuple->GetEntry(ent);

         Double_t genJetET = genJetE/cosh(genJetEta);
         Double_t caloJetWithHOET = (caloJetWithHOE + (weight - 1.)*hadEnergyInHO)/cosh(caloJetWithHOEta);
         h_ETRatioWithHO_ET[wght]->Fill( genJetET, caloJetWithHOET/genJetET );
      }
//       h_ETRatioWithHO_ET[wght]->Draw();
//       string fileName = h_ETRatioWithHO_ET[wght]->GetName();
//       c->SaveAs( (fileName + ".png").c_str() );
   }

   Int_t xlow[8] = {41,91,291,491,991,1991,3991,6991};
   Int_t xhigh[8] = {60,110,310,510,1010,2010,4010,7010};
   vector<string> pTs;
   pTs.push_back("50");
   pTs.push_back("100");
   pTs.push_back("300");
   pTs.push_back("500");
   pTs.push_back("1000");
   pTs.push_back("2000");
   pTs.push_back("4000");
   pTs.push_back("7000");
   // x-axis values
   Double_t x[nWeights];
   Double_t x_e[nWeights];
   
   for (Int_t pT = 0; pT < 8; pT++) {
      // y-axis values
      Double_t y[nWeights];
      Double_t y_e[nWeights];

      for (Int_t wght = 0; wght < nWeights; wght++) {
         Double_t weight = fWeights[wght];
         x[wght] = weight;
         x_e[wght] = 0;
         
         TF1 *fit;
         
         TH1D *hist = (TH1D*)h_ETRatioWithHO_ET[wght]->ProjectionY("_py",xlow[pT],xhigh[pT])->Clone();
         Double_t mean = hist->GetMean();
         Double_t mean_e = 0;
         Double_t sigma = hist->GetRMS();
         Double_t sigma_e = 0;
         Double_t xmin = mean - 2.*sigma;
         Double_t xmax = mean + 2.*sigma;
         Double_t epsilon = 10;
         Int_t counter = 0;
         do {
            hist->Fit("gaus","","",xmin,xmax);
            fit = hist->GetFunction("gaus");
            epsilon = fabs((mean-(fit->GetParameter(1)))/mean);
            mean = fit->GetParameter(1);
            mean_e = fit->GetParError(1);
            sigma = fit->GetParameter(2);
            sigma_e = fit->GetParError(2);
            xmin = mean - 2.*sigma;
            xmax = mean + 2.*sigma;
            counter++;
         } while ( epsilon > 0.001 && counter < 12 );
         y[wght] = sigma/mean;
         y_e[wght] = sqrt( pow(sigma_e/mean,2) + pow((sigma*mean_e)/pow(mean,2),2) );
      }
      string title = "p_{T}=" + pTs[pT] + " GeV/c, " + fTitleExt + ";hadEnergyInHO weight factor;#sigma(E^{calo}_{T}/E^{gen}_{T})/<E^{calo}_{T}/E^{gen}_{T}>";
   
//       Double_t xRange = x[nWeights-1]-x[0];
      Double_t xMin = x[0] - 1.;
      Double_t xMax = x[nWeights-1] + 1.;
      
//       Double_t y_Min_El = *min_element(y,y+nWeights);
//       Double_t y_Max_El = *max_element(y,y+nWeights);
//       Double_t yRange = y_Max_El - y_Min_El;
//       Double_t yAvg = (y_Max_El + y_Min_El)/2;
//       Double_t yMin = yAvg - 2*yRange;
//       Double_t yMax = yAvg + 2*yRange;
      
      TH2F *h_bg = new TH2F("ET_res_vs_HO_wght",title.c_str(), 100, xMin, xMax, 25, 0., 0.25);
      h_bg->SetStats(kFALSE);
//       h_bg->SetTitleOffset(1.,"X");
      h_bg->SetTitleOffset(1.6,"Y");
      h_bg->Draw();
      
      TGraphErrors *g = new TGraphErrors(nWeights, x, y, x_e, y_e);
      g->SetLineColor(kBlue+1);
      g->SetLineWidth(1);
      //g->SetLineStyle(7);
      g->SetMarkerSize(.5);
      g->SetMarkerStyle(4);
      g->SetMarkerColor(kGreen+2);
      g->Draw("PL");

      string fileName = h_bg->GetName();
      fileName = fileName + "_" + fNameExt + "_pT" + pTs[pT];
      
      c->SaveAs( (fileName + "." + fExt).c_str() );

      delete g;
      delete h_bg;
   }
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
   string hostudy_eta01 = "hoStudy_corr_eta0.1.root";
   string hostudy_eta05 = "hoStudy_corr_eta0.5.root";
   string hostudy_eta10 = "hoStudy_corr_eta1.0.root";

   vector<Double_t> HOWeights;
//    HOWeights.push_back(-48.);
//    HOWeights.push_back(-18.);
//    HOWeights.push_back(-13.);
//    HOWeights.push_back(-6.);
//    HOWeights.push_back(-5.);
   HOWeights.push_back(-4.);
   HOWeights.push_back(-3.);
   HOWeights.push_back(-2.);
   HOWeights.push_back(-1.);
   HOWeights.push_back(0.);
//    HOWeights.push_back(0.1);
//    HOWeights.push_back(0.2);
//    HOWeights.push_back(0.3);
//    HOWeights.push_back(0.4);
   HOWeights.push_back(0.5);
//    HOWeights.push_back(0.6);
//    HOWeights.push_back(0.7);
//    HOWeights.push_back(0.8);
//    HOWeights.push_back(0.9);
   HOWeights.push_back(1.0);
//    HOWeights.push_back(1.1);
//    HOWeights.push_back(1.2);
//    HOWeights.push_back(1.3);
//    HOWeights.push_back(1.4);
   HOWeights.push_back(1.5);
//    HOWeights.push_back(1.6);
//    HOWeights.push_back(1.7);
//    HOWeights.push_back(1.8);
//    HOWeights.push_back(1.9);
   HOWeights.push_back(2.0);
   HOWeights.push_back(3.0);
   HOWeights.push_back(4.0);
   HOWeights.push_back(5.0);
   HOWeights.push_back(6.0);
//    HOWeights.push_back(7.0);
//    HOWeights.push_back(8.0);
//    HOWeights.push_back(15.0);
//    HOWeights.push_back(20.0);
//    HOWeights.push_back(50.0);
   //********************************************
   // make plots
   //********************************************   
   resolutionPlots(hostudy_eta01,HOWeights,"#eta=0.1","eta0.1","eps");
   resolutionPlots(hostudy_eta05,HOWeights,"#eta=0.5","eta0.5","eps");
   resolutionPlots(hostudy_eta10,HOWeights,"#eta=1.0","eta1.0","eps");
}
