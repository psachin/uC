#include <mh/mh-timer.c>

uint8_t csb = 2;		/* clock set bit */
uint8_t ocrval = 255;		/* Output compare register value */

int main()
{
	sqwave_tc0(csb, ocrval);
	return 0;
}
