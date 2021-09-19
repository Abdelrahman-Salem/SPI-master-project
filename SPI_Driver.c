/*
 * SPI_Driver.c
 *
 * Created: 13/12/2020 15:30:07
 *  Author: 20114
 */ 
 
#include "SPI.h"

#define F_CPU 8000000
#include <util/delay.h>

#include <avr/io.h>

int main(void)
{
	uint8 tx_data=1;
	uint8 rec_data=0;
	
	DIO_SET_BIN_DIR(DIO_PORTA,DIO_PIN0,DIO_BIN_OUTPUT);
	
	SPI_master_init();
	SPI_master_init_trans();
	_delay_ms(1000);
	
	
    while(1)
    {
		rec_data=SPI_master_transiver(tx_data);
		if(rec_data==2)
		{
			DIO_TOGGLE_BIN(DIO_PORTA,DIO_PIN0);
			rec_data=0;
		}			
		_delay_ms(1000); 
    }
}