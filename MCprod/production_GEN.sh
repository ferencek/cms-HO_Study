#!/bin/bash

FILE=`echo SingleJet_GEN`

cd MCdata/

echo ""
echo ">> `/bin/date` Submitting Condor job(s)..."
#==========================================================
#======================= eta=0.1 ==========================
#==========================================================
echo ">> `/bin/date` SingleJet: d-quark, eta=0.1, pT=50 GeV"

EXTENSION=`echo d-quark_eta0.1_pT50`

cat ../${FILE}_template_cfg.py \
| sed -e s/CONDOR_OUTPUTFILENAME/${FILE}_${EXTENSION}/ \
| sed -e s/CONDOR_MAXEVENTS/4000/ \
| sed -e s/CONDOR_PID/1/ \
| sed -e s/CONDOR_ETA/0.1/ \
| sed -e s/CONDOR_PT/50/ \
| sed -e s/CONDOR_FWKREPORT/100/ \
> ${FILE}_${EXTENSION}_cfg.py

cat ../${FILE}_template.jdl \
| sed -e s/PREFIX_NAME/${FILE}_${EXTENSION}/ \
| sed -e s~RUN_DIR~/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata~ \
> ${FILE}_${EXTENSION}.jdl

condor_submit ${FILE}_${EXTENSION}.jdl
#==========================================================
echo ">> `/bin/date` SingleJet: d-quark, eta=0.1, pT=100 GeV"

EXTENSION=`echo d-quark_eta0.1_pT100`

cat ../${FILE}_template_cfg.py \
| sed -e s/CONDOR_OUTPUTFILENAME/${FILE}_${EXTENSION}/ \
| sed -e s/CONDOR_MAXEVENTS/4000/ \
| sed -e s/CONDOR_PID/1/ \
| sed -e s/CONDOR_ETA/0.1/ \
| sed -e s/CONDOR_PT/100/ \
| sed -e s/CONDOR_FWKREPORT/100/ \
> ${FILE}_${EXTENSION}_cfg.py

cat ../${FILE}_template.jdl \
| sed -e s/PREFIX_NAME/${FILE}_${EXTENSION}/ \
| sed -e s~RUN_DIR~/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata~ \
> ${FILE}_${EXTENSION}.jdl

condor_submit ${FILE}_${EXTENSION}.jdl
#==========================================================
echo ">> `/bin/date` SingleJet: d-quark, eta=0.1, pT=300 GeV"

EXTENSION=`echo d-quark_eta0.1_pT300`

cat ../${FILE}_template_cfg.py \
| sed -e s/CONDOR_OUTPUTFILENAME/${FILE}_${EXTENSION}/ \
| sed -e s/CONDOR_MAXEVENTS/4000/ \
| sed -e s/CONDOR_PID/1/ \
| sed -e s/CONDOR_ETA/0.1/ \
| sed -e s/CONDOR_PT/300/ \
| sed -e s/CONDOR_FWKREPORT/100/ \
> ${FILE}_${EXTENSION}_cfg.py

cat ../${FILE}_template.jdl \
| sed -e s/PREFIX_NAME/${FILE}_${EXTENSION}/ \
| sed -e s~RUN_DIR~/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata~ \
> ${FILE}_${EXTENSION}.jdl

condor_submit ${FILE}_${EXTENSION}.jdl
#==========================================================
echo ">> `/bin/date` SingleJet: d-quark, eta=0.1, pT=500 GeV"

EXTENSION=`echo d-quark_eta0.1_pT500`

cat ../${FILE}_template_cfg.py \
| sed -e s/CONDOR_OUTPUTFILENAME/${FILE}_${EXTENSION}/ \
| sed -e s/CONDOR_MAXEVENTS/4000/ \
| sed -e s/CONDOR_PID/1/ \
| sed -e s/CONDOR_ETA/0.1/ \
| sed -e s/CONDOR_PT/500/ \
| sed -e s/CONDOR_FWKREPORT/100/ \
> ${FILE}_${EXTENSION}_cfg.py

cat ../${FILE}_template.jdl \
| sed -e s/PREFIX_NAME/${FILE}_${EXTENSION}/ \
| sed -e s~RUN_DIR~/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata~ \
> ${FILE}_${EXTENSION}.jdl

condor_submit ${FILE}_${EXTENSION}.jdl
#==========================================================
echo ">> `/bin/date` SingleJet: d-quark, eta=0.1, pT=1000 GeV"

EXTENSION=`echo d-quark_eta0.1_pT1000`

cat ../${FILE}_template_cfg.py \
| sed -e s/CONDOR_OUTPUTFILENAME/${FILE}_${EXTENSION}/ \
| sed -e s/CONDOR_MAXEVENTS/4000/ \
| sed -e s/CONDOR_PID/1/ \
| sed -e s/CONDOR_ETA/0.1/ \
| sed -e s/CONDOR_PT/1000/ \
| sed -e s/CONDOR_FWKREPORT/100/ \
> ${FILE}_${EXTENSION}_cfg.py

cat ../${FILE}_template.jdl \
| sed -e s/PREFIX_NAME/${FILE}_${EXTENSION}/ \
| sed -e s~RUN_DIR~/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata~ \
> ${FILE}_${EXTENSION}.jdl

condor_submit ${FILE}_${EXTENSION}.jdl
#==========================================================
echo ">> `/bin/date` SingleJet: d-quark, eta=0.1, pT=2000 GeV"

EXTENSION=`echo d-quark_eta0.1_pT2000`

cat ../${FILE}_template_cfg.py \
| sed -e s/CONDOR_OUTPUTFILENAME/${FILE}_${EXTENSION}/ \
| sed -e s/CONDOR_MAXEVENTS/4000/ \
| sed -e s/CONDOR_PID/1/ \
| sed -e s/CONDOR_ETA/0.1/ \
| sed -e s/CONDOR_PT/2000/ \
| sed -e s/CONDOR_FWKREPORT/100/ \
> ${FILE}_${EXTENSION}_cfg.py

cat ../${FILE}_template.jdl \
| sed -e s/PREFIX_NAME/${FILE}_${EXTENSION}/ \
| sed -e s~RUN_DIR~/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata~ \
> ${FILE}_${EXTENSION}.jdl

condor_submit ${FILE}_${EXTENSION}.jdl
#==========================================================
echo ">> `/bin/date` SingleJet: d-quark, eta=0.1, pT=4000 GeV"

EXTENSION=`echo d-quark_eta0.1_pT4000`

cat ../${FILE}_template_cfg.py \
| sed -e s/CONDOR_OUTPUTFILENAME/${FILE}_${EXTENSION}/ \
| sed -e s/CONDOR_MAXEVENTS/4000/ \
| sed -e s/CONDOR_PID/1/ \
| sed -e s/CONDOR_ETA/0.1/ \
| sed -e s/CONDOR_PT/4000/ \
| sed -e s/CONDOR_FWKREPORT/100/ \
> ${FILE}_${EXTENSION}_cfg.py

cat ../${FILE}_template.jdl \
| sed -e s/PREFIX_NAME/${FILE}_${EXTENSION}/ \
| sed -e s~RUN_DIR~/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata~ \
> ${FILE}_${EXTENSION}.jdl

condor_submit ${FILE}_${EXTENSION}.jdl
#==========================================================
echo ">> `/bin/date` SingleJet: d-quark, eta=0.1, pT=7000 GeV"

EXTENSION=`echo d-quark_eta0.1_pT7000`

cat ../${FILE}_template_cfg.py \
| sed -e s/CONDOR_OUTPUTFILENAME/${FILE}_${EXTENSION}/ \
| sed -e s/CONDOR_MAXEVENTS/4000/ \
| sed -e s/CONDOR_PID/1/ \
| sed -e s/CONDOR_ETA/0.1/ \
| sed -e s/CONDOR_PT/7000/ \
| sed -e s/CONDOR_FWKREPORT/100/ \
> ${FILE}_${EXTENSION}_cfg.py

cat ../${FILE}_template.jdl \
| sed -e s/PREFIX_NAME/${FILE}_${EXTENSION}/ \
| sed -e s~RUN_DIR~/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata~ \
> ${FILE}_${EXTENSION}.jdl

condor_submit ${FILE}_${EXTENSION}.jdl
#==========================================================
#======================= eta=0.5 ==========================
#==========================================================
echo ">> `/bin/date` SingleJet: d-quark, eta=0.5, pT=50 GeV"

EXTENSION=`echo d-quark_eta0.5_pT50`

cat ../${FILE}_template_cfg.py \
| sed -e s/CONDOR_OUTPUTFILENAME/${FILE}_${EXTENSION}/ \
| sed -e s/CONDOR_MAXEVENTS/4000/ \
| sed -e s/CONDOR_PID/1/ \
| sed -e s/CONDOR_ETA/0.5/ \
| sed -e s/CONDOR_PT/50/ \
| sed -e s/CONDOR_FWKREPORT/100/ \
> ${FILE}_${EXTENSION}_cfg.py

cat ../${FILE}_template.jdl \
| sed -e s/PREFIX_NAME/${FILE}_${EXTENSION}/ \
| sed -e s~RUN_DIR~/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata~ \
> ${FILE}_${EXTENSION}.jdl

condor_submit ${FILE}_${EXTENSION}.jdl
#==========================================================
echo ">> `/bin/date` SingleJet: d-quark, eta=0.5, pT=100 GeV"

EXTENSION=`echo d-quark_eta0.5_pT100`

cat ../${FILE}_template_cfg.py \
| sed -e s/CONDOR_OUTPUTFILENAME/${FILE}_${EXTENSION}/ \
| sed -e s/CONDOR_MAXEVENTS/4000/ \
| sed -e s/CONDOR_PID/1/ \
| sed -e s/CONDOR_ETA/0.5/ \
| sed -e s/CONDOR_PT/100/ \
| sed -e s/CONDOR_FWKREPORT/100/ \
> ${FILE}_${EXTENSION}_cfg.py

cat ../${FILE}_template.jdl \
| sed -e s/PREFIX_NAME/${FILE}_${EXTENSION}/ \
| sed -e s~RUN_DIR~/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata~ \
> ${FILE}_${EXTENSION}.jdl

condor_submit ${FILE}_${EXTENSION}.jdl
#==========================================================
echo ">> `/bin/date` SingleJet: d-quark, eta=0.5, pT=300 GeV"

EXTENSION=`echo d-quark_eta0.5_pT300`

cat ../${FILE}_template_cfg.py \
| sed -e s/CONDOR_OUTPUTFILENAME/${FILE}_${EXTENSION}/ \
| sed -e s/CONDOR_MAXEVENTS/4000/ \
| sed -e s/CONDOR_PID/1/ \
| sed -e s/CONDOR_ETA/0.5/ \
| sed -e s/CONDOR_PT/300/ \
| sed -e s/CONDOR_FWKREPORT/100/ \
> ${FILE}_${EXTENSION}_cfg.py

cat ../${FILE}_template.jdl \
| sed -e s/PREFIX_NAME/${FILE}_${EXTENSION}/ \
| sed -e s~RUN_DIR~/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata~ \
> ${FILE}_${EXTENSION}.jdl

condor_submit ${FILE}_${EXTENSION}.jdl
#==========================================================
echo ">> `/bin/date` SingleJet: d-quark, eta=0.5, pT=500 GeV"

EXTENSION=`echo d-quark_eta0.5_pT500`

cat ../${FILE}_template_cfg.py \
| sed -e s/CONDOR_OUTPUTFILENAME/${FILE}_${EXTENSION}/ \
| sed -e s/CONDOR_MAXEVENTS/4000/ \
| sed -e s/CONDOR_PID/1/ \
| sed -e s/CONDOR_ETA/0.5/ \
| sed -e s/CONDOR_PT/500/ \
| sed -e s/CONDOR_FWKREPORT/100/ \
> ${FILE}_${EXTENSION}_cfg.py

cat ../${FILE}_template.jdl \
| sed -e s/PREFIX_NAME/${FILE}_${EXTENSION}/ \
| sed -e s~RUN_DIR~/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata~ \
> ${FILE}_${EXTENSION}.jdl

condor_submit ${FILE}_${EXTENSION}.jdl
#==========================================================
echo ">> `/bin/date` SingleJet: d-quark, eta=0.5, pT=1000 GeV"

EXTENSION=`echo d-quark_eta0.5_pT1000`

cat ../${FILE}_template_cfg.py \
| sed -e s/CONDOR_OUTPUTFILENAME/${FILE}_${EXTENSION}/ \
| sed -e s/CONDOR_MAXEVENTS/4000/ \
| sed -e s/CONDOR_PID/1/ \
| sed -e s/CONDOR_ETA/0.5/ \
| sed -e s/CONDOR_PT/1000/ \
| sed -e s/CONDOR_FWKREPORT/100/ \
> ${FILE}_${EXTENSION}_cfg.py

cat ../${FILE}_template.jdl \
| sed -e s/PREFIX_NAME/${FILE}_${EXTENSION}/ \
| sed -e s~RUN_DIR~/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata~ \
> ${FILE}_${EXTENSION}.jdl

condor_submit ${FILE}_${EXTENSION}.jdl
#==========================================================
echo ">> `/bin/date` SingleJet: d-quark, eta=0.5, pT=2000 GeV"

EXTENSION=`echo d-quark_eta0.5_pT2000`

cat ../${FILE}_template_cfg.py \
| sed -e s/CONDOR_OUTPUTFILENAME/${FILE}_${EXTENSION}/ \
| sed -e s/CONDOR_MAXEVENTS/4000/ \
| sed -e s/CONDOR_PID/1/ \
| sed -e s/CONDOR_ETA/0.5/ \
| sed -e s/CONDOR_PT/2000/ \
| sed -e s/CONDOR_FWKREPORT/100/ \
> ${FILE}_${EXTENSION}_cfg.py

cat ../${FILE}_template.jdl \
| sed -e s/PREFIX_NAME/${FILE}_${EXTENSION}/ \
| sed -e s~RUN_DIR~/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata~ \
> ${FILE}_${EXTENSION}.jdl

condor_submit ${FILE}_${EXTENSION}.jdl
#==========================================================
echo ">> `/bin/date` SingleJet: d-quark, eta=0.5, pT=4000 GeV"

EXTENSION=`echo d-quark_eta0.5_pT4000`

cat ../${FILE}_template_cfg.py \
| sed -e s/CONDOR_OUTPUTFILENAME/${FILE}_${EXTENSION}/ \
| sed -e s/CONDOR_MAXEVENTS/4000/ \
| sed -e s/CONDOR_PID/1/ \
| sed -e s/CONDOR_ETA/0.5/ \
| sed -e s/CONDOR_PT/4000/ \
| sed -e s/CONDOR_FWKREPORT/100/ \
> ${FILE}_${EXTENSION}_cfg.py

cat ../${FILE}_template.jdl \
| sed -e s/PREFIX_NAME/${FILE}_${EXTENSION}/ \
| sed -e s~RUN_DIR~/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata~ \
> ${FILE}_${EXTENSION}.jdl

condor_submit ${FILE}_${EXTENSION}.jdl
#==========================================================
echo ">> `/bin/date` SingleJet: d-quark, eta=0.5, pT=7000 GeV"

EXTENSION=`echo d-quark_eta0.5_pT7000`

cat ../${FILE}_template_cfg.py \
| sed -e s/CONDOR_OUTPUTFILENAME/${FILE}_${EXTENSION}/ \
| sed -e s/CONDOR_MAXEVENTS/4000/ \
| sed -e s/CONDOR_PID/1/ \
| sed -e s/CONDOR_ETA/0.5/ \
| sed -e s/CONDOR_PT/7000/ \
| sed -e s/CONDOR_FWKREPORT/100/ \
> ${FILE}_${EXTENSION}_cfg.py

cat ../${FILE}_template.jdl \
| sed -e s/PREFIX_NAME/${FILE}_${EXTENSION}/ \
| sed -e s~RUN_DIR~/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata~ \
> ${FILE}_${EXTENSION}.jdl

condor_submit ${FILE}_${EXTENSION}.jdl
#==========================================================
#======================= eta=1.0 ==========================
#==========================================================
echo ">> `/bin/date` SingleJet: d-quark, eta=1.0, pT=50 GeV"

EXTENSION=`echo d-quark_eta1.0_pT50`

cat ../${FILE}_template_cfg.py \
| sed -e s/CONDOR_OUTPUTFILENAME/${FILE}_${EXTENSION}/ \
| sed -e s/CONDOR_MAXEVENTS/4000/ \
| sed -e s/CONDOR_PID/1/ \
| sed -e s/CONDOR_ETA/1.0/ \
| sed -e s/CONDOR_PT/50/ \
| sed -e s/CONDOR_FWKREPORT/100/ \
> ${FILE}_${EXTENSION}_cfg.py

cat ../${FILE}_template.jdl \
| sed -e s/PREFIX_NAME/${FILE}_${EXTENSION}/ \
| sed -e s~RUN_DIR~/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata~ \
> ${FILE}_${EXTENSION}.jdl

condor_submit ${FILE}_${EXTENSION}.jdl
#==========================================================
echo ">> `/bin/date` SingleJet: d-quark, eta=1.0, pT=100 GeV"

EXTENSION=`echo d-quark_eta1.0_pT100`

cat ../${FILE}_template_cfg.py \
| sed -e s/CONDOR_OUTPUTFILENAME/${FILE}_${EXTENSION}/ \
| sed -e s/CONDOR_MAXEVENTS/4000/ \
| sed -e s/CONDOR_PID/1/ \
| sed -e s/CONDOR_ETA/1.0/ \
| sed -e s/CONDOR_PT/100/ \
| sed -e s/CONDOR_FWKREPORT/100/ \
> ${FILE}_${EXTENSION}_cfg.py

cat ../${FILE}_template.jdl \
| sed -e s/PREFIX_NAME/${FILE}_${EXTENSION}/ \
| sed -e s~RUN_DIR~/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata~ \
> ${FILE}_${EXTENSION}.jdl

condor_submit ${FILE}_${EXTENSION}.jdl
#==========================================================
echo ">> `/bin/date` SingleJet: d-quark, eta=1.0, pT=300 GeV"

EXTENSION=`echo d-quark_eta1.0_pT300`

cat ../${FILE}_template_cfg.py \
| sed -e s/CONDOR_OUTPUTFILENAME/${FILE}_${EXTENSION}/ \
| sed -e s/CONDOR_MAXEVENTS/4000/ \
| sed -e s/CONDOR_PID/1/ \
| sed -e s/CONDOR_ETA/1.0/ \
| sed -e s/CONDOR_PT/300/ \
| sed -e s/CONDOR_FWKREPORT/100/ \
> ${FILE}_${EXTENSION}_cfg.py

cat ../${FILE}_template.jdl \
| sed -e s/PREFIX_NAME/${FILE}_${EXTENSION}/ \
| sed -e s~RUN_DIR~/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata~ \
> ${FILE}_${EXTENSION}.jdl

condor_submit ${FILE}_${EXTENSION}.jdl
#==========================================================
echo ">> `/bin/date` SingleJet: d-quark, eta=1.0, pT=500 GeV"

EXTENSION=`echo d-quark_eta1.0_pT500`

cat ../${FILE}_template_cfg.py \
| sed -e s/CONDOR_OUTPUTFILENAME/${FILE}_${EXTENSION}/ \
| sed -e s/CONDOR_MAXEVENTS/4000/ \
| sed -e s/CONDOR_PID/1/ \
| sed -e s/CONDOR_ETA/1.0/ \
| sed -e s/CONDOR_PT/500/ \
| sed -e s/CONDOR_FWKREPORT/100/ \
> ${FILE}_${EXTENSION}_cfg.py

cat ../${FILE}_template.jdl \
| sed -e s/PREFIX_NAME/${FILE}_${EXTENSION}/ \
| sed -e s~RUN_DIR~/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata~ \
> ${FILE}_${EXTENSION}.jdl

condor_submit ${FILE}_${EXTENSION}.jdl
#==========================================================
echo ">> `/bin/date` SingleJet: d-quark, eta=1.0, pT=1000 GeV"

EXTENSION=`echo d-quark_eta1.0_pT1000`

cat ../${FILE}_template_cfg.py \
| sed -e s/CONDOR_OUTPUTFILENAME/${FILE}_${EXTENSION}/ \
| sed -e s/CONDOR_MAXEVENTS/4000/ \
| sed -e s/CONDOR_PID/1/ \
| sed -e s/CONDOR_ETA/1.0/ \
| sed -e s/CONDOR_PT/1000/ \
| sed -e s/CONDOR_FWKREPORT/100/ \
> ${FILE}_${EXTENSION}_cfg.py

cat ../${FILE}_template.jdl \
| sed -e s/PREFIX_NAME/${FILE}_${EXTENSION}/ \
| sed -e s~RUN_DIR~/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata~ \
> ${FILE}_${EXTENSION}.jdl

condor_submit ${FILE}_${EXTENSION}.jdl
#==========================================================
echo ">> `/bin/date` SingleJet: d-quark, eta=1.0, pT=2000 GeV"

EXTENSION=`echo d-quark_eta1.0_pT2000`

cat ../${FILE}_template_cfg.py \
| sed -e s/CONDOR_OUTPUTFILENAME/${FILE}_${EXTENSION}/ \
| sed -e s/CONDOR_MAXEVENTS/4000/ \
| sed -e s/CONDOR_PID/1/ \
| sed -e s/CONDOR_ETA/1.0/ \
| sed -e s/CONDOR_PT/2000/ \
| sed -e s/CONDOR_FWKREPORT/100/ \
> ${FILE}_${EXTENSION}_cfg.py

cat ../${FILE}_template.jdl \
| sed -e s/PREFIX_NAME/${FILE}_${EXTENSION}/ \
| sed -e s~RUN_DIR~/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata~ \
> ${FILE}_${EXTENSION}.jdl

condor_submit ${FILE}_${EXTENSION}.jdl
#==========================================================
echo ">> `/bin/date` SingleJet: d-quark, eta=1.0, pT=4000 GeV"

EXTENSION=`echo d-quark_eta1.0_pT4000`

cat ../${FILE}_template_cfg.py \
| sed -e s/CONDOR_OUTPUTFILENAME/${FILE}_${EXTENSION}/ \
| sed -e s/CONDOR_MAXEVENTS/4000/ \
| sed -e s/CONDOR_PID/1/ \
| sed -e s/CONDOR_ETA/1.0/ \
| sed -e s/CONDOR_PT/4000/ \
| sed -e s/CONDOR_FWKREPORT/100/ \
> ${FILE}_${EXTENSION}_cfg.py

cat ../${FILE}_template.jdl \
| sed -e s/PREFIX_NAME/${FILE}_${EXTENSION}/ \
| sed -e s~RUN_DIR~/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata~ \
> ${FILE}_${EXTENSION}.jdl

condor_submit ${FILE}_${EXTENSION}.jdl
#==========================================================
echo ">> `/bin/date` SingleJet: d-quark, eta=1.0, pT=7000 GeV"

EXTENSION=`echo d-quark_eta1.0_pT7000`

cat ../${FILE}_template_cfg.py \
| sed -e s/CONDOR_OUTPUTFILENAME/${FILE}_${EXTENSION}/ \
| sed -e s/CONDOR_MAXEVENTS/4000/ \
| sed -e s/CONDOR_PID/1/ \
| sed -e s/CONDOR_ETA/1.0/ \
| sed -e s/CONDOR_PT/7000/ \
| sed -e s/CONDOR_FWKREPORT/100/ \
> ${FILE}_${EXTENSION}_cfg.py

cat ../${FILE}_template.jdl \
| sed -e s/PREFIX_NAME/${FILE}_${EXTENSION}/ \
| sed -e s~RUN_DIR~/data/users/ferencek/HO_Study/CMSSW_2_1_8/test/MCdata~ \
> ${FILE}_${EXTENSION}.jdl

condor_submit ${FILE}_${EXTENSION}.jdl
#==========================================================
echo ">> `/bin/date` Condor job(s) submitted successfully!"