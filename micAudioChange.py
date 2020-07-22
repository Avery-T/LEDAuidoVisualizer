#!/usr/bin/env python3
import numpy as np
import sounddevice as sd
import math
import serial
import struct
from time import sleep


ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)
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
    magSum = np.sum(magnitude)
    if(magSum > oldMagSum):
        #writes the number to the arduino, and packs it into bytes
       ser.write(struct.pack('<f', round(magSum)))
    oldMagSum = magSum
         
with sd.InputStream(device = 0, channels=2, samplerate=samplerate, 
        callback = callback):
    sd.sleep(100*10000)
    
