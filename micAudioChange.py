#!/usr/bin/env python3
import numpy as np
import sounddevice as sd
from time import sleep
import mathd


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
        print(magSum)
    oldMagSum = magSum
         
with sd.InputStream(device = 0, channels=2, samplerate=samplerate, 
        callback = callback):
    sd.sleep(100*10000)
    
