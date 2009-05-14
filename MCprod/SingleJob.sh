#!/bin/bash

CONDOR_CLUSTER=$1
CONDOR_PROCESS=$2
RUN_DIR=$3
PREFIX_NAME=$4

#
# header 
#

echo ""
echo "CMSSW on Condor"
echo ""

START_TIME=`/bin/date`
echo "started at $START_TIME"

echo ""
echo "parameter set:"
echo "CONDOR_CLUSTER: $CONDOR_CLUSTER"
echo "CONDOR_PROCESS: $CONDOR_PROCESS"
echo "RUN_DIR: $RUN_DIR"
echo "PARAMETER_SET: $PREFIX_NAME"

#
# setup software environment at FNAL for the given CMSSW release
#
export VO_CMS_SW_DIR=/software/cmssw
. $VO_CMS_SW_DIR/cmsset_default.sh
cd $RUN_DIR
eval `scramv1 runtime -sh`

#
# change to output directory
#
cd $RUN_DIR

#
# modify parameter-set
#

PARAMETER_SET=`echo ${PREFIX_NAME}_cfg.py`
LOG=`echo ${PREFIX_NAME}.log`

#
# run cmssw
#

echo "run: time cmsRun $PARAMETER_SET > $LOG 2>&1"
cmsRun $PARAMETER_SET >> $LOG 2>&1
exitcode=$?

#
# end run
#

echo ""
END_TIME=`/bin/date`
echo "finished at $END_TIME"
exit $exitcode