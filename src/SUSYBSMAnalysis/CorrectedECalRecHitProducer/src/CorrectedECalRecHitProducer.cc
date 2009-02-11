// -*- C++ -*-
//
// Package:    CorrectedECalRecHitProducer
// Class:      CorrectedECalRecHitProducer
// 
/**\class CorrectedECalRecHitProducer CorrectedECalRecHitProducer.cc SUSYBSMAnalysis/CorrectedECalRecHitProducer/src/CorrectedECalRecHitProducer.cc

 Description: <one line class summary>

 Implementation:
     <Notes on implementation>
*/
//
// Original Author:  Christian SANDER
//         Created:  Wed Nov 19 07:34:36 CET 2008
// $Id: CorrectedECalRecHitProducer.cc,v 1.1.1.1 2008/11/20 08:33:19 csander Exp $
//
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDProducer.h"
#include "FWCore/Framework/interface/ESHandle.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "DataFormats/EcalRecHit/interface/EcalRecHitCollections.h"

//
// class decleration
//

class CorrectedECalRecHitProducer : public edm::EDProducer {
   public:
      explicit CorrectedECalRecHitProducer(const edm::ParameterSet&);
      ~CorrectedECalRecHitProducer();

   private:
      virtual void beginJob(const edm::EventSetup&);
      virtual void produce(edm::Event&, const edm::EventSetup&);
      virtual void endJob();
      edm::InputTag _recHitsEB;
      edm::InputTag _recHitsEE;
      
      // ----------member data ---------------------------
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
CorrectedECalRecHitProducer::CorrectedECalRecHitProducer(const edm::ParameterSet& iConfig):
  _recHitsEB ( iConfig.getParameter<edm::InputTag>( "recHitsEB" ) ),
  _recHitsEE ( iConfig.getParameter<edm::InputTag>( "recHitsEE" ) )
 {
  //register your products
/* Examples
   produces<ExampleData2>();

   //if do put with a label
   produces<ExampleData2>("label");
*/
  produces<EBRecHitCollection>("EcalRecHitsEBcorr");
  produces<EERecHitCollection>("EcalRecHitsEEcorr");

  //now do what ever other initialization is needed

}


CorrectedECalRecHitProducer::~CorrectedECalRecHitProducer()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called to produce the data  ------------
void
CorrectedECalRecHitProducer::produce(edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   using namespace edm;
   using namespace std;

/* This is an event example
   //Read 'ExampleData' from the Event
   Handle<ExampleData> pIn;
   iEvent.getByLabel("example",pIn);

   //Use the ExampleData to create an ExampleData2 which 
   // is put into the Event
   std::auto_ptr<ExampleData2> pOut(new ExampleData2(*pIn));
   iEvent.put(pOut);
*/

/* this is an EventSetup example
   //Read SetupData from the SetupRecord in the EventSetup
   ESHandle<SetupData> pSetup;
   iSetup.get<SetupRecord>().get(pSetup);
*/

   const EBRecHitCollection *EBRecHit = 0;
   edm::Handle<EBRecHitCollection> EcalRecHitEB;
   iEvent.getByLabel( _recHitsEB, EcalRecHitEB);
   if( EcalRecHitEB.isValid() ){ 
     EBRecHit = EcalRecHitEB.product();
   } else {
     cerr << "Error! can't get the product " 
	  << endl;
   }
   std::auto_ptr<EBRecHitCollection> EcalRecHitEBcorr(new EBRecHitCollection());
   
   float gainRatio = 12;
   float EperRecHit = 0.035;
   float ADCmax = 4096;
   float ADCpedestal = 200;
   float Esaturated = (ADCmax-ADCpedestal)*EperRecHit*gainRatio;
   for (EcalRecHitCollection::const_iterator myRecHit = EBRecHit->begin(); 
	myRecHit!=EBRecHit->end(); 
	++myRecHit){
     
     if (myRecHit->energy()<-10.){
       //if saturated create new RecHit
       EcalRecHit corrHit(myRecHit->id(), Esaturated, myRecHit->time());
       EcalRecHitEBcorr->push_back(corrHit);
     } else {
       //take unaltered RecHit
       EcalRecHitEBcorr->push_back(*myRecHit);
     }

   }
   
   const EERecHitCollection *EERecHit = 0;
   edm::Handle<EERecHitCollection> EcalRecHitEE;
   iEvent.getByLabel( _recHitsEE, EcalRecHitEE);
   if( EcalRecHitEE.isValid() ){ 
     EERecHit = EcalRecHitEE.product();
   } else {
     cerr << "Error! can't get the product " 
	  << endl;
   }
   std::auto_ptr<EERecHitCollection> EcalRecHitEEcorr(new EERecHitCollection());

   for (EcalRecHitCollection::const_iterator myRecHit = EERecHit->begin(); 
	myRecHit!=EERecHit->end(); 
	++myRecHit){
     
     if (myRecHit->energy()<-10.){
       //if saturated create new RecHit
       EcalRecHit corrHit(myRecHit->id(), Esaturated, myRecHit->time());
       EcalRecHitEEcorr->push_back(corrHit);
     } else {
       //take unaltered RecHit
       EcalRecHitEEcorr->push_back(*myRecHit);
     }

   }

   iEvent.put(EcalRecHitEBcorr,"EcalRecHitsEBcorr");
   iEvent.put(EcalRecHitEEcorr,"EcalRecHitsEEcorr");

 
}

// ------------ method called once each job just before starting event loop  ------------
void 
CorrectedECalRecHitProducer::beginJob(const edm::EventSetup&)
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
CorrectedECalRecHitProducer::endJob() {
}

//define this as a plug-in
DEFINE_FWK_MODULE(CorrectedECalRecHitProducer);
