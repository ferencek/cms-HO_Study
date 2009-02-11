import FWCore.ParameterSet.Config as cms

CorrectedECalRecHitProducer = cms.EDProducer('CorrectedECalRecHitProducer',
                                             recHitsEB = cms.InputTag("ecalRecHit","EcalRecHitsEB"),
                                             recHitsEE = cms.InputTag("ecalRecHit","EcalRecHitsEE")
                                             )
