/*
 * GccApplication1.cpp
 *
 * Created: 22-Jan-18 9:24:41 PM
 * Author : Toshiba
 */ 
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "uart.h"


void uart_init(void);
void uart_transmit(char);


int main(void){
	uart0_init(UART_BAUD_SELECT(9600,F_CPU));
	uart0_puts("hELLO WORLD\n");