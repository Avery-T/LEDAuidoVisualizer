#!/usr/bin/env python3

import parselmouth 
import numpy
snd = parselmouth.Sound("./output0.wav")
pitch = snd.to_pitch()
pitch_values = pitch.selected_array['frequency']
print(pitch_values) 
