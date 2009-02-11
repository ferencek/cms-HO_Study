echo "`/bin/date` >> Starting job(s) on $HOST"
echo "`/bin/date` >> Running: cmsRun hoStudy_eta0.1_cfg.py >& hoStudy_eta0.1.log"
echo "..."
cmsRun hoStudy_eta0.1_cfg.py >& hoStudy_eta0.1.log
echo "`/bin/date` >> Running: cmsRun hoStudy_eta0.5_cfg.py >& hoStudy_eta0.5.log"
echo "..."
cmsRun hoStudy_eta0.5_cfg.py >& hoStudy_eta0.5.log
echo "`/bin/date` >> Running: cmsRun hoStudy_eta1.0_cfg.py >& hoStudy_eta1.0.log"
echo "..."
cmsRun hoStudy_eta1.0_cfg.py >& hoStudy_eta1.0.log
echo "`/bin/date` >> Job(s) completed!"