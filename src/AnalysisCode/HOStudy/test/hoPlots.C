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
   gStyle->SetOptStat(111110);
   //gStyle->SetOptStat(111111);
   //gStyle->SetOptStat(kFALSE);
   
   gStyle->SetPalette(1);
   //gStyle->SetTitleX(0.10);
   //gStyle->SetTitleY(0.95);
   //gStyle->SetTitleW(0.40);
   //gStyle->SetTitleH(0.05);
   //gStyle->SetOptFit(111);
   //gStyle->SetStatX(1.0);
   //gStyle->SetStatY(1.0);
   //gStyle->SetStatW(0.25);
   //gStyle->SetStatH(0.15);
}

void singlePlotProducer(TH1* fHist, const string& fTitleExt, const string& fNameExt, const string& fSwitch) {
   
   string name = fHist->GetName();
   string fileName = name + "_" + fNameExt + ".png";
   
   string title = fHist->GetTitle();
   title = title + " " + fTitleExt;
   fHist->SetTitle(title.c_str());
   
   TCanvas *c = new TCanvas("c","",1120,800);
   c->cd();
   
   fHist->SetLineWidth(2);
   fHist->Draw();
   
   if ( fSwitch.find("log") != string::npos ) c->SetLogy();
   c->SaveAs(fileName.c_str());

   delete c;
}

void multiPlotProducer(const string& fFile, const string& fTitleExt, const string& fNameExt) {
   
   TFile file(fFile.c_str());
   TDirectoryFile *subDir = (TDirectoryFile*)file.Get("hoStudy");
   
   TH1F *h[9];
   h[0] = (TH1F*)subDir->Get("h_GenJetEta"); 
   h[1] = (TH1F*)subDir->Get("h_GenJetPhi");
   h[2] = (TH1F*)subDir->Get("h_CaloJetEta"); 
   h[3] = (TH1F*)subDir->Get("h_CaloJetPhi");
   h[4] = (TH1F*)subDir->Get("h_CaloJetWithHOEta");
   h[5] = (TH1F*)subDir->Get("h_CaloJetWithHOPhi");
   h[6] = (TH1F*)subDir->Get("h_DeltaR");
   h[7] = (TH1F*)subDir->Get("h_DeltaRWithHO");
   h[8] = (TH1F*)subDir->Get("h_DeltaEHO");
   
   for (int i=0; i<9; i++) {
      
       singlePlotProducer(h[i],fTitleExt,fNameExt,"log");
   }
   
   TH2F *h2[3];
   h2[0] = (TH2F*)subDir->Get("h_ETRatio_ET"); 
   h2[1] = (TH2F*)subDir->Get("h_ETRatioWithHO_ET");
   h2[2] = (TH2F*)subDir->Get("h_DeltaE_EHO");
   
   for (int i=0; i<3; i++) {
      
       singlePlotProducer(h2[i],fTitleExt,fNameExt,"");
   }
   
   TCanvas *c = new TCanvas("c","",1120,800);
   c->cd();
   
   TH1D *pr[8];
   pr[0]=(TH1D*)h2[0]->ProjectionY("_py",41,60)->Clone();
   pr[0]->SetLineColor(kMagenta+2);
   pr[0]->SetLineWidth(2);
//    pr[0]->SetLineStyle(7);
   pr[1]=(TH1D*)h2[0]->ProjectionY("_py",91,110)->Clone();
   pr[1]->SetLineColor(kOrange+1);
   pr[1]->SetLineWidth(2);
//    pr[1]->SetLineStyle(7);
   pr[2]=(TH1D*)h2[0]->ProjectionY("_py",291,310)->Clone();
   pr[2]->SetLineColor(kBlue+1);
   pr[2]->SetLineWidth(2);
//    pr[2]->SetLineStyle(7);
   pr[3]=(TH1D*)h2[0]->ProjectionY("_py",491,510)->Clone();
   pr[3]->SetLineColor(kRed);
   pr[3]->SetLineWidth(2);
//    pr[3]->SetLineStyle(7);
   pr[4]=(TH1D*)h2[0]->ProjectionY("_py",991,1010)->Clone();
   pr[4]->SetLineColor(kGreen+2);
   pr[4]->SetLineWidth(2);
//    pr[4]->SetLineStyle(7);
   pr[5]=(TH1D*)h2[0]->ProjectionY("_py",1991,2010)->Clone();
   pr[5]->SetLineColor(kBlack);
   pr[5]->SetLineWidth(2);
//    pr[5]->SetLineStyle(7);
//    pr[6]=(TH1D*)h2[0]->ProjectionY("_py",3991,4010)->Clone();
//    pr[6]->SetLineColor(kBlue+2);
//    pr[6]->SetLineWidth(2);
// //    pr[6]->SetLineStyle(7);
//    pr[7]=(TH1D*)h2[0]->ProjectionY("_py",6991,7010)->Clone();
//    pr[7]->SetLineColor(1);
//    pr[7]->SetLineWidth(2);
//    pr[7]->SetLineStyle(7);
   
   string title = pr[0]->GetTitle();
   title = title + "" + fTitleExt;
   pr[0]->SetTitle(title.c_str());
   pr[0]->GetXaxis()->SetRangeUser(0.,1.25);
   pr[0]->GetYaxis()->SetRangeUser(0.,195.);
   
   pr[0]->Draw();
   pr[1]->Draw("same");
   pr[2]->Draw("same");
   pr[3]->Draw("same");
   pr[4]->Draw("same");
   pr[5]->Draw("same");
//    pr[6]->Draw("same");
//    pr[7]->Draw("same");
   
   TLegend *legend = new TLegend(.2,.6,.35,.85);
   legend->SetBorderSize(1);
   legend->SetFillColor(0);
   //legend->SetFillStyle(0);
   legend->SetTextFont(42);
   legend->AddEntry(pr[0],"p_{T}=50 GeV","l");
   legend->AddEntry(pr[1],"p_{T}=100 GeV","l");
   legend->AddEntry(pr[2],"p_{T}=300 GeV","l");
   legend->AddEntry(pr[3],"p_{T}=500 GeV","l");
   legend->AddEntry(pr[4],"p_{T}=1000 GeV","l");
   legend->AddEntry(pr[5],"p_{T}=2000 GeV","l");
//    legend->AddEntry(pr[6],"p_{T}=4000 GeV","l");
//    legend->AddEntry(pr[7],"p_{T}=7000 GeV","l");
   legend->Draw();
   
   string name = pr[0]->GetName();
   string fileName = name + "_" + fNameExt + ".png";
   
//    c->SaveAs(fileName.c_str());
   
   TH1D *pr_HO[8];
   pr_HO[0]=(TH1D*)h2[1]->ProjectionY("_py",41,60)->Clone();
   pr_HO[0]->SetLineColor(kMagenta+2);
   pr_HO[0]->SetLineWidth(2);
//    pr_HO[0]->SetLineStyle(7);
   pr_HO[1]=(TH1D*)h2[1]->ProjectionY("_py",91,110)->Clone();
   pr_HO[1]->SetLineColor(kOrange+1);
   pr_HO[1]->SetLineWidth(2);
//    pr_HO[1]->SetLineStyle(7);
   pr_HO[2]=(TH1D*)h2[1]->ProjectionY("_py",291,310)->Clone();
   pr_HO[2]->SetLineColor(kBlue+1);
   pr_HO[2]->SetLineWidth(2);
//    pr_HO[2]->SetLineStyle(7);
   pr_HO[3]=(TH1D*)h2[1]->ProjectionY("_py",491,510)->Clone();
   pr_HO[3]->SetLineColor(kRed);
   pr_HO[3]->SetLineWidth(2);
//    pr_HO[3]->SetLineStyle(7);
   pr_HO[4]=(TH1D*)h2[1]->ProjectionY("_py",991,1010)->Clone();
   pr_HO[4]->SetLineColor(kGreen+2);
   pr_HO[4]->SetLineWidth(2);
//    pr_HO[4]->SetLineStyle(7);
   pr_HO[5]=(TH1D*)h2[1]->ProjectionY("_py",1991,2010)->Clone();
   pr_HO[5]->SetLineColor(kBlack);
   pr_HO[5]->SetLineWidth(2);
//    pr_HO[5]->SetLineStyle(7);
//    pr_HO[6]=(TH1D*)h2[1]->ProjectionY("_py",3991,4010)->Clone();
//    pr_HO[6]->SetLineColor(kBlue+2);
//    pr_HO[6]->SetLineWidth(2);
// //    pr_HO[6]->SetLineStyle(7);
//    pr_HO[7]=(TH1D*)h2[1]->ProjectionY("_py",6991,7010)->Clone();
//    pr_HO[7]->SetLineColor(1);
//    pr_HO[7]->SetLineWidth(2);
//    pr_HO[7]->SetLineStyle(7);
   
   title = pr_HO[0]->GetTitle();
   title = title + "" + fTitleExt;
   pr_HO[0]->SetTitle(title.c_str());
   pr_HO[0]->GetXaxis()->SetRangeUser(0.,1.25);
   pr_HO[0]->GetYaxis()->SetRangeUser(0.,220.);
   
   pr_HO[0]->Draw();
   pr_HO[1]->Draw("same");
   pr_HO[2]->Draw("same");
   pr_HO[3]->Draw("same");
   pr_HO[4]->Draw("same");
   pr_HO[5]->Draw("same");
//    pr_HO[6]->Draw("same");
//    pr_HO[7]->Draw("same");
   
//    TLegend *legend = new TLegend(.2,.55,.35,.85);
//    legend->SetBorderSize(1);
//    legend->SetFillColor(0);
//    //legend->SetFillStyle(0);
//    legend->SetTextFont(42);
//    legend->AddEntry(pr_HO[0],"p_{T}=50 GeV","l");
//    legend->AddEntry(pr_HO[1],"p_{T}=100 GeV","l");
//    legend->AddEntry(pr_HO[2],"p_{T}=300 GeV","l");
//    legend->AddEntry(pr_HO[3],"p_{T}=500 GeV","l");
//    legend->AddEntry(pr_HO[4],"p_{T}=1000 GeV","l");
//    legend->AddEntry(pr_HO[5],"p_{T}=2000 GeV","l");
//    legend->AddEntry(pr_HO[6],"p_{T}=4000 GeV","l");
//    legend->AddEntry(pr_HO[7],"p_{T}=7000 GeV","l");
   legend->Draw();
   
   name = pr_HO[0]->GetName();
   fileName = name + "_" + fNameExt + ".png";
   
//    c->SaveAs(fileName.c_str());
   
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
   multiPlotProducer(hostudy_eta01,"(#eta=0.1)","eta0.1");
   multiPlotProducer(hostudy_eta05,"(#eta=0.5)","eta0.5");
   multiPlotProducer(hostudy_eta10,"(#eta=1.0)","eta1.0");
}