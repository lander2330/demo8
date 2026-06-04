// Sketch: demo8.ino
// Version: Version 2026.06.04
// Author: Larry Anderson
//
// This ESP32 microcontroller project shows how to use 2 of its
// digital pins to represent from 1 to 4 different hardware configurations.
// I used this when I put together 4 independent ESP32 temperature
// transmitters placed in 4 different locations at my home.
// I wanted to use the same sketch in all 4 ESP32s and have the sketch
// determine the digital pin wiring to identify which ESP32 is transmitting
// its temperature readings.
//
// In this sketch, when the ESP32s are powered on, the pinMode INPUT_PULLUP is used
// to force 3.3v on both pins 0 and pin 1 to avoid any possible random 
// erroneous voltage reading.
// 
// Wiring ground (0v) to an input pin will override the pinMode INPUT_PULLUP
// because the direct wire creates a short low resistance path that 
// easily overpowers the weak high-resistance pull-up.
//
// For simplicity, this sketch only includes the relevant statements
// that test the ESP32's digital pins 0 and pin 1 to identify
// which of the 4 ESP32's is running the current sketch.
//
// In the full programmed sketch, not shown here, the location and 
// temperature information from the four different ESP32 transmitter units are
// transmitted to a 5th ESP32 that hosts a web site that can be
// viewed by a mobile device such as a cell phone, tablet, laptop or
// desktop to see the ESP32 locations and temperature information summarized
// into a single web page display. That sketch will be
// demonstrated and explained in a future video.

#define PIN0 0
#define PIN1 1
char location[10+1];

void setup()
  {
  pinMode(PIN0, INPUT_PULLUP);                                          // HIGH 3.3v
  pinMode(PIN1, INPUT_PULLUP);                                          // HIGH 3.3v

  // if pin0 is wired to ground and pin1 is not wired to ground
  if ((digitalRead(PIN0) == LOW) && (digitalRead(PIN1) == HIGH))        // 0v 3.3v
    strcpy(location, "Location 1");
  // else if pin0 is not wired to ground and pin1 is wired to ground
  else if ((digitalRead(PIN0) == HIGH) && (digitalRead(PIN1) == LOW))   // 3.3v 0v
    strcpy(location, "Location 2");
  // else if both pin0 is wired to ground and pin1 is wired to ground
  else if ((digitalRead(PIN0) == LOW) && (digitalRead(PIN1) == LOW))    // 0v 0v
    strcpy(location, "Location 3");
  // else neither pin0 or pin1 is wired to ground
  else                                                                  // 3.3v 3.3v
    strcpy(location, "Location 4");
  }

void loop()
  {
  }

// these statements show my software development environment
// Microsoft Windows 11 
// Arduino IDE 2.3.6
// Board: ESP32C6 Dev Module (specifically Espressif Systems ESP32-C6-DEVKITC-1-N8 Microcontroller)  