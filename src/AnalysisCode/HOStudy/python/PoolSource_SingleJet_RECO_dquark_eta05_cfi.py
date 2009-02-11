import FWCore.ParameterSet.Config as cms

source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT50_29_0.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT50_29_1.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT50_29_2.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT50_29_3.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT50_29_4.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT50_29_5.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT50_29_6.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT50_29_7.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT50_29_8.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT50_29_9.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT50_34_0.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT50_34_1.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT50_34_2.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT50_34_3.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT50_34_4.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT50_34_5.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT50_34_6.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT50_34_7.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT50_34_8.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT50_34_9.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT100_30_0.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT100_30_1.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT100_30_2.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT100_30_3.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT100_30_4.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT100_30_5.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT100_30_6.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT100_30_7.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT100_30_8.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT100_30_9.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT100_35_0.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT100_35_1.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT100_35_2.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT100_35_3.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT100_35_4.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT100_35_5.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT100_35_6.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT100_35_7.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT100_35_8.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT100_35_9.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT300_31_0.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT300_31_1.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT300_31_2.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT300_31_3.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT300_31_4.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT300_31_5.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT300_31_6.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT300_31_7.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT300_31_8.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT300_31_9.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT300_36_0.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT300_36_1.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT300_36_2.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT300_36_3.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT300_36_4.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT300_36_5.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT300_36_6.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT300_36_7.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT300_36_8.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT300_36_9.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT500_32_0.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT500_32_1.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT500_32_2.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT500_32_3.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT500_32_4.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT500_32_5.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT500_32_6.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT500_32_7.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT500_32_8.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT500_32_9.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT500_37_0.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT500_37_1.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT500_37_2.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT500_37_3.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT500_37_4.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT500_37_5.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT500_37_6.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT500_37_7.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT500_37_8.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT500_37_9.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT1000_33_0.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT1000_33_1.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT1000_33_2.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT1000_33_3.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT1000_33_4.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT1000_33_5.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT1000_33_6.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT1000_33_7.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT1000_33_8.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT1000_33_9.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT1000_38_0.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT1000_38_1.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT1000_38_2.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT1000_38_3.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT1000_38_4.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT1000_38_5.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT1000_38_6.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT1000_38_7.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT1000_38_8.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT1000_38_9.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT2000_34_0.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT2000_34_1.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT2000_34_2.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT2000_34_3.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT2000_34_4.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT2000_34_5.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT2000_34_6.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT2000_34_7.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT2000_34_8.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT2000_34_9.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT2000_39_0.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT2000_39_1.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT2000_39_2.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT2000_39_3.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT2000_39_4.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT2000_39_5.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT2000_39_6.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT2000_39_7.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT2000_39_8.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT2000_39_9.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT4000_35_0.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT4000_35_1.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT4000_35_2.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT4000_35_3.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT4000_35_4.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT4000_35_5.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT4000_35_6.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT4000_35_7.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT4000_35_8.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT4000_35_9.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT4000_40_0.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT4000_40_1.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT4000_40_2.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT4000_40_3.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT4000_40_4.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT4000_40_5.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT4000_40_6.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT4000_40_7.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT4000_40_8.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT4000_40_9.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT7000_36_0.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT7000_36_1.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT7000_36_2.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT7000_36_3.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT7000_36_4.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT7000_36_5.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT7000_36_6.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT7000_36_7.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT7000_36_8.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT7000_36_9.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT7000_69945_0.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT7000_69945_1.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT7000_69945_2.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT7000_69945_3.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT7000_69945_4.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT7000_69945_5.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT7000_69945_6.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT7000_69945_7.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT7000_69945_8.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT7000_69945_9.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT7000_69945_10.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT7000_69945_11.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT7000_69945_12.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT7000_69945_13.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT7000_69945_14.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT7000_69945_15.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT7000_69945_16.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT7000_69945_17.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT7000_69945_18.root',
       'file:/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata/SingleJet_RECO_d-quark_eta0.5_pT7000_69945_19.root'
    )
)