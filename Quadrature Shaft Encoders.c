#pragma config(Sensor, dgtl9,  leftWheelEncoder, sensorQuadEncoder)
#pragma config(Sensor, dgtl11, rightWheelEncoder, sensorQuadEncoder)
#pragma config(Motor,  port1,           backLeft,      tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           frontLeft,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           leftLift,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           claw,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           mobileGoal,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           rightLift,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           frontRight,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          backRight,     tmotorVex393_HBridge, openLoop, reversed)

task main()
{
	wait1Msec(1000);  // 1 Second Delay

	//Clear Encoders
	SensorValue[rightWheelEncoder] = 0;
	SensorValue[leftWheelEncoder] = 0;
	while(true)
	{
		while(SensorValue[leftWheelEncoder] < 180)  // While less than 5 rotations on the leftEncoder...
		{
			if(SensorValue[leftWheelEncoder] < SensorValue[rightWheelEncoder])//if right side is behind
			{
				motor[backLeft] = 63;
				motor[backRight] = 50;
				motor[frontLeft] = 63;
				motor[frontRight] = 50;
			}
			else if(SensorValue[rightWheelEncoder] < SensorValue[leftWheelEncoder])//if left side is behind
			{
				motor[backLeft] = 40;
				motor[backRight] = 63;
				motor[frontLeft] = 63;
				motor[frontRight] = 40;
			}
			else
			{
				//...Move Forward
				motor[backLeft] = 63;
				motor[backRight] = 63;
				motor[frontLeft] = 63;
				motor[frontRight] = 63;
			}
		}
		motor[backLeft] = 0;
		motor[backRight] = 0;
		motor[frontLeft] = 0;
		motor[frontRight] = 0;
	}
}
