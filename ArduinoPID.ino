#include "PID.h"
#include <stdint.h>


//This PID model assumes no differentiation
//and also assumes that the desired reference
//directly (1 to 1) correlates with the value
//being measured

PID mypid = PID(1, 0.1, 0.0);

//sensor variable for tracking values
int sensorVal = 0;
int motorOutput = 0;

enum{
	NOT_TRACKING = 0,
	TRACKING
};

uint8_t state = NOT_TRACKING;

void setup()
{
	//read the sensor for present value
	mypid.setTarget(25); 
	sensorVal = 0;
}

void loop()
{
	
	//if a specific button pressed
	if(digitalRead(1)==HIGH){
		if(state == NOT_TRACKING){
			//read sensor and store as target
			sensorVal = analogRead(3);
			
			mypid.setTarget(sensorVal);
		}else{
			state = NOT_TRACKING; //stop tracking target
		}
		
	}
	
	/* read sensor */
	sensorVal = analogRead(3);
	
	
	if(state == TRACKING){
		motorOutput = mypid.update(sensorVal);
		analogWrite(4, motorOutput);
	}
    delay(100);//delay for good measure
	
}


