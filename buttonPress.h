/*
  Library for button de-bouncing.
*/
/* Avoid reload of this library */
#ifndef buttonPress
#define buttonPress

#include <avr/io.h>

/* Prototypes */
char ButtonPressed(int buttonNumber, unsigned char pinOfButton,
		   unsigned char portBit, int confidenceLevel);

char pressed[numberOfButtons];
int pressed_confidence_level[numberOfButtons]; /* Measured button press confidence */
int released_confidence_level[numberOfButtons]; /* Measured button release confidence */


char ButtonPressed(int buttonNumber, unsigned char pinOfButton,
		     unsigned char portBit, int confidenceLevel) {
  if (bit_is_clear(pinOfButton, portBit)) { /* Button is
					       pressed. PINB1 will have 0 volts
					       when button is pressed */
    
    pressed_confidence_level[buttonNumber] ++; /* Increase press confidence */
    released_confidence_level[buttonNumber] = 0; /* Reset 'released_confidence_level' since there is a button press */

    if (pressed_confidence_level[buttonNumber] > confidenceLevel) { /* Indicator of good button press */
  
      if (pressed[buttonNumber] == 0) {
	pressed[buttonNumber] = 1;
	return 1;
      }
      /* Reset it so that new pressed condition can be evaluated. */
      pressed_confidence_level[buttonNumber] = 0;
    }
  }
  else {
    /* button is not pressed */
    released_confidence_level[buttonNumber] ++; /* Works just like pressed */
    pressed_confidence_level[buttonNumber] = 0; /* Reset 'pressed_confidence_level' since there button is released */
 
    if (released_confidence_level[buttonNumber] > confidenceLevel) {
      pressed[buttonNumber] = 0;
      released_confidence_level[buttonNumber] = 0;
    }
  }
  return 0;
}

#endif


