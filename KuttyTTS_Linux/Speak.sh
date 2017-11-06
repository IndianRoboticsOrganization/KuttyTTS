#!/bin/bash

# KuttyTTS Tamil by Indian Robotics [Powered By IIT Madras Donlab's Indic TTS]
# =============================================================================
#
# Author : Vasanth Kumar (@jarvisvasu)
# Founder Of Indian Robotics Organization
# 
# Contact : indianroboticsorganization@gmail.com
#
# For more info : http://www.indianrobotics.org
#
# If You Like The Software, Hit A LIKE On Our Facebook Page
#
# Like Us On : http://facebook.com/indianrobotics/
#
# For any queries, feel free to contact us!
# Please post your feedbacks on facebook, It really means so much for us!
#



if (($# != 2)); then

echo "Usage : Speak.sh text [mode 0/1]"

else

text=$2

if (($1 == 0)); then

echo "Default Voice : naveen_tamil"
echo "Synthesizing : $text"
output=$(echo ${text} | ./KuttyTTS -m voices/naveen_tamil.htsvoice -o output/speech.wav)
echo "Speech generated : output/speech.wav"
output=$(aplay output/speech.wav)

elif (($1 == 1)); then

if [ -e ${text} ]; then
textdata=`cat ${text}`

echo "Default Voice : naveen_tamil"
echo "Synthesizing : $textdata"
output=$(echo ${textdata} | ./KuttyTTS -m voices/naveen_tamil.htsvoice -o output/speech.wav)
echo "Speech generated : output/speech.wav"
output=$(aplay output/speech.wav)
else

echo "File not found : $text"

fi

	
else
	echo "Invalid mode value"
	echo "Usage : ./Speak.sh [mode 0/1] [text/file]"
	echo "ON-THE-GO - ./Speak.sh 0 'வணக்கம்'"
	echo "READ-FILE - ./Speak.sh 1 text.txt"
fi


fi

