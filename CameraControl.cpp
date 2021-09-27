extern "C"{
	#include <wiringPi.h>
	#include <softPwm.h>
}
#include "CameraControl.h"
using namespace std;

//variable of two pos of camera steering gear
int ServoUpDownPos = 90;
int ServoLeftRightPos = 90;
//set steering gear pin
int ServoPin = 4;
int FrontServoPin = 4;
int ServoUpDownPin = 13;
int ServoLeftRightPin = 14;

//front gear left, right sway variable
int FrontServoLeftRightPos = 90;

//steering gear control mark pos
int ServoFlags;

void servo_pulse(int ServoPin, int myangle)
{
  int PulseWidth;                    //define pulse width variable
  PulseWidth = (myangle * 11) + 500; //convert the angle to a pulse width of 500-2480
  digitalWrite(ServoPin, HIGH);      //set the interface level of the steering gear high
  delayMicroseconds(PulseWidth);     //delay microseconds of pulse width value
  digitalWrite(ServoPin, LOW);       //set the interface level of the steering gear low
  delay(20 - PulseWidth / 1000);     //delay remaining time in the period
  return;
}


void servo_init()
{
	int i = 0;
	for (i = 0; i < 10; i++)
	{
	servo_pulse(ServoLeftRightPin, 90); 
	}
	for (i = 0; i < 10; i++)
	{
	servo_pulse(ServoUpDownPin, 90);
	}
	for (i = 0; i < 10; i++)
	{
	servo_pulse(FrontServoPin, 90);
	}
}


void servo_up(int angle, int a)
{
	int i = 0;
	for (i = 0; i < a; i++)
	{
	servo_pulse(ServoUpDownPin, angle);
	}
}


void servo_down(int angle, int a)
{
	int i = 0;
	for (i = 0; i < a; i++)
	{
	servo_pulse(ServoUpDownPin, angle);
	}
}


void servo_left(int angle, int a)
{
	int i = 0;
	for (i = 0; i < a; i++)
	{
	servo_pulse(ServoLeftRightPin, angle);
	}
}


void servo_right(int angle, int a)
{  
	int i = 0;
	for (i = 0; i < a; i++)
	{
	servo_pulse(ServoLeftRightPin, angle);
	}
}

void servo_updown_init()
{
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		servo_pulse(ServoUpDownPin, 90);
	}
}


void servo_front_init()
{
	servo_pulse(FrontServoPin, 90);
}


int main()
{
    //inital wiringPi
  wiringPiSetup();
  
  //set steering gear to output mode
  pinMode(ServoUpDownPin, OUTPUT);
  pinMode(ServoLeftRightPin, OUTPUT);
  int i = 0;
	//test if the camera can be control be our program
	servo_init(); //set to initial postion
    delay(2000);
	servo_up(0,2);	//camera move forward
	delay(2000);
	servo_init();//go back to initial position
	delay(2000);
	servo_down(180,6); //cmaera move backward
	delay(2000);
	servo_init(); //back to initial
	delay(2000);
	servo_right(0,6); //camera move right
	delay(2000);
	servo_init(); //back to initial
	delay(2000);
	servo_left(180,6); //camera move left
	delay(2000);
	servo_init();//back to initial
  return 1;
}
