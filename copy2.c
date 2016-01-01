/* Reads the voltage level at PA0(PIN 0 of PORT A) and sets the same on PB0 */
#include <avr/io.h>
#include <mh/mh-digital.c>

int main(void)
{
	uint8_t val;
	DDRA = 0;		/* Data Direction Register. Port A as input */
	PORTA = 1;		/* Enable pullup on PORTA, bit 0 */
	DDRB = 1;		/* PB0 as output */

	for (;;) {
		val = GETBIT(PORTA, 0);

		if (val != 0) {
			SETBIT(PORTB, 0);
		} else {
			CLRBIT(PORTB, 0);
		}
	}
}
