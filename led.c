/* light up LED */
#include <avr/io.h>

#define numberOfButtons 2
#include "buttonPress.h"

int main(void) {

  DDRB = 0b00001100;
  PORTB = (1 << PINB0)|(1 << PINB1);

  while (1)
    {
      if (ButtonPressed(0, PINB, 0, 200)) PORTB ^= (1 << PINB2);
      if (ButtonPressed(1, PINB, 1, 200)) PORTB ^= (1 << PINB3);
    }
}


