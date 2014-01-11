#include <avr/io.h>

int main(void) {
  // initialize the port for the LEDs
  DDRB = 0b00000001;
  PORTB = 0b00000000;


  /*
    How do we got 'CS12'?

    => Since there is one 16-bit Timer/counter, so the maximum TCNT1
    can count is 2^16 is 65536(actually 65535. Go ahead and give 'if
    (TCNT1 > 65535)', the led will never blink). Now ATmega32A has
    internal clock speed of 16MHz. Meaning 16000000 cycles per/Sec. So
    16000000/65536=244. This is a minimum prescaler value. No way we
    can go below this value. From the data sheet(pg 109) CS12 has a
    clk/256.
   */
  
  TCCR1B |= 1<<CS12;		/* prescaling of clk/256 */
  /*
    I'm not sure about which the timer clock control register is
    1B(TCCR1B)

    Solution: from data sheet
  */
  

  while (1) {
    if (TCNT1 > 65534) {	/* TCNT1: TimerCouNTer1 */
      TCNT1 = 0;		/* reset TCNT1 */
      PORTB ^= 1<<PINB0;	/* PINB0 to HIGH */
    }
  }
}

