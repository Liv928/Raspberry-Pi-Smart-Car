
extern "C"{
#include <wiringPi.h>
#include <softPwm.h>
}
#include <iostream>

using namespace std;

//define pin
int Left_motor_forward = 28;       //left moter move forward connect to pin 28 with Pi
int Left_motor_backward = 29;     //left moter move backward connect to pin 29 with Pi

int Right_motor_forward = 24;      //right moter move forward connect to pin 24 with Pi
int Right_motor_backward = 25;    //left moter move backward connect to pin 25 with Pi

int Left_motor_pwm = 27;      //pin 27 controls speed of the car, with left moter
int Right_motor_pwm = 23;     //pin 23 controls speed of the car, with right moter

//function to make car move forward
void run(int time)
{
    //write HIGH or LOW to a digital pin
    //HIGH indicate activate, LOW indicate deactivate
    digitalWrite(Left_motor_forward, HIGH);
    digitalWrite(Left_motor_backward, LOW);
    softPwmWrite(Left_motor_pwm, 150);   //control tire's speed
    
    
    digitalWrite(Right_motor_forward, HIGH);
    digitalWrite(Right_motor_backward, LOW);
    softPwmWrite(Right_motor_pwm, 150);
    
    delay(time * 100);
    cout<<"car moves forward successfully"<<endl;
}


void brake(int time)
{
    digitalWrite(Left_motor_forward, LOW);
    digitalWrite(Left_motor_backward, LOW);
    digitalWrite(Right_motor_forward, LOW);
    digitalWrite(Right_motor_backward, LOW);
    
    delay(time * 100);
    cout<<"car brakes successfully"<<endl;
}


void back(int time)
{
    digitalWrite(Left_motor_forward, LOW);
    digitalWrite(Left_motor_backward, HIGH);
    softPwmWrite(Left_motor_pwm, 150);
    
    digitalWrite(Right_motor_forward, LOW);
    digitalWrite(Right_motor_backward, HIGH);
    softPwmWrite(Right_motor_pwm, 150);
    
    delay(time * 100);
    cout<<"car moves back successfully"<<endl;
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
 
        //programmed actions
        delay(2000);
        run(10);
        brake(5);
        back(10);
        run(5);
        brake(2);
        back(5);
        cout<<"car runs successfully"<<endl;
    return 1;
}

