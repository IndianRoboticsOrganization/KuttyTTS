KuttyTTS - Tamil Speech Synthesizer [Powered By IIT Madras - Donlab's Indic TTS Voices]
=======================================================================================

HOW-TO Build from sourcecode
****************************

Operating System : Linux

Required tools : MingW32

$ sudo apt-get install mingw32 mingw32-binutils mingw32-runtime wine

$ cd KuttyTTS

$ make

Now you should have the executable binary in src/KuttyTTS.exe

Test the synthesizer by running the following command :

$ echo "வணக்கம்" | src/KuttyTTS.exe -m voices/naveen_tamil.htsvoice -o output/speech.wav

*****************************************************************************

Tamil Text-To-Speech tool for windows (Command-Line | Console App).

This application is a windows port of linux command line text to speech tool called flite_hts_tamil.

where a linux version was created by [mentamizh] (https://github.com/mentamizh/flite_hts_tamil)
which uses code from open source android app developed by [donlab](http://www.iitm.ac.in/donlab/tts/index.php)

Indian Robotics ported the application to windows for Windows users/developers.

Theres also a linux version of KuttyTTS available from indianrobotics.org!

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
=====

1. Open "text.txt" file
2. Enter your tamil text & save in "UTF-8" Encoding.
3. Now Just Click "Speak.bat"
4. If The Program Executed Successfully. Check the generated speech audio in output/speech.wav

***************************************************************************************************************

For More Information :
======================

Visit - www.indianrobotics.org

Please, feel free to contact us on indianroboticsorganization@gmail.com

If you like the application, Hit a like on our facebook page

Like Us On : http://facebook.com/indianrobotics/

Please post your feedbacks on facebook, it means so much to us.

Ideas
=====

You can now build your own Tamil Voice-Enabled Applications in .Net/Other for windows using KuttyTTS.

Example C# Code
================

void SpeakTamil(string msg){

StreamWriter writetext = new StreamWriter("text.txt",false,Encoding.UTF-8)
writetext.WriteLine(msg);
writetext.close();
Process process = new Process();
process.StartInfo.FileName = "Speak.bat";
process.StartInfo.ErrorDialog = true;
process.StartInfo.CreateNoWindow = true;
process.Start();
process.WaitForExit(1000 * 60 * 5);
SoundPlayer simpleSound = new SoundPlayer("output\output.wav");
simpleSound.PlaySync();

}

Future :
========

* Graphincal User Interface Will Be Added
* A .Net (C#,VB,F#) Library Will Be Made Available for Wizards (Developers).

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

To compile this application from source, you can use MingW's C Compiler On Windows/Linux.

Thanks for using KuttyTTS - Indian Robotics!

