

//Lightstrip Controller
//Adam Greig, 2008-06-04
//CC BY-SA-NC 3.0

#define F_CPU 1200000UL

#include <avr/interrupt.h>
#include <avr/delay.h>

//Converge - how fast the average will converge to the current value. Default: 10
#define CONVERGE 10
//Peak - what multiple of the average will be considered a peak. Default: 1.3
#define PEAK 1.3

int main() {
	
	//Initialise registers. Note that the compiler optimises each to an integer, so the 0s just make life easier.
	ADMUX	= (0<<REFS0)	| (1<<ADLAR)	| (1<<MUX1)	| (1<<MUX0);
	ADCSRA	= (1<<ADEN)	| (0<<ADSC)	| (0<<ADATE)	| (0<<ADIF)	| (0<<ADIE)	| (0<<ADPS2)	| (0<<ADPS1)	| (1<<ADPS0);
	DIDR0	= (0<<ADC0D)	| (0<<ADC1D)	| (0<<ADC2D )	| (1<<ADC3D);
	DDRB	= (0<<PB0)	| (0<<PB1)	| (0<<PB2)	| (0<<PB3)	| (1<<PB4);
	
	//Initialise ADC, ignore first result
	ADCSRA	|= (1<<ADSC);
	while( ADCSRA & (1<<ADSC) ) {}
	
	//Store duty cycle, background average, current result, difference between result and average.
	unsigned char duty;
	unsigned char avg;
	unsigned char result;
	signed char diff;
	
	//Main loop
	for( ;; ) {
		
		//Take a reading
		ADCSRA	|= (1<<ADSC);
		while( ADCSRA & (1<<ADSC) ) {}
		result	= ADCH;
		
		//Find the difference and converge the average
		diff = result - avg;
		avg += diff / CONVERGE;
		
		//Determine if it's a peak
		if( result > avg * PEAK )
			duty = (100*result)/avg;
		else
			duty = 0;
		
		//Execute the duty cycle
		if (duty != 0 )
			PORTB	= 1<<PB4;
		for( int j=0; j<duty; j++ )
			asm( "nop\n\t" "nop\n\t" "nop\n\t" :: );
		PORTB	= 0<<PB4;
		for( int j=100; j>duty; j-- )
			asm( "nop\n\t" "nop\n\t" "nop\n\t" :: );
	}
}


