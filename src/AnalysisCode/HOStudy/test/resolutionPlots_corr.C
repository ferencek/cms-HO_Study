#include "TCanvas.h"
#include "TH1D.h"
#include "TH2F.h"
#include "TF1.h"
#include "TGraphErrors.h"
#include "TLegend.h"
#include "TLatex.h"
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
//    gStyle->SetPadLeftMargin(0.13);
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

void resolutionPlot(const string& fFile, const string& fTitle, const string& fNameExt, const string& fExt) {

   TH2F *h[2];

   TFile file(fFile.c_str());
   TDirectoryFile *subDir = (TDirectoryFile*)file.Get("hoStudy");
   h[0] = (TH2F*)subDir->Get("h_ETRatio_ET"); 
   h[1] = (TH2F*)subDir->Get("h_ETRatioWithHO_ET");
   
   Double_t x_e[8] = {0.};
   Double_t x[8] = {50.,100.,300.,500.,1000.,2000.,4000.,7000.};

   Int_t xlow[8] = {41,91,291,491,991,1991,3991,6991};
   Int_t xhigh[8] = {60,110,310,510,1010,2010,4010,7010};
   TH1D *hist;
   TF1 *fit;
   
   Double_t y[8] = {0.};
   Double_t y_e[8] = {0.};
   Double_t y_P[8] = {0.};
   Double_t y_P_e[8] = {0.};
   for ( Int_t i = 0; i < 8; i++ ) {
      hist = (TH1D*)h[0]->ProjectionY("_py",xlow[i],xhigh[i])->Clone();
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
      y[i] = sigma/mean;
      y_e[i] = sqrt( pow(sigma_e/mean,2) + pow((sigma*mean_e)/pow(mean,2),2) );

      Double_t totEntries = hist->GetEntries();
      Int_t lowerBin = hist->GetXaxis()->FindBin(mean-3*sigma);
//       Int_t upperBin = hist->GetXaxis()->FindBin(mean+3*sigma);
      Double_t leftSideEntries = hist->Integral(0,lowerBin-1);
      y_P[i] = (100.*leftSideEntries)/totEntries;
      y_P_e[i] = 100.*sqrt( pow(sqrt(leftSideEntries)/totEntries,2) + pow((leftSideEntries*sqrt(totEntries))/pow(totEntries,2),2) );
   }
   
   Double_t y_HO[8] = {0.};
   Double_t y_HO_e[8] = {0.};
   Double_t y_P_HO[8] = {0.};
   Double_t y_P_HO_e[8] = {0.};
   for ( Int_t i = 0; i < 8; i++ ) {
      hist = (TH1D*)h[1]->ProjectionY("_py",xlow[i],xhigh[i])->Clone();
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
      y_HO[i] = sigma/mean;
      y_HO_e[i] = sqrt( pow(sigma_e/mean,2) + pow((sigma*mean_e)/pow(mean,2),2) );

      Double_t totEntries = hist->GetEntries();
      Int_t lowerBin = hist->GetXaxis()->FindBin(mean-3*sigma);
//       Int_t upperBin = hist->GetXaxis()->FindBin(mean+3*sigma);
      Double_t leftSideEntries = hist->Integral(0,lowerBin-1);
      y_P_HO[i] = (100.*leftSideEntries)/totEntries;
      y_P_HO_e[i] = 100.*sqrt( pow(sqrt(leftSideEntries)/totEntries,2) + pow((leftSideEntries*sqrt(totEntries))/pow(totEntries,2),2) );
   }
   
   gStyle->SetPadLeftMargin(0.12);

   TCanvas *c = new TCanvas("c","",1120,800);
//    TCanvas *c = new TCanvas("c","",800,800);
   c->cd();
   
   string title = fTitle + ";E^{gen}_{T} [GeV];#sigma(E^{calo}_{T}/E^{gen}_{T})/<E^{calo}_{T}/E^{gen}_{T}>";
   
   TH2F *h_bg = new TH2F("ET_resolution",title.c_str(), 7200, 0., 7200., 22, 0.,0.22);
   h_bg->SetStats(kFALSE);
//    h_bg->SetTitleOffset(1.,"X");
   h_bg->SetTitleOffset(1.3,"Y");
   h_bg->Draw();
   
   TGraphErrors *g = new TGraphErrors(8, x, y, x_e, y_e);
   g->SetLineColor(kRed+1);
   g->SetLineWidth(2);
   //g->SetLineStyle(7);
   g->SetMarkerSize(.5);
   g->SetMarkerStyle(26);
   g->SetMarkerColor(kRed+1);
   g->Draw("PL");
   
   TGraphErrors *g_HO = new TGraphErrors(8, x, y_HO, x_e, y_HO_e);
   g_HO->SetLineColor(kGreen+2);
   g_HO->SetLineWidth(2);
   g_HO->SetLineStyle(7);
   g_HO->SetMarkerSize(.5);
   g_HO->SetMarkerStyle(4);
   g_HO->SetMarkerColor(kGreen+2);
   g_HO->Draw("PL");
   
   TLegend *legend = new TLegend(.65,.65,.85,.8);
   legend->SetBorderSize(1);
   legend->SetFillColor(0);
   //legend->SetFillStyle(0);
   legend->SetTextFont(42);
   legend->AddEntry(g,"without HO","lp");
   legend->AddEntry(g_HO,"with HO","lp");
   legend->Draw();

   string fileName = h_bg->GetName();
   fileName = fileName + "_" + fNameExt;

   c->SaveAs((fileName + "." + fExt).c_str());
   delete c;

   gStyle->SetPadLeftMargin(0.1);

   TCanvas *c2 = new TCanvas("c2","",800,800);
   c2->cd();

   string title_P = fTitle + ";E^{gen}_{T} [GeV];% of events more than 3#sigma below the mean";
   
   TH2F *h_bg_P = new TH2F("P3sigma",title_P.c_str(), 7200, 0., 7200., 85, 0.,8.5);
   h_bg_P->SetStats(kFALSE);
//    h_bg_P->SetTitleOffset(1.,"X");
//    h_bg_P->SetTitleOffset(1.,"Y");
   h_bg_P->Draw();
   
   TGraphErrors *g_P = new TGraphErrors(8, x, y_P, x_e, y_P_e);
   g_P->SetLineColor(kRed+1);
   g_P->SetLineWidth(2);
   //g_P->SetLineStyle(7);
   g_P->SetMarkerSize(.8);
   g_P->SetMarkerStyle(26);
   g_P->SetMarkerColor(kRed+1);
   g_P->Draw("PL");
   
   TGraphErrors *g_P_HO = new TGraphErrors(8, x, y_P_HO, x_e, y_P_HO_e);
   g_P_HO->SetLineColor(kGreen+2);
   g_P_HO->SetLineWidth(2);
   g_P_HO->SetLineStyle(7);
   g_P_HO->SetMarkerSize(.8);
   g_P_HO->SetMarkerStyle(4);
   g_P_HO->SetMarkerColor(kGreen+2);
   g_P_HO->Draw("PL");
   
   TLegend *legend2 = new TLegend(.15,.65,.35,.8);
   legend2->SetBorderSize(1);
   legend2->SetFillColor(0);
   //legend2->SetFillStyle(0);
   legend2->SetTextFont(42);
   legend2->AddEntry(g_P,"without HO","lp");
   legend2->AddEntry(g_P_HO,"with HO","lp");
   legend2->Draw();

   fileName = h_bg_P->GetName();
   fileName = fileName + "_" + fNameExt;

   c2->SaveAs((fileName + "." + fExt).c_str());

   delete legend2;
   delete g_P;
   delete g_P_HO;
   delete h_bg_P;
   delete legend;
   delete g;
   delete g_HO;
   delete h_bg;
   delete c2;
   delete fit;
   delete hist;
}

void fitPlot(const string& fFile, const Int_t fEn, const string& fTitleExt, const string& fNameExt, const string& fExt) {
   
   TH2F *h[2];

   TFile file(fFile.c_str());
   TDirectoryFile *subDir = (TDirectoryFile*)file.Get("hoStudy");
   h[0] = (TH2F*)subDir->Get("h_ETRatio_ET"); 
   h[1] = (TH2F*)subDir->Get("h_ETRatioWithHO_ET");
   
   gStyle->SetPadLeftMargin(0.12);

//    TCanvas *c = new TCanvas("c","",1120,800);
   TCanvas *c = new TCanvas("c","",800,800);
   c->cd();
   
   Int_t xlow[8] = {41,91,291,491,991,1991,3991,6991};
   Int_t xhigh[8] = {60,110,310,510,1010,2010,4010,7010};
   TH1D *hist;
   TF1 *fit;
   
   for (Int_t i=0; i<2; i++) {
      hist = (TH1D*)h[i]->ProjectionY("_py",xlow[fEn],xhigh[fEn])->Clone();
      hist->GetYaxis()->SetTitle("Entries/0.01");

      string name = hist->GetName();
      string fileName = name + "_" + fNameExt;

      string title = hist->GetTitle();
      title = title + "" + fTitleExt;
      hist->SetTitle(title.c_str());
      hist->SetTitleOffset(1.5,"Y");

      Double_t mean = hist->GetMean();
      cout<<">> Histogram mean="<<mean<<endl;
      Double_t mean_e = 0;
      Double_t sigma = hist->GetRMS();
      cout<<">> Histogram RMS="<<sigma<<endl;
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
         if ( counter == 0 ) {
            cout<<">> 1st mean="<<mean<<" 1st mean error="<<mean_e<<endl;
            cout<<">> 1st sigma="<<sigma<<" 1st sigma error="<<sigma_e<<endl;
         }
         xmin = mean - 2.*sigma;
         xmax = mean + 2.*sigma;
         counter++;
      } while ( epsilon > 0.001 && counter < 12 );
      cout<<">> Number of iterations="<<counter<<endl;
      cout<<">> epsilon="<<epsilon<<endl;
      cout<<">> Final mean="<<mean<<" Final mean error="<<mean_e<<endl;
      cout<<">> Final sigma="<<sigma<<" Final sigma error="<<sigma_e<<endl;
      hist->GetYaxis()->SetRangeUser(1.,10000.);
      hist->Draw();

      if ( fileName.find("WithHO") != string::npos ) {
         TLatex l;
         l.SetTextAlign(12);
         l.SetTextSize(0.05);
         l.SetTextFont(42);
         l.SetTextColor(kGreen+2);
         l.SetNDC();
         l.DrawLatex(0.15,0.85,"with HO");
      }

      c->SetLogy();
      c->SaveAs((fileName + "." + fExt).c_str());

//       Int_t totEntries = hist->GetEntries();
//       Int_t lowerBin = hist->GetXaxis()->FindBin(mean-3*sigma);
//       Int_t upperBin = hist->GetXaxis()->FindBin(mean+3*sigma);
//       Int_t sideEntries = totEntries - hist->Integral(lowerBin,upperBin);
//       Double_t sidePercentage = (100.*sideEntries)/totEntries;
// 
//       ofstream textFile;
//       textFile.open((fileName + ".txt").c_str());
//       textFile << "*** " << fileName.c_str() << " ***" << endl;
//       textFile << "Total number of entries: " << totEntries << endl;
//       textFile << "Number of entries outside Mean+/-3*Sigma: " << sideEntries << " (" << sidePercentage << "%)" << endl;
//       textFile.close();
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
   string hostudy_eta01 = "root_files/hoStudy_corr_eta0.1.root";
   string hostudy_eta05 = "root_files/hoStudy_corr_eta0.5.root";
   string hostudy_eta10 = "root_files/hoStudy_corr_eta1.0.root";
   //********************************************
   // make plots
   //********************************************
//    fitPlot(hostudy_eta01,0,"p_{T}=50 GeV/c, #eta=0.1","fit_corr_eta0.1_pT50","eps");
//    fitPlot(hostudy_eta01,1,"p_{T}=100 GeV/c, #eta=0.1","fit_corr_eta0.1_pT100","eps");
//    fitPlot(hostudy_eta01,2,"p_{T}=300 GeV/c, #eta=0.1","fit_corr_eta0.1_pT300","eps");
//    fitPlot(hostudy_eta01,3,"p_{T}=500 GeV/c, #eta=0.1","fit_corr_eta0.1_pT500","eps");
//    fitPlot(hostudy_eta01,4,"p_{T}=1000 GeV/c, #eta=0.1","fit_corr_eta0.1_pT1000","eps");
//    fitPlot(hostudy_eta01,5,"p_{T}=2000 GeV/c, #eta=0.1","fit_corr_eta0.1_pT2000","eps");
//    fitPlot(hostudy_eta01,6,"p_{T}=4000 GeV/c, #eta=0.1","fit_corr_eta0.1_pT4000","eps");
//    fitPlot(hostudy_eta01,7,"p_{T}=7000 GeV/c, #eta=0.1","fit_corr_eta0.1_pT7000","eps");
//    
//    fitPlot(hostudy_eta05,0,"p_{T}=50 GeV/c, #eta=0.5","fit_corr_eta0.5_pT50","eps");
//    fitPlot(hostudy_eta05,1,"p_{T}=100 GeV/c, #eta=0.5","fit_corr_eta0.5_pT100","eps");
//    fitPlot(hostudy_eta05,2,"p_{T}=300 GeV/c, #eta=0.5","fit_corr_eta0.5_pT300","eps");
//    fitPlot(hostudy_eta05,3,"p_{T}=500 GeV/c, #eta=0.5","fit_corr_eta0.5_pT500","eps");
//    fitPlot(hostudy_eta05,4,"p_{T}=1000 GeV/c, #eta=0.5","fit_corr_eta0.5_pT1000","eps");
//    fitPlot(hostudy_eta05,5,"p_{T}=2000 GeV/c, #eta=0.5","fit_corr_eta0.5_pT2000","eps");
//    fitPlot(hostudy_eta05,6,"p_{T}=4000 GeV/c, #eta=0.5","fit_corr_eta0.5_pT4000","eps");
//    fitPlot(hostudy_eta05,7,"p_{T}=7000 GeV/c, #eta=0.5","fit_corr_eta0.5_pT7000","eps");
//    
//    fitPlot(hostudy_eta10,0,"p_{T}=50 GeV/c, #eta=1.0","fit_corr_eta1.0_pT50","eps");
//    fitPlot(hostudy_eta10,1,"p_{T}=100 GeV/c, #eta=1.0","fit_corr_eta1.0_pT100","eps");
//    fitPlot(hostudy_eta10,2,"p_{T}=300 GeV/c, #eta=1.0","fit_corr_eta1.0_pT300","eps");
//    fitPlot(hostudy_eta10,3,"p_{T}=500 GeV/c, #eta=1.0","fit_corr_eta1.0_pT500","eps");
//    fitPlot(hostudy_eta10,4,"p_{T}=1000 GeV/c, #eta=1.0","fit_corr_eta1.0_pT1000","eps");
//    fitPlot(hostudy_eta10,5,"p_{T}=2000 GeV/c, #eta=1.0","fit_corr_eta1.0_pT2000","eps");
//    fitPlot(hostudy_eta10,6,"p_{T}=4000 GeV/c, #eta=1.0","fit_corr_eta1.0_pT4000","eps");
//    fitPlot(hostudy_eta10,7,"p_{T}=7000 GeV/c, #eta=1.0","fit_corr_eta1.0_pT7000","eps");
   
   resolutionPlot(hostudy_eta01,"#eta=0.1","corr_eta0.1","eps");
   resolutionPlot(hostudy_eta05,"#eta=0.5","corr_eta0.5","eps");
   resolutionPlot(hostudy_eta10,"#eta=1.0","corr_eta1.0","eps");
}
