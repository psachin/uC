# make file for /home/sachin/github/uC
# From: http://www.youtube.com/watch?v=wfQBS22jxL8&list=PLE72E4CFE73BD1DE1
# run as:
# make compile ARG="hello" or make ARG="hello" (to compile)
# make burn ARG="hello" (to burn)
# make clean ARG="hello" (to clean)

.PHONY: all clean compile burn

all: compile

compile:
	avr-gcc -Wall -O2 -mmcu=atmega32 -o ${ARG} ${ARG}.c
	avr-objcopy -j .text -j .data -O ihex ${ARG} ${ARG}.hex

burn:
	avrdude -b 19200 -P /dev/ttyUSB0 -pm32 -c stk500v1 -U flash:w:${ARG}.hex

clean:
	-rm -rvf *.hex
	-rm -rvf *.o *~
	-rm -rvf ${ARG}
