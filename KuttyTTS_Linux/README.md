KuttyTTS - Tamil Speech Synthesizer [Powered By IIT Madras - Donlab's Indic TTS Voices]
=======================================================================================

HOW-TO Build from sourcecode
****************************

Required tools : GCC

$ sudo apt-get install gcc

$ cd KuttyTTS

$ make

Now you should have the executable binary in src/KuttyTTS

Test the synthesizer by running the following command :

$ echo "வணக்கம்" | src/KuttyTTS -m voices/naveen_tamil.htsvoice -o output/speech.wav

*****************************************************************************

Tamil Text-To-Speech tool for linux (Command-Line | Console App).

This application is a clone of text to speech tool called flite_hts_tamil 
created by [mentamizh] (https://github.com/mentamizh/flite_hts_tamil)
which uses code from open source android app developed by [donlab]
(http://www.iitm.ac.in/donlab/tts/index.php)

Indian Robotics have added a simple script to generate speech from text effortlessly.

Theres also a windows version of KuttyTTS available from indianrobotics.org!

If you are a developer or wish to enhance this TTS,
Then checkout https://github.com/mentamizh/flite_hts_tamil


Minimum System Requirements
===========================

* Processor	Intel/AMD Single Core x86 (32Bit)
* RAM		512MB
* Disk Space	10MB

Credits
=======

IIT Madras, Department Of Computer Science for [donlab] (Indic TTS)
Mohan for [mentamizh] (flite_hts_tamil)

Usage
=============================================================================

First set execute permission to "Speak.sh"

	$ chmod +x ./Speak.sh

ON-THE-GO Mode
**************

Open your terminal & run the script as follows.

	$ Speak.sh 0 "வணக்கம்"

You should hear the synthesized speech on the go!

READFILE Mode
************

Open your terminal & run the script

	$ Speak.sh 1 text.txt

The text to be synthesized will be taken from the text.txt file.

The synthesized speech will be saved in output/speech.wav

You can play the synthesized speech using the command below

	$ aplay output/speech.wav

*********************************************************************************

For More Information :

Visit - www.indianrobotics.org

Please, feel free to contact us on indianroboticsorganization@gmail.com

If you like the application, Hit a like on our facebook page

Like Us On : http://facebook.com/indianrobotics/

Please post your feedbacks on facebook, it means so much to us.

Ideas
=====

You can now build your own Tamil Voice-Enabled Applications in C/C++/Python/Java for linux using this command line tool (KuttyTTS).

Example Python Code (KuttyTTS.py)
===================

import sys
import os

def speak(msg):
os.chdir('/home/indianrobotics/KuttyTTS')
speakCmd = "echo '"+msg+"' > kuttytts -m naveen_tamil.htsvoice -o output/speech.wav"
os.system(speakCmd)
os.system("aplay output/speech.wav")
return

speak("வணக்கம்")

Future :
========

* Graphincal User Interface Will Be Added
* A C Shared-library will be created
* Python & Java API through wrappers

Pros
=====

* Light Weight & Speed
* Easy To Install

Cons
=====

* Some speech processing problems & Letter-To-Sound rules should be fixed.
* Currently it has no intonation support, so sounds robotic.

Compiling from source :
=======================

To compile this application from source, just run

	$ make

