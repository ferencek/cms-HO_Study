import FWCore.ParameterSet.Config as cms

process = cms.Process("CorrRecHits")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

### Define source ###
process.source = cms.Source ("PoolSource",
                             fileNames = cms.untracked.vstring (
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0001/0AA3BA3B-AA7D-DD11-B345-000423D9939C.root',
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0001/0E87F6D4-C47D-DD11-9413-000423D999CA.root',
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0001/12B28E56-C27D-DD11-A201-000423D98800.root',
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0001/12D4355B-C27D-DD11-B735-000423D98FBC.root',
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0001/1473DEEE-C17D-DD11-A6E6-001617E30F50.root',
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0001/1E8AC487-C27D-DD11-B51F-000423D98750.root',
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0001/2059BD3B-C27D-DD11-9D94-000423D6CA02.root',
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0001/20E79713-AA7D-DD11-91A0-000423D98950.root',
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0001/220C6967-C27D-DD11-B08E-0019DB2F3F9B.root',
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0001/22CE1C68-C47D-DD11-A799-000423D985B0.root',
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0001/2450ACD9-C17D-DD11-9A18-000423D990CC.root',
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0001/343C80EB-C17D-DD11-AA2D-001617DF785A.root',
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0001/3ABDB0A1-C27D-DD11-AC3D-001617C3B77C.root',
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0001/3C1E695B-C57D-DD11-946E-001617C3B79A.root',
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0001/3C4E0855-C57D-DD11-ADF8-000423D99660.root',
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0001/3E2B7F84-C27D-DD11-A38A-001617C3B66C.root',
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0001/466FD7BC-C27D-DD11-A7DF-000423D6C8E6.root',
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0001/4C7E98F6-C17D-DD11-8E7B-001617E30CE8.root',
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0001/581ED35D-E77D-DD11-8A78-000423D9517C.root',
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0001/58582CF0-F87D-DD11-9DDA-0019DB2F3F9B.root',
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0001/5A3E6989-C27D-DD11-B824-0019DB2F3F9B.root',
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0001/5CC42B1C-C27D-DD11-8A09-000423D60FF6.root',
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0001/6021BE41-C27D-DD11-AF1C-001617C3B6C6.root',
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0001/60B26B4E-C27D-DD11-9433-001617C3B6CC.root',
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0001/6632A01F-AA7D-DD11-8BE9-000423D99F3E.root',
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0001/66A01CAA-C17D-DD11-A269-001617E30D40.root',
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0001/6A9077CD-C27D-DD11-A14C-000423D6B5C4.root',
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0001/6EB65B37-AA7D-DD11-AAE6-001617C3B778.root',
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0001/707F947F-C27D-DD11-9837-000423D990CC.root',
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0001/72E8C574-C27D-DD11-A683-0019DB29C620.root',
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0001/7611D9DE-A97D-DD11-9FED-001617DBD556.root',
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0001/7AB7122D-AA7D-DD11-A081-0019DB29C614.root',
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0001/840A931E-C27D-DD11-8CC1-001617C3B78C.root',
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0001/84FF395C-C57D-DD11-996E-000423D992DC.root',
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0001/98557CFE-C17D-DD11-9D46-000423D98E6C.root',
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0001/A20B84E5-A97D-DD11-B603-001617E30D12.root',
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0001/A2469138-AA7D-DD11-BCF7-000423D94E70.root',
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0001/A65FC84B-C57D-DD11-AAD6-000423D9997E.root',
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0001/A801FD3E-C27D-DD11-A8F5-001617C3B6DC.root',
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0001/AED3CD88-FC7D-DD11-BEA1-000423D9890C.root',
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0001/B00F549A-C27D-DD11-87F1-000423D986A8.root',
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0001/B686E6EE-C27D-DD11-9168-000423D990CC.root',
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0001/BC911460-C27D-DD11-A342-000423D6B5C4.root',
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0001/BE244DA6-C27D-DD11-99A0-001617DF785A.root',
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0001/C0A75C1B-AA7D-DD11-A680-001617E30D52.root',
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0001/C4E2E3F1-C17D-DD11-AFED-000423D98868.root',
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0001/CA7417E4-C27D-DD11-B4CA-000423D9880C.root',
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0001/CAF6B0BF-C17D-DD11-BC58-001617C3B76A.root',
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0001/D0E331EB-A97D-DD11-B853-001617E30F50.root',
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0001/D245D9E9-A97D-DD11-86C6-001617DC1F70.root',
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0001/D47617BF-C27D-DD11-ADBD-001617C3B64C.root',
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0001/D4D6BFDE-C27D-DD11-BF60-000423D94C68.root',
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0001/E08DBDF5-C27D-DD11-8C2F-001617C3B78C.root',
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0001/E0BBA0BC-C27D-DD11-A4B2-001617E30D40.root',
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0001/E2F1DF77-C27D-DD11-947A-000423D99AA2.root',
       #'/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0001/E8ED8015-AA7D-DD11-88A5-001617DBD332.root',
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0001/EE4DD77C-C27D-DD11-AE78-000423D996B4.root',
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0001/EEB142C7-C17D-DD11-ADE8-000423D94494.root',
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0001/F8B7ECAD-C17D-DD11-9ABE-001617C3B6CC.root',
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0002/B8BF4024-437E-DD11-BFD2-0016177CA778.root',
       '/store/relval/CMSSW_2_1_7/RelValQCD_Pt_3000_3500/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0002/C8C5DE91-077F-DD11-BDE3-000423D6CA42.root'
      ),
       secondaryFileNames = cms.untracked.vstring (
      )
)

### Source is local file ###
#process.source = cms.Source("PoolSource",
#    fileNames = cms.untracked.vstring(
#        'file:///scratch/csander/RelVal/mysticEvents.root'
#    )
#)

### Some standard sequences needed for reconstruction ###
process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cff")
process.GlobalTag.globaltag = 'STARTUP_V4::All'
process.load("Configuration.StandardSequences.Geometry_cff")
process.load("Configuration.StandardSequences.MagneticField_cff")

### Make new ECal RecHit collection ###
process.load("SUSYBSMAnalysis.CorrectedECalRecHitProducer.correctedecalrechitproducer_cfi")
process.CorrectedECalRecHitProducer.recHitsEB = cms.InputTag("ecalRecHit","EcalRecHitsEB")
process.CorrectedECalRecHitProducer.recHitsEE = cms.InputTag("ecalRecHit","EcalRecHitsEE")

### Change ECal input collection for reconstruction ###
process.load("Configuration.StandardSequences.Reconstruction_cff")
process.towerMaker.ecalInputs = cms.VInputTag(cms.InputTag("CorrectedECalRecHitProducer","EcalRecHitsEBcorr","CorrRecHits"),
                                              cms.InputTag("CorrectedECalRecHitProducer","EcalRecHitsEEcorr","CorrRecHits"))

### new Collections ###
# friendlyClassName  | moduleLabel                  | productInstanceName | processName
#--------------------+------------------------------+---------------------+------------
# EcalRecHitsSorted  | CorrectedECalRecHitProducer  | EcalRecHitsEBcorr   | CorrRecHits
# recoCaloJets       | sisCone5CaloJets             |                     | CorrRecHits

### TFileService ###
process.TFileService = cms.Service("TFileService",
    fileName = cms.string('QCD_3000_3500_217_Ideal_V9_v1_bugfix.root')
)

### HSusyAnalyzer to make histos ###
process.load("SUSYBSMAnalysis.HSusyAnalyzer.hsusyanalyzer_cfi")
process.HSusyAnalyzer.recJet = cms.InputTag("sisCone5CaloJets","","CorrRecHits")
process.HSusyAnalyzer.genJet = 'sisCone5GenJets'
process.HSusyAnalyzer.recMet =  cms.InputTag("met","","CorrRecHits")
process.HSusyAnalyzer.genMet = 'genMet'
process.HSusyAnalyzer.hist   = 'QCD_3000_3500_217_Ideal_V9_v1_bugfix.root'
process.HSusyAnalyzer.MinJetPt = 50.
process.HSusyAnalyzer.MinGenJetPt = 500.
process.HSusyAnalyzer.MaxJetEta = 5.0
process.HSusyAnalyzer.METcut = 0.0
process.HSusyAnalyzer.ScaleForPlots = 4000.0

process.dump = cms.EDAnalyzer("EventContentAnalyzer")

### Output fo file ###
#process.out = cms.OutputModule("PoolOutputModule",
#    fileName = cms.untracked.string('myOutputFile.root')
#)

### Definition of path ###
process.p = cms.Path(process.CorrectedECalRecHitProducer*process.caloTowersRec*process.recoJets*process.metreco*process.HSusyAnalyzer)
#process.p = cms.Path(process.myProducerLabel)
#process.p = cms.Path(process.HSusyAnalyzer)

#process.e = cms.EndPath(process.out)
