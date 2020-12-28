#define F_CPU	8000000UL
#define BAUD	9600
#define BRC	((F_CPU/16/BAUD)-1)
#include <util/setbaud.h>
#include <avr/io.h>
#include <stdio.h>
#include "uart.h"
#include <util/delay.h>

int main(void)
{
	uart_init();

	while(1){
		USART_TX('a');
		_delay_ms(200);
	}


	return 0;
}

