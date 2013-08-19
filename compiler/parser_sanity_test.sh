#!/bin/bash

TOTAL=0
PASSED=0
for file in ./tests/assets/*.hex
do
	let TOTAL++
	./parser_stub.out $file
	if [ $? -eq 0 ]; then
		let PASSED++
	fi
done

if [ $TOTAL -eq $PASSED ]
	then
		echo -e "\n\033[00;32m $PASSED/$TOTAL passed.\033[0m\n"
	else
		echo -e "\n\033[00;31m $PASSED/$TOTAL passed.\033[0m\n"
fi
