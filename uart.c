#include <avr/io.h>
#include <stdio.h>

#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#ifndef BAUD
#define BAUD 9600
#endif
#include <util/setbaud.h>

/* http://www.cs.mun.ca/~rod/Winter2007/4723/notes/serial/serial.html */

void uart_init(void) {
	UBRRH = UBRRH_VALUE;
	UBRRL = UBRRL_VALUE;
	

	UCSRA &= ~(1<<U2X);
	UCSRB = (1<<RXEN) | (1<<TXEN);
	UCSRC = (1<<URSEL) | (3<<UCSZ0);
}

void uart_putchar(char c, FILE *stream) {
	if (c == '\n') {
		uart_putchar('\r', stream);
	}
	loop_until_bit_is_set(UCSRA, UDRE);
	UDR = c;
}

char uart_getchar(FILE *stream) {
	loop_until_bit_is_set(UCSRA, RXC);
	return UDR;
}

void USART_TX(unsigned char c){
	while( !(UCSRA & (1<<UDRE)) );
	UDR = c;
}
