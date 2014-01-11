#include <avr/io.h>
#include <avr/interrupt.h>

int main(void) {
  sei();			/* Global interrupt */

  DDRB |= 1<<PINB0;

  /* TCCR: Timer Counter Control Register */
  TCCR1B |= 1 << CS12 | 1<<WGM12; /* WGM: WavaformGenerationMode. 1=> 16
				     bits. 2 => that we have more that
				     one WGM */
  TIMSK |= 1<<OCIE1A;			/* TIMSK: Timer/Counter
					   Interrupt Mask Register */
  OCR1A = 15624;

  /* OCIE1A: Output Compare A Interrupt Enable */
  while (1) {
    /* Never ending loop. */
  }
}

ISR(TIMER1_COMPA_vect) {
  PORTB ^= 1<<PINB0;
}

