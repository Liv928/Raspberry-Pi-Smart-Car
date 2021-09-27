
extern "C"{
#include <wiringPi.h>
#include <softPwm.h>
}
#include <iostream>
#include "brake.h"
using namespace std;

//define pin
int Left_motor_forward = 28;       //left moter move forward connect to pin 28 with Pi
int Left_motor_backward = 29;     //left moter move backward connect to pin 29 with Pi

int Right_motor_forward = 24;      //right moter move forward connect to pin 24 with Pi
int Right_motor_backward = 25;    //left moter move backward connect to pin 25 with Pi

int Left_motor_pwm = 27;      //pin 27 controls speed of the car, with left moter
int Right_motor_pwm = 23;     //pin 23 controls speed of the car, with right moter


void brake(int time)
{
    digitalWrite(Left_motor_forward, LOW);
    digitalWrite(Left_motor_backward, LOW);
    digitalWrite(Right_motor_forward, LOW);
    digitalWrite(Right_motor_backward, LOW);
    
    delay(time * 100);
    cout<<"car brakes successfully"<<endl;
}


int main()
{
    //initialize wiringPi
    wiringPiSetup();
    
    pinMode(Left_motor_forward, OUTPUT);
    pinMode(Left_motor_backward, OUTPUT);
    pinMode(Right_motor_forward, OUTPUT);
    pinMode(Right_motor_backward, OUTPUT);
    
    //create two pin controlled by software
    //int softPwmCreate(int pin,int initialValue,int pwmRange);
    softPwmCreate(Left_motor_pwm,0,255);
    softPwmCreate(Right_motor_pwm,0,255);
        brake(20);
 
}

