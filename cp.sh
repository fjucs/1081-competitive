#!/bin/bash
clear
pushd week$1/ >/dev/null
g++ -std=c++11 "$2".cpp -o "$2"
if [[ $? -eq 0 ]]; then
	echo Complete
	echo RUNNING
	./$2 < "$2.in" > "$2.out"
	echo END
	rm ./"$2"
fi
popd >/dev/null