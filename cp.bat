@echo off
cls
pushd week%1
g++ -std=c++14 %2.cpp -DDBG -o %2
if %ERRORLEVEL% EQU 0 (
	echo Complete.
	%2.exe < %2.in > %2.out
	echo END
)
popd