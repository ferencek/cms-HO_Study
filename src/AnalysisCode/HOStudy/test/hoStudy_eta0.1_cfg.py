import FWCore.ParameterSet.Config as cms

process = cms.Process("USER")

process.load("FWCore.MessageService.MessageLogger_cfi")
process.MessageLogger.cerr.default.limit = 10
process.MessageLogger.cerr.FwkReport.reportEvery = 500

process.maxEvents = cms.untracked.PSet( 
    input = cms.untracked.int32(-1) 
)

process.load("AnalysisCode.HOStudy.PoolSource_SingleJet_RECO_dquark_eta01_cfi")

process.TFileService = cms.Service("TFileService",
    fileName = cms.string('hoStudy_eta0.1.root')
)

process.caloJetCollectionClone = cms.EDProducer("CaloJetShallowCloneProducer",
    src = cms.InputTag("iterativeCone5CaloJets")
)
process.caloJetWithHOCollectionClone = cms.EDProducer("CaloJetShallowCloneProducer",
    src = cms.InputTag("iterativeCone5CaloJetsWithHO")
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

process.testMatchMany = cms.EDFilter("CandOneToManyDeltaRMatcher",
    printDebug = cms.untracked.bool(True),
    src = cms.InputTag("genJetSele"),
    matched = cms.InputTag("caloJetSele")
)

process.hoStudy = cms.EDAnalyzer('HOStudy',
    matchMapOne = cms.InputTag("jetMatchMap","src2mtc"),
    matchMapOneWithHO = cms.InputTag("jetWithHOMatchMap","src2mtc"),
    genJets = cms.InputTag("genJetSele"),
    caloJetsWithHO = cms.InputTag("iterativeCone5CaloJetsWithHO")
)

# Output definition
#process.output = cms.OutputModule("PoolOutputModule",
    #outputCommands = cms.untracked.vstring('keep *_*_*_USER'),
    #fileName = cms.untracked.string('test.root')
#)

process.p = cms.Path((process.caloJetCollectionClone+process.caloJetWithHOCollectionClone+process.genJetCollectionClone)*(process.caloJetSele+process.caloJetWithHOSele+process.genJetSele)*(process.jetMatchMap+process.jetWithHOMatchMap)*process.hoStudy)
#process.outpath = cms.EndPath(process.output)
