/* light up LED */
#include <avr/io.h>
#define F_CPU 1000000		/* I don't know the bast value, but
				   the LED flashes */
#include <util/delay.h>
#include <avr/interrupt.h>



void main(void) {
  /* DDR: Data direction register. It tells the uC whether to make a
     port input or output. We'll make PORT B as o/p */

  /* set DDRB to its previous value OR make PORT B(PIN 0) as o/p */
  // DDRB |= 0b00000001;		/* last digit is for PIN 0 */
  /* if I want to make PIN 2 as output the notation would be
     0b00000100 */


  /* or another way is */
  DDRB |= 1 << PINB0;		/* (OR operator)assign PIN0(of PORTB)
				   as 1. PINB0 has reference in 'io.h'
				   file */
  PORTB ^= 1 << PINB0;		/* Toggling only PIN0 of PORTB */
  DDRB |= 1 << PINB2;		/* Set direction for output on PINB2 */

  DDRB &= ~(1 << PINB1);	/* DDR input PINB1 */
  PORTB |= 1 << PINB1;		/* set PINB1 to HIGH */

  int pressed = 0;
  int pressed_confidence_level = 0;
  int released_confidence_level = 0;
  // 00000000000000010101000111111111111110101010000000000000000000010101011111111111111111111111
  while (1) {
    /* never ending loop. */
    if (bit_is_clear(PINB, 1)) {
      /* button is pressed */
      pressed_confidence_level ++;
      if (pressed_confidence_level > 200) {
	
	if (pressed == 0) {
	  PORTB ^= 1 << PORTB0;
	  PORTB ^= 1 << PORTB2;
	  pressed = 1;
	}
	pressed_confidence_level = 0;
      }
    }
    else {
      /* button is not pressed */
      released_confidence_level ++;
      if (released_confidence_level > 200) {
	pressed = 0;
	released_confidence_level = 0;
      }
    }
  }
}


