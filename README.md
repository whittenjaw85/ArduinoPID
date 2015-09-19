# ArduinoPID
Quick implementation of PID controller with Arduino

**To use the implementation**

*It is probably good start for kP, kI, and kD*

`PID mypid = PID(1, 0.1, 0);`

**To set a reference**

`mypid.setTarget( <some value you like> );`

**To get an output for your factor**

`int output = 0; //initial holder for data`

`output = mypid.update( <sensor reference> );`

