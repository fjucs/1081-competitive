#!/bin/bash

mkdir week$1/ &> /dev/null
pushd week$1/ &>/dev/null

cat ../template.cpp > $2.cpp
echo -n >$2.in
echo -n >$2.out
echo week$1/$2 created

popd &>/dev/null