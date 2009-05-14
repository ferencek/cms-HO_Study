import FWCore.ParameterSet.Config as cms

process = cms.Process('GEN')

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
process.load("Configuration.Generator.PythiaUESettings_cfi")
process.source = cms.Source("PythiaSource",
    pythiaPylistVerbosity = cms.untracked.int32(0),
    maxEventsToPrint = cms.untracked.int32(0),
    pythiaHepMCVerbosity = cms.untracked.bool(False),
    #  possibility to run single or double back-to-back particles with PYTHIA
    DoubleParticle = cms.untracked.bool(False),
    # if ParticleID = 0, run PYTHIA
    ParticleID = cms.untracked.int32(CONDOR_PID),
    Etamin = cms.untracked.double(CONDOR_ETA),
    Etamax = cms.untracked.double(CONDOR_ETA),
    Phimin = cms.untracked.double(0.0),
    Phimax = cms.untracked.double(360.0),
    Ptmin = cms.untracked.double(CONDOR_PT),
    Ptmax = cms.untracked.double(CONDOR_PT),
    PythiaParameters = cms.PSet(
        process.pythiaUESettingsBlock,
        # This is a vector of ParameterSet names to be read, in this order
        parameterSets = cms.vstring('pythiaUESettings')
    )
)

# Output definition
process.output = cms.OutputModule("PoolOutputModule",
    outputCommands = process.RECOSIMEventContent.outputCommands,
    fileName = cms.untracked.string('CONDOR_OUTPUTFILENAME.root'),
    SelectEvents = cms.untracked.PSet(
        SelectEvents = cms.vstring('generation_step')
    )
)

# Additional output definition

# Other statements
process.GlobalTag.globaltag = 'IDEAL_V9::All'
process.MessageLogger.cerr.FwkReport.reportEvery = CONDOR_FWKREPORT

# Path and EndPath definitions
process.generation_step = cms.Path(process.pgen)
process.out_step = cms.EndPath(process.output)

# Schedule definition
process.schedule = cms.Schedule(process.generation_step,process.out_step)
