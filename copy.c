/* Reads the voltage level at PA0(PIN 0 of PORT A) and sets the same on PB0 */
#include <avr/io.h>

int main(void)
{
	DDRA = 0;		/* Data Direction Register. Port A as input */
	PORTA = 1;		/* Enable pullup on PORTA, bit 0 */
	DDRB = 1;		/* PB0 as output */

	for (;;) {
		PORTB = PINA;
	}
}
