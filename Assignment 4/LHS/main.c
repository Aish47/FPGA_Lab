#include <avr/io.h>
#include <util/delay.h>
	
	unsigned char num ;                             //input number
	unsigned char A=0x00,B=0x00,C=0x00;	    //binary inputs
	unsigned char sev_seg[8] = {0x02, 0x9e, 0x24, 0x0c, 0x98, 0x48, 0x40, 0x1e};
	unsigned int lhs; 
	 
	int main (void)
	{
	 
	//set PB5 as output pin
	  DDRB    |= ((1 << DDB5));
	  DDRD	  |= 0xFE;
	//  PORTB = ((1 <<  PB5));
	  while (1) {
		for (num = 0x00; num<0x08; num++)               //loop to iterate through all usecases
	    	{
	        	A = num>>2;    B = num>>1;    C = num>>0;     //changing the inputs , D is LSB
	        	lhs = A&(~A|B)&C&(A|B);                          //Actual Boolean Function
			PORTD = sev_seg[num];
			
			if(lhs==1)
			{
			 PORTB = ((1 <<  PB5));
			}
			else
			{PORTB = ((0 << PB5));}
	    		_delay_ms(1000);
		}
	  }
	

	  /* . */
	  return 0;
	

	}
