@echo off

set "comando_ejecucion=bin\main.exe"
set argumento="23+78.1*C-D"
REM set argumento="2+C*A/(B+5)"
REM set argumento="2+4*2/7"

%comando_ejecucion% %argumento%