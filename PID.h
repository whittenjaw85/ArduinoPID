#ifndef _PID_H_
#define _PID_H_

#include "Arduino.h"

class PID{
	
public:
	PID(float kP, float kI, float kD);
	
	void setTarget(int val); //sets the desired value of the operation
	
	int update(int val); //returns value of control
	
	
private:
	int errorAccumulator;
	int errorDifference;
	int error;
	int errorOld;
	
	float kP;
	float kI;
	float kD;
	
	int target;
};


#endif //_PID_H_