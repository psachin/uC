/* light up LED */
#include <avr/io.h>
#define F_CPU 1000000		/* I don't know the bast value, but
				   the LED flashes */
#include <util/delay.h>



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

  DDRB &= ~(1 << PINB1);	/* DDR input PINB1 */
  PORTB |= 1 << PINB1;		/* set PINB1 to HIGH */

  while (1) {
    /* never ending loop. */
    PORTB ^= 1 << PINB0;		/* '^' is X-OR operation
					   which will flip PIN0 to 1
					   and 0 */

    if (bit_is_clear(PINB, 1)) {
      /* button is pressed */
      _delay_ms(10000);
    }
    else {
      /* button is not pressed */
      _delay_ms(1000);			/* delay 100 milli seconds */
    }
  }
}


