import FWCore.ParameterSet.Config as cms

process = cms.Process('RECO')

# import of standard configurations
process.load('Configuration/StandardSequences/Services_cff')
process.load('FWCore/MessageService/MessageLogger_cfi')
process.load('Configuration/StandardSequences/MixingNoPileUp_cff')
process.load('Configuration/StandardSequences/GeometryPilot2_cff')
process.load('Configuration/StandardSequences/MagneticField_38T_cff')
process.load('Configuration/StandardSequences/Generator_cff')
process.load('Configuration/StandardSequences/VtxSmearedEarly10TeVCollision_cff')
process.load('Configuration/StandardSequences/Sim_cff')
process.load('Configuration/StandardSequences/Digi_cff')
process.load('Configuration/StandardSequences/SimL1Emulator_cff')
process.load('L1TriggerConfig/L1GtConfigProducers/Luminosity/lumi1030.L1Menu2008_2E30_Unprescaled_cff')
process.load('Configuration/StandardSequences/DigiToRaw_cff')
process.load('Configuration/StandardSequences/RawToDigi_cff')
process.load('Configuration/StandardSequences/Reconstruction_cff')
process.load('Configuration/StandardSequences/FrontierConditions_GlobalTag_cff')
process.load('Configuration/EventContent/EventContent_cff')

# grab all starting seeds from /dev/urandom
from IOMC.RandomEngine.RandomServiceHelper import RandomNumberServiceHelper
randHelper = RandomNumberServiceHelper(process.RandomNumberGeneratorService)
randHelper.populate()
process.RandomNumberGeneratorService.saveFileName = cms.untracked.string('CONDOR_OUTPUTFILENAME.random')

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(CONDOR_MAXEVENTS)
)
process.options = cms.untracked.PSet(
    Rethrow = cms.untracked.vstring('ProductNotFound')
)
# Input source
process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/CONDOR_INPUTFILENAME.root'
    ),
    skipEvents = cms.untracked.uint32(CONDOR_SKIPEVENTS)
)

# iterativeCone5CaloJetsWithHO
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

# Output definition
process.output = cms.OutputModule("PoolOutputModule",
    outputCommands = process.RECOSIMEventContent.outputCommands,
    fileName = cms.untracked.string('CONDOR_OUTPUTFILENAME.root'),
    SelectEvents = cms.untracked.PSet(
        SelectEvents = cms.vstring('simulation_step')
    )
)

# Additional output definition

# Other statements
process.GlobalTag.globaltag = 'IDEAL_V9::All'
process.MessageLogger.cerr.FwkReport.reportEvery = CONDOR_FWKREPORT

# Path and EndPath definitions
#process.generation_step = cms.Path(process.pgen)
process.simulation_step = cms.Path(process.psim)
process.digitisation_step = cms.Path(process.pdigi)
process.L1simulation_step = cms.Path(process.SimL1Emulator)
process.digi2raw_step = cms.Path(process.DigiToRaw)
process.raw2digi_step = cms.Path(process.RawToDigi)
process.reconstruction_step = cms.Path(process.reconstruction*process.iterativeCone5CaloJetsWithHO)
process.out_step = cms.EndPath(process.output)

# Schedule definition
process.schedule = cms.Schedule(process.simulation_step,process.digitisation_step,process.L1simulation_step,process.digi2raw_step,process.raw2digi_step,process.reconstruction_step,process.out_step)