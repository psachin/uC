/* light up LED */
#include <avr/io.h>

void main(void) {
  /* DDR: Data direction register. It tells the uC whether to make a
     port input or outoup. We ll make PORT B as o/p */
  DDRB = 0b00000001;		/* last digit is for PIN 0 */
    /* if I want to make PIN 2 as output the notation would be
       0b00000100 */
  PORTB = 0b00000001;		/* put PIN 1 of PORT B to HIGH(5 volt) */

  while (1) {
    /* never ending loop. */
  }
  
}


