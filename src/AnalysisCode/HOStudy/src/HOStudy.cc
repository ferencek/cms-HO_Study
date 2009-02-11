// -*- C++ -*-
//
// Package:    HOStudy
// Class:      HOStudy
// 
/**\class HOStudy HOStudy.cc AnalysisCode/HOStudy/src/HOStudy.cc

 Description: <one line class summary>

 Implementation:
     <Notes on implementation>
*/
//
// Original Author:  Dinko Ferencek
//         Created:  Mon Nov 24 14:39:02 EST 2008
// $Id$
//
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "DataFormats/Common/interface/Ref.h"
#include "DataFormats/JetReco/interface/Jet.h"
#include "DataFormats/JetReco/interface/CaloJet.h"
#include "DataFormats/JetReco/interface/CaloJetCollection.h"
#include "DataFormats/JetReco/interface/GenJet.h"
#include "DataFormats/JetReco/interface/GenJetCollection.h"
#include "DataFormats/Candidate/interface/CandMatchMap.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"

//TFile Service
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "PhysicsTools/UtilAlgos/interface/TFileService.h"

// ROOT
#include <TROOT.h>
#include <TSystem.h>
#include <TStyle.h>
#include <TFile.h>
#include <TCanvas.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TProfile.h>
#include <TNtuple.h>

#include <Math/VectorUtil.h>

using namespace std;
using namespace edm;
using namespace reco;
using namespace ROOT::Math::VectorUtil;

//
// class decleration
//

class HOStudy : public edm::EDAnalyzer {
   public:
      explicit HOStudy(const edm::ParameterSet&);
      ~HOStudy();


   private:
      virtual void beginJob(const edm::EventSetup&) ;
      virtual void analyze(const edm::Event&, const edm::EventSetup&);
      virtual void endJob() ;

      // ----------member data ---------------------------
      edm::Service<TFileService> fs;
      
      InputTag matchMapOne_;
      InputTag matchMapOneWithHO_;
      InputTag genJets_;
      InputTag selectedGenJets_;
      InputTag caloJetsWithHO_;
      InputTag caloJets_;

      Handle<CandViewMatchMap>  matchedJetsMap;
      Handle<CandViewMatchMap>  matchedJetsWithHOMap;
      Handle<GenJetCollection>  genJets;
      Handle<CandidateCollection>  selectedGenJets;
      Handle<CaloJetCollection>  caloJetsWithHO;
      Handle<CaloJetCollection>  caloJets;
      
      TH1F *h_GenJetEta;
      TH1F *h_GenJetPhi;
      TH1F *h_CaloJetEta;
      TH1F *h_CaloJetPhi;
      TH1F *h_CaloJetWithHOEta;
      TH1F *h_CaloJetWithHOPhi;
      TH1F *h_DeltaR;
      TH1F *h_DeltaRWithHO;
      TH1F *h_DeltaE;
      TH1F *h_DeltaEHO;
      TH2F *h_DeltaE_EHO;
      TH2F *h_ETRatio_ET; 
      TH2F *h_ETRatioWithHO_ET;
      TH1F *h_GenJetDeltaE;
      TH2F *h_ConstituentpT_ET;
      TNtuple *n_Ntuple;
};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
HOStudy::HOStudy(const edm::ParameterSet& iConfig)

{
   //now do what ever initialization is needed
   matchMapOne_       = iConfig.getParameter<InputTag> ("matchMapOne");
   matchMapOneWithHO_ = iConfig.getParameter<InputTag> ("matchMapOneWithHO");
   genJets_ = iConfig.getParameter<InputTag> ("genJets");
   selectedGenJets_ = iConfig.getParameter<InputTag> ("selectedGenJets");
   caloJetsWithHO_ = iConfig.getParameter<InputTag> ("caloJetsWithHO");
   caloJets_ = iConfig.getParameter<InputTag> ("caloJets");
}


HOStudy::~HOStudy()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called once each job just before starting event loop  ------------
void 
HOStudy::beginJob(const edm::EventSetup&)
{
    // book all histograms
   h_GenJetEta  = fs->make<TH1F>("h_GenJetEta","GenJet  #eta;#eta;Entries/0.01",150,0.,1.5);
   h_GenJetPhi  = fs->make<TH1F>("h_GenJetPhi","GenJet  #phi;#phi;Entries/0.02",315,-3.15,3.15);
   h_CaloJetEta = fs->make<TH1F>("h_CaloJetEta","CaloJet  #eta;#eta;Entries/0.01",150,0.,1.5);
   h_CaloJetPhi = fs->make<TH1F>("h_CaloJetPhi","CaloJet  #phi;#phi;Entries/0.02",315,-3.15,3.15);
   h_CaloJetWithHOEta = fs->make<TH1F>("h_CaloJetWithHOEta","CaloJetWithHO  #eta;#eta;Entries/0.01",150,0.,1.5);
   h_CaloJetWithHOPhi = fs->make<TH1F>("h_CaloJetWithHOPhi","CaloJetWithHO  #phi;#phi;Entries/0.02",315,-3.15,3.15);
   h_DeltaR        = fs->make<TH1F>("h_DeltaR","#DeltaR(GenJet,CaloJet);#DeltaR;Entries/0.005",100,0.,0.5);
   h_DeltaRWithHO  = fs->make<TH1F>("h_DeltaRWithHO","#DeltaR(GenJet,CaloJetWithHO);#DeltaR;Entries/0.005",100,0.,0.5);
   h_DeltaE           = fs->make<TH1F>("h_DeltaE","#DeltaE=E^{calo,HO}-E^{calo,HO};#DeltaE [GeV];Entries/(0.1 GeV)",200,-10.,10.);
   h_DeltaEHO         = fs->make<TH1F>("h_DeltaEHO","#DeltaE_{HO}=(E^{calo,HO}-E^{calo})-hadEnergyInHO;#DeltaE_{HO} [GeV];Entries/(0.1 GeV)",200,-10.,10.);
   h_DeltaE_EHO       = fs->make<TH2F>("h_DeltaE_EHO",";hadEnergyInHO [GeV];E^{calo,HO}-E^{calo} [GeV]",260,-10.,250.,260,-10.,250.);
   h_ETRatio_ET       = fs->make<TH2F>("h_ETRatio_ET",";E^{gen}_{T} [GeV];E^{calo}_{T}/E^{gen}_{T}",7200,0.,7200.,150,0.,1.5);
   h_ETRatioWithHO_ET = fs->make<TH2F>("h_ETRatioWithHO_ET",";E^{gen}_{T} [GeV];E^{calo,HO}_{T}/E^{gen}_{T}",7200,0.,7200.,150,0.,1.5);
   h_GenJetDeltaE     = fs->make<TH1F>("h_GenJetDeltaE","#DeltaE=E^{gen}-E^{gen};#DeltaE [GeV];Entries/(0.1 GeV)",200,-10.,10.);
   h_ConstituentpT_ET = fs->make<TH2F>("h_ConstituentpT_ET",";E^{gen}_{T} [GeV];p_{T} [GeV/c]",7200,0.,7200.,2000,0.,2000.);
   n_Ntuple = fs->make<TNtuple>("n_Ntuple","HO Study Ntuple", "GenJetE:GenJetEta:GenJetPhi:CaloJetE:CaloJetEta:CaloJetPhi:CaloJetWithHOE:CaloJetWithHOEta:CaloJetWithHOPhi:HadEnergyInHB:HadEnergyInHO");
}

// ------------ method called to for each event  ------------
void
HOStudy::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   try {
      iEvent.getByLabel (matchMapOne_, matchedJetsMap);
      iEvent.getByLabel (matchMapOneWithHO_, matchedJetsWithHOMap);
      iEvent.getByLabel (genJets_, genJets);
      iEvent.getByLabel (selectedGenJets_, selectedGenJets);
      iEvent.getByLabel (caloJetsWithHO_, caloJetsWithHO);
      iEvent.getByLabel (caloJets_, caloJets);
   } catch(std::exception& ce) {
      cerr << "[HOStudy] caught std::exception " << ce.what() << endl;
      return;
   }
   // require one and only one selected reconstructed GenJet
   if ( selectedGenJets->size() == 1 ) {
      // loop over GenJet constituent particles and get their pT's
      for( CandidateCollection::const_iterator sj  = selectedGenJets->begin();
                                            sj != selectedGenJets->end();
                                            sj++ ) {
         for( GenJetCollection::const_iterator j  = genJets->begin();
                                               j != genJets->end();
                                               j++ ) {
            if ( DeltaR( sj->p4(),j->p4() ) < 0.001 ) {
               h_GenJetDeltaE->Fill( sj->energy() - j->energy() );
               std::vector<const GenParticle*> genJetConstituents = j->getGenConstituents();
               std::vector<const GenParticle*>::const_iterator c;
               for ( c = genJetConstituents.begin(); c != genJetConstituents.end(); c++ ) {
                  h_ConstituentpT_ET->Fill( j->et(), (*c)->pt() );
               }
            }
         }
      }
      // loop over matchedJetsMap
      double genJetE = 0;
      double genJetEta = 0;
      double genJetPhi = -4.;
      double caloJetE = 0;
      double caloJetEta = 0;
      double caloJetPhi = -4.;
      double dR = -1.;
      double caloJetWithHOE = 0;
      double caloJetWithHOEta = 0;
      double caloJetWithHOPhi = -4.;
      double dRWithHO = -1.;
      double hadEnergyInHB = 0;
      double hadEnergyInHO = 0;
      for( CandViewMatchMap::const_iterator i  = matchedJetsMap->begin();
					    i != matchedJetsMap->end();
					    i++ ) {
	  const Candidate *sourceRef = &*(i->key);
	  const Candidate *matchRef  = &*(i->val);
	  genJetE =  sourceRef->energy();
	  genJetEta =  sourceRef->eta();
	  genJetPhi =  sourceRef->phi();
	  caloJetE =  matchRef->energy();
	  caloJetEta =  matchRef->eta();
	  caloJetPhi =  matchRef->phi();
	  dR = DeltaR( sourceRef->p4() , matchRef->p4() );
	  h_GenJetEta->Fill( genJetEta );
	  h_GenJetPhi->Fill( genJetPhi );
	  h_CaloJetEta->Fill( caloJetEta );
	  h_CaloJetPhi->Fill( caloJetPhi );
	  h_DeltaR->Fill( dR );
	  h_ETRatio_ET->Fill( sourceRef->et(), matchRef->et()/sourceRef->et() );
// 	  for( CaloJetCollection::const_iterator j  = caloJets->begin();
// 						 j != caloJets->end();
// 						 j++ ) {
// 	      if ( DeltaR( matchRef->p4(), j->p4() ) < 0.001 ) {
//                  cout<<">> hadEnergyInHO for CaloJet without HO = "<<j->hadEnergyInHO()<<" GeV"<<endl;
//               }
// 	  }
      }
      // loop over matchedJetsWithHOMap
      for( CandViewMatchMap::const_iterator i  = matchedJetsWithHOMap->begin();
					    i != matchedJetsWithHOMap->end();
					    i++ ) {
	  const Candidate *sourceRef = &*(i->key);
	  const Candidate *matchRef  = &*(i->val);
	  caloJetWithHOE =  matchRef->energy();
          caloJetWithHOEta =  matchRef->eta();
          caloJetWithHOPhi =  matchRef->phi();
	  dRWithHO = DeltaR( sourceRef->p4(), matchRef->p4() );
	  h_CaloJetWithHOEta->Fill( caloJetWithHOEta );
	  h_CaloJetWithHOPhi->Fill( caloJetWithHOPhi );
	  h_DeltaRWithHO->Fill( dRWithHO );
	  h_ETRatioWithHO_ET->Fill( sourceRef->et(), matchRef->et()/sourceRef->et() );
	  for( CaloJetCollection::const_iterator j  = caloJetsWithHO->begin();
						 j != caloJetsWithHO->end();
						 j++ ) {
	      if ( DeltaR( matchRef->p4(), j->p4() ) < 0.001 ) {
	         hadEnergyInHB = j->hadEnergyInHB();
                 hadEnergyInHO = j->hadEnergyInHO();
		 h_DeltaE->Fill( caloJetWithHOE - j->energy() );
		 h_DeltaEHO->Fill( (caloJetWithHOE - caloJetE) - hadEnergyInHO );
		 h_DeltaE_EHO->Fill( hadEnergyInHO, (caloJetWithHOE - caloJetE) );
                 //cout<<">> hadEnergyInHO for CaloJet with HO = "<<j->hadEnergyInHO()<<" GeV"<<endl;
	      } 
	  }
      }
      n_Ntuple->Fill(genJetE,genJetEta,genJetPhi,caloJetE,caloJetEta,caloJetPhi,caloJetWithHOE,caloJetWithHOEta,caloJetWithHOPhi,hadEnergyInHB,hadEnergyInHO);
   }

}

// ------------ method called once each job just after ending the event loop  ------------
void 
HOStudy::endJob() {
}

//define this as a plug-in
DEFINE_FWK_MODULE(HOStudy);
