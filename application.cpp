#include <avrio.h>
#include "uart_project.hpp"
#include "time_drive.hpp"

#define F_CPU 8000000

#define IN 0
#define OUT 1
#define LOW 0
#define HIGH 1


 void DIO_init(uint8_t pinNumber, uint8_t port, uint8_t direction);
 

 void DIO_write(uint8_t pinNumber, uint8_t port, uint8_t value);


 void DIO_read(uint8_t pinNumber, uint8_t port, uint8_t *value);

void main(void)
{
	SWUART_init( 9600);
	Init_Timer()
	
	while(1)
	{
		while((TIFR&0x01)==0);  /* Wait for TOV0 to roll over */
		SWUART_send('a');		/*send echo*/
		TIFR = 0x1;  		/* Clear TOV0 flag*/
	
		
	}
}

