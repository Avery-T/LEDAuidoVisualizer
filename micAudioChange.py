#!/usr/bin/env python3
import numpy as np
import sounddevice as sd
import math
import serial
import struct
import os 
from time import sleep

#attemps to find the device idof the pulleged in arduino
arduinoCheck = os.popen("find /dev/ttyACM*") 
arduino = arduinoCheck.readlines()
arduino = arduino[0] 
arduino = arduino[:-1] #last two characters are not in the path
#if arduino is not found manually type in path
ser = serial.Serial(arduino, 9600, timeout=0)
ser.flush()
outdata = np.array([])
samplerate = 44100
high = 4000
low = 100
delta_f = (high -low)
fftsize = math.ceil(samplerate / delta_f)
low_bin = math.floor(low/delta_f)
oldMagSum = 0 

def callback(indata,frames, time, status):
    global oldMagSum
    magnitude = np.abs(np.fft.rfft(indata[:, 0], n=fftsize))
    magSum = round(np.sum(magnitude)) 
    #writes the number to the arduino, and packs it into bytes
    ser.write(struct.pack('<f', magSum))
    oldMagSum = magSum
    print(magSum)
         
with sd.InputStream(device = 0, channels=2, samplerate=samplerate, 
        callback = callback):
    sd.sleep(100*10000)
