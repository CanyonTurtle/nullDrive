//Shatayu,
// this is made for use with 1 ultrasonic mounted above fence level in back of bot.

void waitUntilAimed() {
	bool foundPole = false;
	int tolerance = 00;
	float finalSonar;
	float lastSonar = sensorValue(sonar);
	float newSonar = sensorValue(sonar);
	powerDrive(40, -40);

	//turn until seeing pole
	while(foundPole == false){
		lastSonar = newSonar;
		wait1Msec(30);
		newSonar = sensorValue[sonar];
		if(newSonar < 55){ //(lastSonar - 10)
			foundPole = true;
			finalSonar = newSonar;
		}
	}
	
	//turn until past pole
	int firstEnc = getMotorEncoder(leftDrive);
	foundPole = true;
	while(foundPole == true){
		lastSonar = newSonar;
		wait1Msec(30);
		newSonar = sensorValue[sonar];
		if(newSonar > finalSonar){ //(lastSonar - 10)
			foundPole = false;
		}
	}

	//turn back until encoder on drive is at average value between start and stop of seeing pole.
	int lastEnc = getMotorEncoder(leftDrive);
	float avgMC = (lastEnc + firstEnc) / 2
	powerDrive(-40, 40);
	waitUntil(abs(getMotorEncoder(leftDrive) - avgMC) < 10);
	wait1Msec(140);
}

task ericAutonClimb()
{
	powerDrive(80, 80);
	wait1Msec(500);
	powerDrive(-80, 80);
	powerClaw(80, 80);
	wait1Msec(700);
	powerDrive(80, 80);
	wait1Msec(700);
	powerDrive(60, -60);
	powerClaw(0,0);
	wait1Msec(1500);
	waitUntilAimed();
	powerDrive(-80,-80);
	wait1Msec(700);
	powerLift(127, 127);
	powerClaw(-30, -30);
	powerDrive(-30, -30);
	wait1Msec(1300);
	powerLift(0,0);
	powerClaw(0,0);
	powerDrive(0,0);
	wait1Msec(500);
	powerDrive(127, 127);
	powerLift(-127, -127);
	waitUntil(SensorValue[pot2] < 1400);
	powerLift(-10, -10);
	powerDrive(0,0);

}
