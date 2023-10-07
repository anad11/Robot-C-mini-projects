task main()
{
	SensorType[S1]=sensorEV3_Touch;
	wait1Msec(50);
	SensorType[S2]=sensorEV3_Ultrasonic;
	wait1Msec(50);
	SensorType[S3]=sensorEV3_Color;
	wait1Msec(50);
	SensorMode[S3]=modeEV3Color_Color;
	wait1Msec(50);
	SensorType[S4]=sensorEV3_Gyro;
	wait1Msec(50);



	displayString(3, "Group 5 JC AD");

	while (!getButtonPress(buttonAny))
	{	}
	while (getButtonPress(buttonAny))
	{	}
	const int color_red=5;
	nMotorEncoder[motorB]=0;
	motor[motorB]=motor[motorC]=40;
	while (SensorValue[S3]!=color_red)
	{	}

	int paper_start = 0;
	paper_start = SensorValue[S2];
	while (SensorValue[S3]==color_red)
	{	}

	int paper_end = 0;
	paper_end = SensorValue[S2];

	int paper_length_us = 0;
	paper_length_us = paper_start - paper_end;

	while (SensorValue[S1] == 0)
	{	}
	wait1Msec(50);



	motor[motorB]=motor[motorC]=-40;

	while (SensorValue[S3]!=color_red)
	{	}
	nMotorEncoder[motorC]=0;
	while (SensorValue[S3]==color_red)
	{	}
	int paper_length_e=0;
	paper_length_e=nMotorEncoder[motorC];

	while (nMotorEncoder[motorB]>0)
	{	}

	motor[motorB]=motor[motorC]=0;

	displayString(5, "%d" , paper_length_us);
	displayString(7, "%d" , paper_length_e);
	wait1Msec(2000);

	motor[motorB]=30;
	motor[motorC]=-30;
	while(getGyroDegrees(S4)<360)
	{	}
	motor[motorB]=motor[motorC]=0;
	wait1Msec(50);

	displayString(10, "HALLOWEEN");
	wait1Msec(4000);

}
