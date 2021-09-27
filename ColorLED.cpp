extern "C"{
	#include <wiringPi.h>
	#include <softPwm.h>
}
#include "ColorLED.h"

using namespace std;

#define ON 1     //use LED
#define OFF 0    //stop LED

/*define pin*/
int red_port = 3;  //LED_R link on Raspberry's wiringPi 3 pin
int green_port = 2;  //LED_G link on Raspberry's wiringPi 2 pin
int blue_port = 5;  //LED_B link on Raspberry's wiringPi 5 pin


void LED_color(int switch_red, int switch_green, int switch_blue)
{
  	//red LED
  	switch_red == ON ? digitalWrite(red_port, HIGH): digitalWrite(red_port, LOW);
 
  	//green LED
  	switch_green == ON ? digitalWrite(green_port, HIGH) : digitalWrite(green_port, LOW);
  
  	//blue LED
  	switch_blue == ON ? digitalWrite(blue_port, HIGH) : digitalWrite(blue_port, LOW);
}


void red(){
	LED_color(ON, OFF, OFF);
	delay(500);
}


void green(){
	LED_color(OFF, ON, OFF);
	delay(500);
}


void blue(){
	LED_color(OFF, OFF, ON);
	delay(500);
}


void yellow(){
	LED_color(ON, ON, OFF);
	delay(500);
}


void pink(){
	LED_color(ON, OFF, ON);
	delay(500);
}


void cyan(){
	LED_color(OFF, ON, ON);
	delay(500);
}


void white(){
	LED_color(ON, ON, ON);
}


void turnOffLED(){
	LED_color(OFF,OFF,OFF);
}


int main()
{
	wiringPiSetup();
	
	//RGB pin mode set to output mode
	pinMode(red_port, OUTPUT);
	pinMode(green_port, OUTPUT);
	pinMode(blue_port, OUTPUT);
	int i = 0;
	while(i<10){
		red();
		yellow();
		green();
		pink();
		blue();
		white();
		cyan();
		turnOffLED();
		i++;
	}
   return 0;	
}
