#include <avr/io.h>
#include <avr/interrupt.h>
unsigned char memoria = 0;

ISR(TIMER0_OVF_vect){
	
	TCNT0 = 12;
	memoria ++;
	
	if(memoria == 2) {
		memoria = 0;
		
	  if((PINC&(1<<PC0))==0) {
			PORTC |= (1<<PC0);
		}
			else{
				PORTC &=~(1<<PC0);
			}
	 }
  }

int main(void)
{
    
	DDRC = 0b00000001;
	TCCR0 = 0b00000101;
	TCNT0 = 12;
	TIMSK |= 1;
	sei();
		
    while (1) {}
}

