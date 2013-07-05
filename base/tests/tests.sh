#!/bin/sh

# make all

for file in ./*.test
do
	$file
	echo '\n'
done