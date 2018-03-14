/*
     3
    ###
8 #  6  # 7
    ###
4 #  5  #  1
    ###  # 2

*/

#include <avr/io.h>
#include <util/delay.h>

int main(void){
  char i;
  int arr[10] = {
    0b11011101,
    0b01000001,
    0b01111100,
    0b01110101,
    0b11100001,
    0b10110101,
    0b10111101,
    0b01000101,
    0b11111101,
    0b11110101,
  };

  DDRD = 0b11111100;
  DDRB = 0b00000011;

  for(;;){
    /*
    for(i = 2; i < 8; i++){
      //PORTD &= 1 << (8 - i);    // reset previous pin
      PORTD ^= 1 << i;    // toggle the LED
      _delay_ms(1000);
      PORTD ^= 1 << i;
    }
    for(i = 0; i < 2; i++){
      //PORTB &= 1 << (8 - i);    // reset previous pin
      PORTB ^= 1 << i;    // toggle the LED
      _delay_ms(1000);
      PORTB ^= 1 << i;
    }
    */

    for(i = 0; i < 10; i++){
      PORTD = arr[i] << 2;
      PORTB = arr[i] >> 6;
      _delay_ms(1000);
      PORTB = 0;
    }
  }
  return 0;
}


