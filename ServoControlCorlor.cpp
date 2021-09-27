extern "C"{
	#include <wiringPi.h>
	#include <softPwm.h>
}
#include "ServoControlCorlor.h"
using namespace std;

#define ON  1   //use LED
#define OFF 0   //stop LED

//define pin
int red_port = 3;  //LED_R link on Raspberry's wiringPi 3 pin
int green_port = 2;  //LED_G link on Raspberry's wiringPi 2 pin
int blue_port = 5;  //LED_B link on Raspberry's wiringPi 5 pin

//define servo pin
int ServoPin = 4;

//define function
void color_light(int);
void LED_color(int, int, int);


void servo_pulse(int myangle)
{
  int PulseWidth;                    //define pulse width variable
  PulseWidth = (myangle * 11) + 500; //convert the angle to a pulse width of 500-2480
  digitalWrite(ServoPin, HIGH);      //set the interface level of the steering gear high
  delayMicroseconds(PulseWidth);     //delay microseconds of pulse width value
  digitalWrite(ServoPin, LOW);       //set the interface level of the steering gear low
  delay(20 - PulseWidth / 1000);     //delay remaining time in the period
  return;
}


void servo_control_color()
{
  //define steering gear rotation position
  int pos = 0;
  for (pos = 0; pos < 180; pos++)
  {
    //steering gear from 0 rotates to 180, delaying 20ms each time
    servo_pulse(pos);
    //rotate to the corresponding angle, call related functions
    color_light(pos);
    delay(20);
  }

  for (pos = 180; pos > 0; pos--)
  {
    //steering gear from 180 to 0, delaying 20ms each time
    servo_pulse(pos);
    //rotate to the corresponding angle, call related functions
    color_light(pos);
    delay(20);
  }
  return;
}


void color_light(int pos)
{
  //red light when turning at 150-180 degrees
  if (pos > 150)
  {
    LED_color(ON, OFF, OFF);
  }
  //green light, when rotating at 125-150 degrees
  else if (pos > 125)
  {
    LED_color(OFF, ON, OFF);
  }
  //blue, when rotating at 100-125 degrees
  else if (pos > 100)
  {
    LED_color(OFF, OFF, ON);
  }
  //cyan light, when rotating at 75-100 degrees
  else if (pos > 75)
  {
    LED_color(OFF, ON, ON);
  }
  //yellow light,When rotating at 50-75 degrees
  else if (pos > 50)
  {
    LED_color(ON, ON, OFF);
  }
  //pink light,when rotating at 25-50 degrees
  else if (pos > 25)
  {
    LED_color(ON, OFF, ON);
  }
  //white light,when rotating at 0-25 degrees
  else if (pos > 0)
  {
    LED_color(ON, ON, ON);
  }
  else
  {//turn off the light
    LED_color(OFF, OFF, OFF);
  }
}


void LED_color(int switch_red, int switch_green, int switch_blue)
{
  //red LED
  switch_red == ON ? digitalWrite(red_port, HIGH): digitalWrite(red_port, LOW);
 
  //green LED
  switch_green == ON ? digitalWrite(green_port, HIGH) : digitalWrite(green_port, LOW);
  
  //blue LED
  switch_blue == ON ? digitalWrite(blue_port, HIGH) : digitalWrite(blue_port, LOW);
}


int main()
{
  //inital wiringPi
  wiringPiSetup();
  
  //set steering gear to output mode
  pinMode(ServoPin, OUTPUT);
  
  //initialize IO port of RGB tricolor LED as output mode
  pinMode(red_port, OUTPUT);
  pinMode(green_port, OUTPUT);
  pinMode(blue_port, OUTPUT);
  
  //initializing the actuator position forward
  int ServoPos = 90;
  servo_pulse(ServoPos);
  int i = 0;
  while(i<10)
  {
   //delay 0.5s
   delay(500);
   //Call the steering gear control colorful light program
   servo_control_color();
   i++;
  }
  return 1;
}


