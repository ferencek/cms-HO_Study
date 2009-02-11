import FWCore.ParameterSet.Config as cms

process = cms.Process("CorrRecHits")

# Some standard sequences needed for reconstruction 
process.load('Configuration/StandardSequences/Services_cff')
process.load('FWCore/MessageService/MessageLogger_cfi')
process.load('Configuration/StandardSequences/GeometryPilot2_cff')
process.load('Configuration/StandardSequences/MagneticField_38T_cff')
process.load('Configuration/StandardSequences/Reconstruction_cff')
process.load('Configuration/StandardSequences/FrontierConditions_GlobalTag_cff')
process.load('Configuration/EventContent/EventContent_cff')

# Other statements
process.GlobalTag.globaltag = 'IDEAL_V9::All'
process.MessageLogger.cerr.default.limit = 10
process.MessageLogger.cerr.FwkReport.reportEvery = 500

process.maxEvents = cms.untracked.PSet( 
    input = cms.untracked.int32(-1) 
)

# Define source
process.load("AnalysisCode.HOStudy.PoolSource_SingleJet_RECO_dquark_eta10_cfi")

# Make new ECal RecHit collection
process.load("SUSYBSMAnalysis.CorrectedECalRecHitProducer.correctedecalrechitproducer_cfi")
process.CorrectedECalRecHitProducer.recHitsEB = cms.InputTag("ecalRecHit","EcalRecHitsEB")
process.CorrectedECalRecHitProducer.recHitsEE = cms.InputTag("ecalRecHit","EcalRecHitsEE")

# Change ECal input collection for reconstruction
process.towerMaker.ecalInputs = cms.VInputTag(cms.InputTag("CorrectedECalRecHitProducer","EcalRecHitsEBcorr","CorrRecHits"),
                                              cms.InputTag("CorrectedECalRecHitProducer","EcalRecHitsEEcorr","CorrRecHits"))
process.towerMakerWithHO.ecalInputs = cms.VInputTag(cms.InputTag("CorrectedECalRecHitProducer","EcalRecHitsEBcorr","CorrRecHits"),
                                              cms.InputTag("CorrectedECalRecHitProducer","EcalRecHitsEEcorr","CorrRecHits"))

### New Collections ###
# friendlyClassName  | moduleLabel                  | productInstanceName | processName
#--------------------+------------------------------+---------------------+------------
# EcalRecHitsSorted  | CorrectedECalRecHitProducer  | EcalRecHitsEBcorr   | CorrRecHits
# recoCaloJets       | sisCone5CaloJets             |                     | CorrRecHits

# Increase HO threshold from its default Scheme B value of 1.1. GeV to 2.2 GeV
process.towerMaker.HOThreshold = 2.2
process.towerMakerWithHO.HOThreshold = 2.2

# Define iterativeCone5CaloJetsWithHO
CaloJetParametersWithHO = cms.PSet(
    src = cms.InputTag("towerMakerWithHO"),
    verbose = cms.untracked.bool(False),
    jetPtMin = cms.double(0.0),
    inputEtMin = cms.double(0.5),
    jetType = cms.untracked.string('CaloJet'),
    inputEMin = cms.double(0.0)
)
from RecoJets.JetProducers.IconeJetParameters_cfi import *
process.iterativeCone5CaloJetsWithHO = cms.EDProducer("IterativeConeJetProducer",
    CaloJetParametersWithHO,
    IconeJetParameters,
    alias = cms.untracked.string('IC5CaloJetWithHO'),
    coneRadius = cms.double(0.5)
)
process.RECOSIMEventContent.outputCommands.extend(cms.untracked.vstring('keep *_towerMakerWithHO_*_*','keep *_iterativeCone5CaloJetsWithHO_*_*'))

# TFileService
process.TFileService = cms.Service("TFileService",
    fileName = cms.string('hoStudy_corr_eta1.0.root')
)

# Modules needed to perform HO study
process.caloJetCollectionClone = cms.EDProducer("CaloJetShallowCloneProducer",
    src = cms.InputTag("iterativeCone5CaloJets","","CorrRecHits")
)
process.caloJetWithHOCollectionClone = cms.EDProducer("CaloJetShallowCloneProducer",
    src = cms.InputTag("iterativeCone5CaloJetsWithHO","","CorrRecHits")
)
process.genJetCollectionClone = cms.EDProducer("GenJetShallowCloneProducer",
    src = cms.InputTag("iterativeCone5GenJets")
)
process.caloJetSele = cms.EDFilter("PtMinCandSelector",
    src = cms.InputTag("caloJetCollectionClone"),
    ptMin = cms.double(15.0)
)
process.caloJetWithHOSele = cms.EDFilter("PtMinCandSelector",
    src = cms.InputTag("caloJetWithHOCollectionClone"),
    ptMin = cms.double(15.0)
)
process.genJetSele = cms.EDFilter("PtMinCandSelector",
    src = cms.InputTag("genJetCollectionClone"),
    ptMin = cms.double(30.0)
)
process.jetMatchMap = cms.EDFilter("CandOneToOneDeltaRMatcher",
    src = cms.InputTag("genJetSele"),
    matched = cms.InputTag("caloJetSele"),
    algoMethod = cms.string('BruteForce')
)
process.jetWithHOMatchMap = cms.EDFilter("CandOneToOneDeltaRMatcher",
    src = cms.InputTag("genJetSele"),
    matched = cms.InputTag("caloJetWithHOSele"),
    algoMethod = cms.string('BruteForce')
)

# HO study
process.hoStudy = cms.EDAnalyzer('HOStudy',
    matchMapOne = cms.InputTag("jetMatchMap","src2mtc"),
    matchMapOneWithHO = cms.InputTag("jetWithHOMatchMap","src2mtc"),
    genJets = cms.InputTag("iterativeCone5GenJets"),
    selectedGenJets = cms.InputTag("genJetSele"),
    caloJetsWithHO = cms.InputTag("iterativeCone5CaloJetsWithHO","","CorrRecHits"),
    caloJets = cms.InputTag("iterativeCone5CaloJets","","CorrRecHits")
)

# Output definition
#process.output = cms.OutputModule("PoolOutputModule",
    #outputCommands = process.RECOSIMEventContent.outputCommands,
    #fileName = cms.untracked.string('SingleJet_RECO_d-quark_eta1.0_corr.root')
#)

# Path and EndPath definitions
process.correction_step = cms.Path(process.CorrectedECalRecHitProducer)
process.reconstruction_step = cms.Path(process.caloTowersRec*(process.iterativeCone5CaloJets+process.iterativeCone5CaloJetsWithHO))
process.analysis_step = cms.Path((process.caloJetCollectionClone+process.caloJetWithHOCollectionClone+process.genJetCollectionClone)*(process.caloJetSele+process.caloJetWithHOSele+process.genJetSele)*(process.jetMatchMap+process.jetWithHOMatchMap)*process.hoStudy)
#process.out_step = cms.EndPath(process.output)

# Schedule definition
process.schedule = cms.Schedule(process.correction_step,process.reconstruction_step,process.analysis_step)
