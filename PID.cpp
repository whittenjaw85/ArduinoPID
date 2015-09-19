#include "PID.h"

PID::PID(float kP, float kI, float kD){
	this->kP = kP;
	this->kI = kI;
	this->kD = kD;
	
	this->error = 0;
	this->errorOld = 0;
	this->errorDifference = 0;
	this->errorAccumulator = 0;
}

void PID::setTarget(int val){
	/* This function takes a reference value and presumes
	that it is in the correct units desired for operation 
	*/
	
	this->error = 0;
	this->errorOld = 0;
	this->errorDifference = 0;
	this->errorAccumulator = 0;
	
	this->target = val;
}

int PID::update(int val){
	/* The update function takes a sensor value for comparison
	against the desired target */
	
	//Convert val from sensor to control value
	int usableVal = val;// assuming nothing needed for now
	
	//Calc error
	this->error = target - val;
	
	//"Integrate" discrete
	this->errorAccumulator += this->error;
	
	//"Differentiate" discrete
	this->errorDifference = this->error - this->errorOld;
	
	//upkeep
	this->error = this->errorOld;
	
	int output = (this->error*this->kP + this->errorAccumulator*this->kI + 
		this->errorDifference*this->kD);
		
	//verify output is within bounds of control
	if(output > 255) output = 255;
	if(output < 0) output = 0;
	
	//return output
	return output;
}