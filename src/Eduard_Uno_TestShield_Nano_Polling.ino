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

// ==== INPUT PINS ====

  // PORTC (A0–A5 = PC0–PC5) als Input
  DDRC &= ~0b00111111;  // PC0–PC5 (A0–A5) als Input
  PORTC &= ~0b00111111; // Kein Pullup

  // PORTD (D1–D6 = PD1–PD6) als Input
  DDRD &= ~0b11111110;  // PD1–PD6 als Input (lassen PD0 in Ruhe)
  PORTD &= ~0b11111110; // Kein Pullup an PD1–PD6

  // ==== OUTPUT PINS ====

  // PORTD: D7 = PD7
  DDRD |= (1 << PD7);   // PD7 als Output
  PORTD &= ~(1 << PD7); // LOW

  // PORTB: D8–D12 = PB0–PB4
  DDRB |= 0b00011111;   // PB0–PB4 als Output
  PORTB &= ~0b00011111; // Alle LOW

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

    // Schritt 1 

   // D7 = PD7 auf HIGH
  PORTD |= (1 << PD7);

  // D8–D12 = PB0–PB4 auf HIGH
  PORTB |= 0b00011111;

    // Schritt 2 Warten auf Antwort von IoT Board

  // Warte solange, bis alle 6 Pins HIGH sind
  while ((PINC & 0b00111111) != 0b00111111) {
    
    // TODO Neopixel Einbindung!!!!
    
    }

    // Schritt 3 

  for(int pin = 1; pin < 6; pin++){
     delay(20);
    if(digitalRead(pin) == HIGH){
      writeEasyNeoPixel(pin, 0, 16, 0);
    }else{
      writeEasyNeoPixel(pin, 16, 0, 0);
    }
  }
}
