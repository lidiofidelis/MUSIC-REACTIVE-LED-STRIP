#include <Arduino.h>

// the number of the RGB pins
const int redPin = 2;  // 2 corresponds to GPIO2
const int greenPin = 12;  // 12 corresponds to GPI12
const int bluePin = 13;  // 13 corresponds to GPI13

// setting PWM properties
const int freq = 5000;
const int redChannel = 0; //PWM Channel 0
const int greenChannel = 1; //PWM Channel 1
const int blueChannel = 2; //PWM Channel 2
const int resolution = 8; // 0 to 255


 
void setup(){
  // configure LED PWM functionalitites
  ledcSetup(redChannel, freq, resolution);
  ledcSetup(greenChannel, freq, resolution);
  ledcSetup(blueChannel, freq, resolution);
  
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(redPin, redChannel);
  ledcAttachPin(greenPin, greenChannel);
  ledcAttachPin(bluePin, blueChannel);
}
 
void loop(){
  // increase the LED strip color in gray scale
  for(int color = 0; color <= 255; color++){   
    // changing the LED strip color in gray scale
    ledcWrite(redChannel, color);
    ledcWrite(greenChannel, color);
    ledcWrite(blueChannel, color);
    delay(20);
  }

  // decrease the LED strip color in gray scale
  for(int color = 255; color >= 0; color--){
    // changing the LED strip color in gray scale
    ledcWrite(redChannel, color); 
    ledcWrite(greenChannel, color);
    ledcWrite(blueChannel, color);  
    delay(20);
  }
}