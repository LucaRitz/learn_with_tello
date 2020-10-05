#!/bin/sh

rm -f /interface/output/*

find /source -type f -print0 | xargs -0 dos2unix --
cd /source/${LANGUAGE}

for d in */ ; do
    mkdir /interface/output/$d
done

pdflatex -output-directory /interface/output learn_with_tello.tex
biber /interface/output/learn_with_tello.bcf
pdflatex -output-directory /interface/output learn_with_tello.tex
pdflatex -output-directory /interface/output learn_with_tello.tex