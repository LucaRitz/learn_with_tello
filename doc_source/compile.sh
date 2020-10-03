#!/usr/bin/env bash

rm -f /interface/output/*

find /miktex/work -type f -print0 | xargs -0 dos2unix --
cd /miktex/work/${LANGUAGE}

pdflatex -output-directory /interface/output learn_with_tello.tex
pdflatex -output-directory /interface/output learn_with_tello.tex
pdflatex -output-directory /interface/output learn_with_tello.tex