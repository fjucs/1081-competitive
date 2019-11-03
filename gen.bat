@echo off
pushd week%1
type ..\template.cpp > %2.cpp
echo.>%2.in
echo.>%2.out
popd