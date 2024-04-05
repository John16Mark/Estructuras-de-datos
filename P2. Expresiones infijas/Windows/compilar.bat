@echo off
setlocal enabledelayedexpansion

REM aquí se puede modificar la variable a conveniencia
set "gcc_command=gcc src/main.c -o bin/main.exe"

set "source_dir=..\..\libs\TAD"
for %%f in ("%source_dir%\*.c") do (
    set "gcc_command=!gcc_command! "%%~f""
)

set "source_dir=..\..\libs\diseno"
for %%f in ("%source_dir%\*.c") do (
    set "gcc_command=!gcc_command! "%%~f""
)

cls
echo Compilando...
%gcc_command%