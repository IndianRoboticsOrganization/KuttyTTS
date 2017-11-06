@echo off
title KuttyTTS - Tamil Speech Synthesizer - Indian Robotics
set NLM=^
set NL=^^^%NLM%%NLM%^%NLM%%NLM%
KuttyTTS.exe -m voices\naveen_tamil.htsvoice -o output\speech.wav < text.txt
echo.
echo.
echo For more information : www.indianrobotics.org
echo. 
echo Contact : indianroboticsorganization@gmail.com 
echo. 
echo Speech Generated : output\output.wav
echo. 
pause

