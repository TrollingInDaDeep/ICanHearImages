# ICanHearImages

My first visual synth project.
Starts off by just plugging my audio synth into the r, g or b cable of a VGA cable.

Laptop -> VGA Cable -> Breadboard -> VGA Cable -> Monitor
on the breadboard break out following pins with dupont cables:
* Blue *Pin 3*
* Green *Pin 2*
* Red *Pin 1*
* HSync *Pin 13*
* VSync *Pin 14*
* GND *Pin 10*

The pins HSync, VSync and GND can just be patched to the 2nd VGA cable.
Red, Green and Blue can be used for fun modifications.

* Disconnect one of them to get different color of your image
* Add in Potentiometers to change the Color intensity
* connect an audio source. + wire to a color, GND to GND. with a stereo cable you can also connect right channel and left channel to different colors.
  A square wave will create sharp horizontal bars. Low frequency = less bars. If you hit the exact frequency, the bar will be still on the image. Saw waves will be sharp on one end and soft on the other.
  you can see visual representation of effects like chorus or delay.

Next step would be to create vertical bars. for that you need a very high frequency (ca. 145Khz) It could be possible with arduino UNO but I failed to do it.
It can theoretically do the frequency, but it didn't really work on my monitor. Maybe the Monitor was the issue.

