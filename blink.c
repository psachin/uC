#include <mh/mh-utils.c>

int main(void)
{
	DDRB = 0b00000111 ;		/* configure PB0,1,2 as output */
	PORTB = 0x00;			/* Keep all LEDs off */
	for (;;) {
		PORTB = 0b00000111;
		delay_ms(100);
		PORTB = 0b00000000; /* all off except PB2 */
		delay_ms(100);
	}
}
