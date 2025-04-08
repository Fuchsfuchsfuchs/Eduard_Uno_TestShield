//  Hehe Armadillo hehe
//
//      ,::////;::-.
//     /:'///// ``::>/|/
//   .',  ||||    `/( e\
//-==~-'`-Xm````-mm-' `-_\ 
//
//  Eduard BreakoutShieldTest Testboard Polling Version


#include <EasyNeoPixels.h>          // Include an easier way to select certain LEDs etc

#define LED_PIN 13
#define LED_COUNT 25

void setup() {
  
  
// All digital Pins set to Input (DDRx = 0)
  DDRB = 0x00;                      // Pins D8–D13
  DDRC = 0x00;                      // A0–A5
  DDRD = 0x00;                      // Pins D0–D7

// Deactivate internal Pull Up Resistors
  PORTB = 0x00;
  PORTC = 0x00;
  PORTD = 0x00; 

// Initialize NeoPixel Matrix
  setupEasyNeoPixels(LED_PIN, LED_COUNT);

// Set all Neopixel to red

  for(int i = 0; i < 26; i++){
      writeEasyNeoPixel(i, 16, 0, 0);
    }

  writeEasyNeoPixel(0, 0, 0, 16);
  writeEasyNeoPixel(1, 0, 0, 16);

  delay(3000);
}

void loop() {
  
  for(int pin = 2; pin < 19; pin++){
    delay(20);
    if(digitalRead(pin) == HIGH){
      writeEasyNeoPixel(pin, 0, 16, 0);
    }else{
      writeEasyNeoPixel(pin, 16, 0, 0);
    }
  }
}
