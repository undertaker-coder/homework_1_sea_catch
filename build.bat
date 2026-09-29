@echo off
setlocal

set "VSDEVCMD=C:\BuildTools\Common7\Tools\VsDevCmd.bat"
if not exist "%VSDEVCMD%" (
    echo Visual Studio Build Tools was not found at C:\BuildTools.
    exit /b 1
)

call "%VSDEVCMD%" -arch=x64 >nul
if errorlevel 1 exit /b %errorlevel%

cl.exe /nologo /std:c++17 /EHsc /W4 /utf-8 dates_judging.cpp /Fe:dates_judging.exe
exit /b %errorlevel%
