/*
 * baudrate: is an input argument that describes baudrate that the UART needs to make the communications.
 */
 void SWUART_init(uint32_t baudrate);

/*
 * data: is an input argument that describes a byte of data to be send over the SW UART.
 */
 void SWUART_send(uint8_t data);
 
 /*
 * data: is an output argument that describes a byte of data to be recieved by the SW UART.
 */
 void SWUART_recieve(uint8_t *data);


 void SWUART_init(uint32_t baudrate);
 {
	UBRRH = (baudrate>>8);                      // shift the register right by 8 bits
	UBRRL = baudrate;                           // set baud rate
	UCSRB = (1<<TXEN)|(1<<RXEN);
	UCSRC = (1<<URSEL)| (1<<UCSZ1)|(1<<UCSZ0) | (UPM1); // 8bit data format with parity
 }
 
 
 void SWUART_send(uint8_t data);
 {
 	/* Wait for empty transmit buffer */
	while ( !( UCSRA & (1<<UDRE)) );  // check trans
	UDR = data;
 }

 void SWUART_recieve(uint8_t *data);
 {
	while ( !(UCSRA & (1<<RXC)) );
	*data = UDR;
 }
