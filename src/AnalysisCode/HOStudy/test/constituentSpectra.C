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
//    gStyle->SetPadRightMargin(0.05);
   gStyle->SetPadTickX(1);  // To get tick marks on the opposite side of the frame
   gStyle->SetPadTickY(1);
   gStyle->SetFrameBorderMode(0);
//    gStyle->SetStatFont(42);
//    gStyle->SetStatFontSize(0.05);
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
   gStyle->SetStatW(0.3);
   //gStyle->SetStatH(0.15);
}

void plotProducer(const string& fFile, const string& fTitleExt, const string& fNameExt, const string& fExt) {
   
   TFile file(fFile.c_str());
   TDirectoryFile *subDir = (TDirectoryFile*)file.Get("hoStudy");
   
   TH2F *h2;
   h2 = (TH2F*)subDir->Get("h_ConstituentpT_ET"); 
   
//    gStyle->SetPadLeftMargin(0.09);
   gStyle->SetOptStat(kFALSE);

//    TCanvas *c = new TCanvas("c","",1120,800);
   TCanvas *c = new TCanvas("c","",800,800);
   c->cd();
   
   TH1D *pr[8];
   pr[0]=(TH1D*)h2->ProjectionY("_py",41,60)->Clone();
   pr[0]->SetLineColor(kMagenta+2);
   pr[0]->SetLineWidth(2);
//    pr[0]->SetLineStyle(7);
   pr[1]=(TH1D*)h2->ProjectionY("_py",91,110)->Clone();
   pr[1]->SetLineColor(kYellow);
   pr[1]->SetLineWidth(2);
//    pr[1]->SetLineStyle(7);
   pr[2]=(TH1D*)h2->ProjectionY("_py",291,310)->Clone();
   pr[2]->SetLineColor(kBlue+1);
   pr[2]->SetLineWidth(2);
//    pr[2]->SetLineStyle(7);
   pr[3]=(TH1D*)h2->ProjectionY("_py",491,510)->Clone();
   pr[3]->SetLineColor(kRed);
   pr[3]->SetLineWidth(2);
//    pr[3]->SetLineStyle(7);
   pr[4]=(TH1D*)h2->ProjectionY("_py",991,1010)->Clone();
   pr[4]->SetLineColor(kGreen+2);
   pr[4]->SetLineWidth(2);
//    pr[4]->SetLineStyle(7);
   pr[5]=(TH1D*)h2->ProjectionY("_py",1991,2010)->Clone();
   pr[5]->SetLineColor(kBlack);
   pr[5]->SetLineWidth(2);
//    pr[5]->SetLineStyle(7);
   pr[6]=(TH1D*)h2->ProjectionY("_py",3991,4010)->Clone();
   pr[6]->SetLineColor(kOrange-3);
   pr[6]->SetLineWidth(2);
//    pr[6]->SetLineStyle(7);
   pr[7]=(TH1D*)h2->ProjectionY("_py",6991,7010)->Clone();
   pr[7]->SetLineColor(kCyan);
   pr[7]->SetLineWidth(2);
//    pr[7]->SetLineStyle(7);
   
   pr[7]->SetTitle(fTitleExt.c_str());
   pr[7]->GetYaxis()->SetTitle("Entries/(20 GeV/c)");
//    pr[7]->SetTitleOffset(1.,"X");
   pr[7]->SetTitleOffset(1.3,"Y");
   
   pr[7]->Rebin(20)->Draw();
   pr[0]->Rebin(20)->Draw("same");
   pr[1]->Rebin(20)->Draw("same");
   pr[2]->Rebin(20)->Draw("same");
   pr[3]->Rebin(20)->Draw("same");
   pr[4]->Rebin(20)->Draw("same");
   pr[5]->Rebin(20)->Draw("same");
   pr[6]->Rebin(20)->Draw("same");
   
   TLegend *legend = new TLegend(.6,.5,.85,.85);
   legend->SetBorderSize(1);
   legend->SetFillColor(0);
   //legend->SetFillStyle(0);
   legend->SetTextFont(42);
   legend->AddEntry(pr[0],"p_{T}=50 GeV/c","l");
   legend->AddEntry(pr[1],"p_{T}=100 GeV/c","l");
   legend->AddEntry(pr[2],"p_{T}=300 GeV/c","l");
   legend->AddEntry(pr[3],"p_{T}=500 GeV/c","l");
   legend->AddEntry(pr[4],"p_{T}=1000 GeV/c","l");
   legend->AddEntry(pr[5],"p_{T}=2000 GeV/c","l");
   legend->AddEntry(pr[6],"p_{T}=4000 GeV/c","l");
   legend->AddEntry(pr[7],"p_{T}=7000 GeV/c","l");
   legend->Draw();
   
   string name = pr[0]->GetName();
   string fileName = name + "_" + fNameExt + "." + fExt;

   c->SetLogy();
   c->SaveAs(fileName.c_str());

   delete c;
}

void plotProducerZoomed(const string& fFile, const string& fTitleExt, const string& fNameExt, const string& fExt) {
   
   TFile file(fFile.c_str());
   TDirectoryFile *subDir = (TDirectoryFile*)file.Get("hoStudy");
   
   TH2F *h2;
   h2 = (TH2F*)subDir->Get("h_ConstituentpT_ET"); 
   
//    gStyle->SetPadLeftMargin(0.09);
   gStyle->SetOptStat(kFALSE);

//    TCanvas *c = new TCanvas("c","",1120,800);
   TCanvas *c = new TCanvas("c","",800,800);
   c->cd();
   
   TH1D *pr[8];
   pr[0]=(TH1D*)h2->ProjectionY("_py",41,60)->Clone();
   pr[0]->SetLineColor(kMagenta+2);
   pr[0]->SetLineWidth(2);
//    pr[0]->SetLineStyle(7);
   pr[1]=(TH1D*)h2->ProjectionY("_py",91,110)->Clone();
   pr[1]->SetLineColor(kYellow);
   pr[1]->SetLineWidth(2);
//    pr[1]->SetLineStyle(7);
   pr[2]=(TH1D*)h2->ProjectionY("_py",291,310)->Clone();
   pr[2]->SetLineColor(kBlue+1);
   pr[2]->SetLineWidth(2);
//    pr[2]->SetLineStyle(7);
   pr[3]=(TH1D*)h2->ProjectionY("_py",491,510)->Clone();
   pr[3]->SetLineColor(kRed);
   pr[3]->SetLineWidth(2);
//    pr[3]->SetLineStyle(7);
   pr[4]=(TH1D*)h2->ProjectionY("_py",991,1010)->Clone();
   pr[4]->SetLineColor(kGreen+2);
   pr[4]->SetLineWidth(2);
//    pr[4]->SetLineStyle(7);
   pr[5]=(TH1D*)h2->ProjectionY("_py",1991,2010)->Clone();
   pr[5]->SetLineColor(kBlack);
   pr[5]->SetLineWidth(2);
//    pr[5]->SetLineStyle(7);
   pr[6]=(TH1D*)h2->ProjectionY("_py",3991,4010)->Clone();
   pr[6]->SetLineColor(kOrange-3);
   pr[6]->SetLineWidth(2);
//    pr[6]->SetLineStyle(7);
   pr[7]=(TH1D*)h2->ProjectionY("_py",6991,7010)->Clone();
   pr[7]->SetLineColor(kCyan);
   pr[7]->SetLineWidth(2);
//    pr[7]->SetLineStyle(7);
   
   pr[7]->SetTitle(fTitleExt.c_str());
   pr[7]->GetYaxis()->SetTitle("Entries/(4 GeV/c)");
//    pr[7]->SetTitleOffset(1.,"X");
   pr[7]->SetTitleOffset(1.3,"Y");
//    pr[7]->GetXaxis()->SetRangeUser(0.,200.);
//    pr[7]->GetYaxis()->SetRangeUser(0.,650.);
   
   TH1D *temp = pr[7]->Rebin(4);
   temp->GetXaxis()->SetRangeUser(0.,200.);
   temp->Draw();

   pr[0]->Rebin(4)->Draw("same");
   pr[1]->Rebin(4)->Draw("same");
   pr[2]->Rebin(4)->Draw("same");
   pr[3]->Rebin(4)->Draw("same");
   pr[4]->Rebin(4)->Draw("same");
   pr[5]->Rebin(4)->Draw("same");
   pr[6]->Rebin(4)->Draw("same");
   
   TLegend *legend = new TLegend(.6,.5,.85,.85);
   legend->SetBorderSize(1);
   legend->SetFillColor(0);
   //legend->SetFillStyle(0);
   legend->SetTextFont(42);
   legend->AddEntry(pr[0],"p_{T}=50 GeV/c","l");
   legend->AddEntry(pr[1],"p_{T}=100 GeV/c","l");
   legend->AddEntry(pr[2],"p_{T}=300 GeV/c","l");
   legend->AddEntry(pr[3],"p_{T}=500 GeV/c","l");
   legend->AddEntry(pr[4],"p_{T}=1000 GeV/c","l");
   legend->AddEntry(pr[5],"p_{T}=2000 GeV/c","l");
   legend->AddEntry(pr[6],"p_{T}=4000 GeV/c","l");
   legend->AddEntry(pr[7],"p_{T}=7000 GeV/c","l");
   legend->Draw();
   
   string name = pr[0]->GetName();
   string fileName = name + "_" + fNameExt + "_zoomed." + fExt;

   c->SetLogy();
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
   string hostudy_eta01 = "hoStudy_corr_eta0.1.root";
   string hostudy_eta05 = "hoStudy_corr_eta0.5.root";
   string hostudy_eta10 = "hoStudy_corr_eta1.0.root";
   //********************************************
   // make plots
   //********************************************
   plotProducer(hostudy_eta01,"#eta=0.1","corr_eta0.1","eps");
   plotProducer(hostudy_eta05,"#eta=0.5","corr_eta0.5","eps");
   plotProducer(hostudy_eta10,"#eta=1.0","corr_eta1.0","eps");

   plotProducerZoomed(hostudy_eta01,"#eta=0.1","corr_eta0.1","eps");
   plotProducerZoomed(hostudy_eta05,"#eta=0.5","corr_eta0.5","eps");
   plotProducerZoomed(hostudy_eta10,"#eta=1.0","corr_eta1.0","eps");
}