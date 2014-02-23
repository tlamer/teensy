#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include "usb_debug_only.h"
#include "print.h"


/*	Teensy++ 2.0 onboard LED macros  */ 
#if defined(__AVR_AT90USB1286__)
#define LED_CONFIG	(DDRD |= (1<<6))
#define LED_ON		(PORTD |= (1<<6))
#define LED_OFF		(PORTD &= ~(1<<6))
#define LED_SWITCH  (PORTD ^= (1<<6))
#endif

#define CPU_PRESCALE(n)	(CLKPR = 0x80, CLKPR = (n))
#define CPU_16MHz       0x00
#define CPU_8MHz        0x01
#define CPU_4MHz        0x02
#define CPU_2MHz        0x03
#define CPU_1MHz        0x04
#define CPU_500kHz      0x05
#define CPU_250kHz      0x06
#define CPU_125kHz      0x07
#define CPU_62kHz       0x08


int main(void)
{

/*	set CPU to 16 MHz  */
	CPU_PRESCALE(CPU_16MHz);

/* 	initialize USB for debug messages.  */
	usb_init();

}

