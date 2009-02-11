#include "TCanvas.h"
#include "TH1D.h"
#include "TH2F.h"
#include "TF1.h"
#include "TGraphErrors.h"
#include "TLegend.h"
#include "TFile.h"
#include "TStyle.h"
#include "TLatex.h"
#include "TSpectrum.h"
#include <fstream>
#include <string>


void style() {

   gStyle->Reset("Default");
   gStyle->SetCanvasColor(0);
   gStyle->SetPadColor(0);
   gStyle->SetTitleFillColor(10);
   gStyle->SetCanvasBorderMode(0);
   gStyle->SetStatColor(0);
   gStyle->SetPadBorderMode(0);
   gStyle->SetPadTickX(1);  // To get tick marks on the opposite side of the frame
   gStyle->SetPadTickY(1);
   gStyle->SetFrameBorderMode(0);
   gStyle->SetPalette(1);
   
   //gStyle->SetOptStat(kFALSE);
   gStyle->SetOptStat(111110);
   gStyle->SetOptFit(1);
//    gStyle->SetStatFont(42);
//    gStyle->SetTitleFont(42);
//    gStyle->SetTitleFont(42, "XYZ");
//    gStyle->SetLabelFont(42, "XYZ");
}

void fitPlot(const string& fFile, const Int_t fEn, const string& fTitleExt, const string& fNameExt) {
   
   TH2F *h[2];

   TFile file(fFile.c_str());
   TDirectoryFile *subDir = (TDirectoryFile*)file.Get("hoStudy");
   h[0] = (TH2F*)subDir->Get("h_ETRatio_ET"); 
   h[1] = (TH2F*)subDir->Get("h_ETRatioWithHO_ET");
   
   TCanvas *c = new TCanvas("c","",1120,800);
   c->cd();
   
   Int_t xlow[8] = {41,91,291,491,991,1991,3991,6991};
   Int_t xhigh[8] = {60,110,310,510,1010,2010,4010,7010};
   TH1D *hist;
   TF1 *fit;
   
   for (Int_t i=0; i<2; i++) {
      hist = (TH1D*)h[i]->ProjectionY("_py",xlow[fEn],xhigh[fEn])->Clone();
      hist->GetYaxis()->SetTitle("# of entries");
      
      string name = hist->GetName();
      string fileName = name + "_" + fNameExt;

      string title = hist->GetTitle();
      title = title + "" + fTitleExt;
      hist->SetTitle(title.c_str());

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
//       do {
//          hist->Fit("gaus","","",xmin,xmax);
//          fit = hist->GetFunction("gaus");
//          epsilon = fabs((mean-(fit->GetParameter(1)))/mean);
//          mean = fit->GetParameter(1);
//          mean_e = fit->GetParError(1);
//          sigma = fit->GetParameter(2);
//          sigma_e = fit->GetParError(2);
//          if ( counter == 0 ) {
//             cout<<">> 1st mean="<<mean<<" 1st mean error="<<mean_e<<endl;
//             cout<<">> 1st sigma="<<sigma<<" 1st sigma error="<<sigma_e<<endl;
//          }
//          xmin = mean - 2.*sigma;
//          xmax = mean + 2.*sigma;
//          counter++;
//       } while ( epsilon > 0.001 && counter < 11 );
      cout<<">> Number of iterations="<<counter<<endl;
      cout<<">> epsilon="<<epsilon<<endl;
      cout<<">> Final mean="<<mean<<" Final mean error="<<mean_e<<endl;
      cout<<">> Final sigma="<<sigma<<" Final sigma error="<<sigma_e<<endl;
      hist->Draw();

      if ( fileName.find("WithHO") != string::npos ) {
         TLatex l;
         l.SetTextAlign(12);
         l.SetTextSize(0.05);
         l.SetTextFont(42);
//          l.SetTextColor(kRed);
         l.SetNDC();
         l.DrawLatex(0.15,0.85,"with HO");
      }

      c->SaveAs((fileName + ".png").c_str());

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

   // set ROOT style
   style();
   //********************************************
   // root files
   //********************************************
   string hostudy_eta01 = "root_files/hoStudy_eta0.1.root";
   string hostudy_eta05 = "root_files/hoStudy_eta0.5.root";
   string hostudy_eta10 = "root_files/hoStudy_eta1.0.root";
   //********************************************
   // make plots
   //********************************************
   fitPlot(hostudy_eta01,0,"E_{T}^{gen}=50 GeV, #eta=0.1","eta0.1_ET50");
   fitPlot(hostudy_eta01,1,"E_{T}^{gen}=100 GeV, #eta=0.1","eta0.1_ET100");
   fitPlot(hostudy_eta01,2,"E_{T}^{gen}=300 GeV, #eta=0.1","eta0.1_ET300");
   fitPlot(hostudy_eta01,3,"E_{T}^{gen}=500 GeV, #eta=0.1","eta0.1_ET500");
   fitPlot(hostudy_eta01,4,"E_{T}^{gen}=1000 GeV, #eta=0.1","eta0.1_ET1000");
   fitPlot(hostudy_eta01,5,"E_{T}^{gen}=2000 GeV, #eta=0.1","eta0.1_ET2000");
   fitPlot(hostudy_eta01,6,"E_{T}^{gen}=4000 GeV, #eta=0.1","eta0.1_ET4000");
   fitPlot(hostudy_eta01,7,"E_{T}^{gen}=7000 GeV, #eta=0.1","eta0.1_ET7000");
   
   fitPlot(hostudy_eta05,0,"E_{T}^{gen}=50 GeV, #eta=0.5","eta0.5_ET50");
   fitPlot(hostudy_eta05,1,"E_{T}^{gen}=100 GeV, #eta=0.5","eta0.5_ET100");
   fitPlot(hostudy_eta05,2,"E_{T}^{gen}=300 GeV, #eta=0.5","eta0.5_ET300");
   fitPlot(hostudy_eta05,3,"E_{T}^{gen}=500 GeV, #eta=0.5","eta0.5_ET500");
   fitPlot(hostudy_eta05,4,"E_{T}^{gen}=1000 GeV, #eta=0.5","eta0.5_ET1000");
   fitPlot(hostudy_eta05,5,"E_{T}^{gen}=2000 GeV, #eta=0.5","eta0.5_ET2000");
   fitPlot(hostudy_eta05,6,"E_{T}^{gen}=4000 GeV, #eta=0.5","eta0.5_ET4000");
   fitPlot(hostudy_eta05,7,"E_{T}^{gen}=7000 GeV, #eta=0.5","eta0.5_ET7000");
   
   fitPlot(hostudy_eta10,0,"E_{T}^{gen}=50 GeV, #eta=1.0","eta1.0_ET50");
   fitPlot(hostudy_eta10,1,"E_{T}^{gen}=100 GeV, #eta=1.0","eta1.0_ET100");
   fitPlot(hostudy_eta10,2,"E_{T}^{gen}=300 GeV, #eta=1.0","eta1.0_ET300");
   fitPlot(hostudy_eta10,3,"E_{T}^{gen}=500 GeV, #eta=1.0","eta1.0_ET500");
   fitPlot(hostudy_eta10,4,"E_{T}^{gen}=1000 GeV, #eta=1.0","eta1.0_ET1000");
   fitPlot(hostudy_eta10,5,"E_{T}^{gen}=2000 GeV, #eta=1.0","eta1.0_ET2000");
   fitPlot(hostudy_eta10,6,"E_{T}^{gen}=4000 GeV, #eta=1.0","eta1.0_ET4000");
   fitPlot(hostudy_eta10,7,"E_{T}^{gen}=7000 GeV, #eta=1.0","eta1.0_ET7000");

}
