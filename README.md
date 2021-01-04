# LEDAuidoVisualizer
## About
This code visualizes audio captured from a USB microphone. 
The Python script connects to the USB microphone and checks whether 
a given sample of audio is louder than the prior sample. 
The Python script then sends input to the Arduino via serial port. The  
Arduino then displays a led of a defined color across 
the led strip connected to it for every input it gets from the Python script.

## What is needed 
 - Python3
 - USB microphone
 - Arduino (connected to your computer) 
 - FastLED (Arduino Library) compatible LED Strip
 
## Guide to installing python sounddevice on Raspberry Pi
 - sudo apt install libffi-dev
 - sudo apt-get install libatlas-base-dev
 - sudo apt-get install libportaudio2
 - pip install cffi
 - pip install sounddevice


 

