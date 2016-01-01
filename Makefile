# Makefile for /home/sachin/github/uC
# From: http://www.youtube.com/watch?v=wfQBS22jxL8&list=PLE72E4CFE73BD1DE1
#
# Run as:
# make (to compile)
# make burn (to burn)
# make clean (to clean)

.PHONY: all clean compile burn

BINARY = echo
TTY = ttyUSB0

SRCS := $(wildcard *.c)
BINS := $(SRCS:%.c=%)

all: compile

compile:
	avr-gcc -Wall -O2 -mmcu=atmega32 -Wl,-Map,${BINARY}.map -o ${BINARY} ${BINARY}.c
	avr-objcopy -j .text -j .data -O ihex ${BINARY} ${BINARY}.hex
	avr-objdump -S ${BINARY} > ${BINARY}.lst

burn:
	avrdude -v -v -v -v -b 19200 -P /dev/${TTY} -pm32 -c stk500v1 -U flash:w:${BINARY}.hex

clean:
	-rm -rvf *.hex
	-rm -rvf *.o *~
	-rm -rvf *.map *.lst
	-rm -rvf ${BINS}
