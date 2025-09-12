#include <Audio.h>
#include "MyDsp.h"

MyDsp myDsp;
AudioOutputI2S out;
AudioControlSGTL5000 audioShield;
AudioConnection patchCord0(myDsp,0,out,0);
AudioConnection patchCord1(myDsp,0,out,1);

float freqs[] = {101,202,303,404,505};
int cnt = 0;

void setup() {
  AudioMemory(2);
  audioShield.enable();
  audioShield.volume(0.5);
}

void loop() {
  myDsp.setFreq(freqs[cnt]);
  cnt = (cnt+1)%5;
  delay(1000);
}
