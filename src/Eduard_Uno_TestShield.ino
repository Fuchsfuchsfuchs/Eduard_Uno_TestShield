// Include Adafruit Neopixel
#include <Adafruit_NeoPixel.h>      // Necessary library to use the Adafruit Neopixels
#include <EasyNeoPixels.h>          // Include an easier way to select certain LEDs etc
#ifdef __AVR__
 #include <avr/power.h>             // Required for 16 MHz Adafruit Trinket
#endif

// Defines for Adafruit Neopixel
#define LED_PIN   6                 // Which pin on the Arduino is connected to the NeoPixels?
#define LED_COUNT 5                 // How many NeoPixels are attached to the Arduino?

#include "PinChangeInterrupt.h"

const int startPin = 2;
const int endPin = 12;


// Array to track pin changes
volatile bool pinChanged[endPin + 1] = {false};

// Forward declarations for interrupt service routines (ISRs) for each pin
void pin2ISR(); void pin3ISR(); void pin4ISR(); void pin5ISR(); void pin6ISR();
void pin7ISR(); void pin8ISR(); void pin9ISR(); void pin10ISR(); void pin11ISR(); void pin12ISR();

void setup() {

// Start serial connection
  Serial.begin(9600);

// Initialize NeoPixel Matrix
  setupEasyNeoPixels(LED_PIN, 25);
  
// All digital Pins set to Input (DDRx = 0)
  DDRB = 0x00;                      // Pins D8–D13
  DDRC = 0x00;                      // A0–A5
  DDRD = 0x00;                      // Pins D0–D7

// Deactivate internal Pull Up Resistors
  PORTB = 0x00;
  PORTC = 0x00;
  PORTD = 0x00; 

// Set up each pin as an input and attach interrupts
  pinMode(2, INPUT);  attachPinChangeInterrupt(2, pin2ISR, CHANGE);
  pinMode(3, INPUT);  attachPinChangeInterrupt(3, pin3ISR, CHANGE);
  pinMode(4, INPUT);  attachPinChangeInterrupt(4, pin4ISR, CHANGE);
  pinMode(5, INPUT);  attachPinChangeInterrupt(5, pin5ISR, CHANGE);
  pinMode(6, INPUT);  attachPinChangeInterrupt(6, pin6ISR, CHANGE);
  pinMode(7, INPUT);  attachPinChangeInterrupt(7, pin7ISR, CHANGE);
  pinMode(8, INPUT);  attachPinChangeInterrupt(8, pin8ISR, CHANGE);
  pinMode(9, INPUT);  attachPinChangeInterrupt(9, pin9ISR, CHANGE);
  pinMode(10, INPUT); attachPinChangeInterrupt(10, pin10ISR, CHANGE);
  pinMode(11, INPUT); attachPinChangeInterrupt(11, pin11ISR, CHANGE);
  pinMode(12, INPUT); attachPinChangeInterrupt(12, pin12ISR, CHANGE);

}

void loop() {
   // Check each pin for changes and print its current state
  for (int pin = startPin; pin <= endPin; pin++) {
    if (pinChanged[pin]) {
      // pinChanged[pin] = false;  // Reset the change flag
      int val = digitalRead(pin);  // Read the pin state
      Serial.print("Pin ");
      Serial.print(pin);
      Serial.print(" changed to ");
      Serial.println(val == HIGH ? "HIGH" : "LOW");

      writeEasyNeoPixel(pin, 0, 255, 0);    // Set neopixel corresponding to pin to green
    }
  }
}

// Interrupt service routines (ISRs) for each pin
void pin2ISR()  { pinChanged[2] = true; }
void pin3ISR()  { pinChanged[3] = true; }
void pin4ISR()  { pinChanged[4] = true; }
void pin5ISR()  { pinChanged[5] = true; }
void pin6ISR()  { pinChanged[6] = true; }
void pin7ISR()  { pinChanged[7] = true; }
void pin8ISR()  { pinChanged[8] = true; }
void pin9ISR()  { pinChanged[9] = true; }
void pin10ISR() { pinChanged[10] = true; }
void pin11ISR() { pinChanged[11] = true; }
void pin12ISR() { pinChanged[12] = true; }
