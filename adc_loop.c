#include <mh/mh-lcd.c>
#include <mh/mh-adc.c>
#include <mh/mh-utils.c>

main()
{
	uint16_t data;
	lcd_init();
	adc_enable();

	DDRB = 1;

	for (;;) {
		data = read_adc(0);
		lcd_clear();
		if (data == 1023) {
			PORTB = 1;
			lcd_put_int(data);
			delay_ms(100);
		} else {
			lcd_put_int(data);
			delay_ms(100);
		}
		PORTB = 0;
	}
}
