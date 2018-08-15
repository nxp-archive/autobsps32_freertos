REM
REM Copyright 2018 NXP
REM

if defined T32SYS_PPC (SET T32_PATH=%T32SYS_PPC%) else (SET T32_PATH=)
start %T32_PATH%\bin\windows64\t32mppc.exe -c .\config.t32,mpc5777c.cmm 20001 e200z7 USB CORE=1 %T32_PATH%

