#!/bin/bash
outputfile=keymap.md
echo "Generating $outputfile"
grep -e '^\s*//' keymap.c | sed 's#//##' | tee "$outputfile"
