
#include "infrared.h"

//Define pin
int Left_motor_forward = 28;       //Left motor forward AIN2 connects Raspberry's wiringPi code 28 port
int Left_motor_backward = 29;     //Left motor forward AIN2 connects Raspberry's wiringPi code 29 port
int Right_motor_forward = 24;      //Right motor forward BIN2 connection Raspberry wiringPi code 24 port
int Right_motor_backward = 25;    //Right motor forward BIN2 connection Raspberry wiringPi code 25 port
int Left_motor_pwm = 27;      //Left motor speed control PWMA connects Raspberry's wiringPi code 27 port
int Right_motor_pwm = 23;     //Left motor speed control PWMA connects Raspberry's wiringPi code 23 port
int key = 10;                 //Define the button as Raspberry's wiringPi code 10 port

const int FollowSensorLeft =  26;  //Define the infrared sensor pin on the left to be the wiring of the wiringPi encoding 26
const int FollowSensorRight = 0;   //Define the infrared sensor pin following the right side as the wiring of the trackingPi code

int LeftSensorValue ;              //Define variables to save the size of the data collected by the infrared sensor
int RightSensorValue ;



void run()
{
  //Left motor forward
  digitalWrite(Left_motor_forward, HIGH);   //Left motor forward enable
  digitalWrite(Left_motor_backward, LOW);  //Left motor backward disable
  softPwmWrite(Left_motor_pwm, 150);

  //Right motor forward
  digitalWrite(Right_motor_forward, HIGH);  //Right motor forward enable
  digitalWrite(Right_motor_backward, LOW); //Right motor backward disable
  softPwmWrite(Right_motor_pwm, 150);
}


void brake(int time)
{
  digitalWrite(Left_motor_forward, LOW);
  digitalWrite(Left_motor_backward, LOW);
  digitalWrite(Right_motor_forward, LOW);
  digitalWrite(Right_motor_backward, LOW);
  delay(time * 100);
}


void left()
{
  //Left motor stop
  digitalWrite(Left_motor_forward, LOW);    //Left motor forward prohibition
  digitalWrite(Left_motor_backward, LOW);  //Left motor backward prohibition
  softPwmWrite(Left_motor_pwm, 70);

  //Right motor forward
  digitalWrite(Right_motor_forward, HIGH);  //Right motor forward prohibition
  digitalWrite(Right_motor_backward, LOW); //Right motor backward prohibition
  softPwmWrite(Right_motor_pwm, 100);
}


void right()
{
  //Left motor forward
  digitalWrite(Left_motor_forward, HIGH);   //Left motor forward enable
  digitalWrite(Left_motor_backward, LOW);  //Left motor backward enable
  softPwmWrite(Left_motor_pwm, 80);

  //Right motor stop
  digitalWrite(Right_motor_forward, LOW);   //Right motor forward enable
  digitalWrite(Right_motor_backward, LOW); //Right motor forward enable
  softPwmWrite(Right_motor_pwm, 0);
}



void left_motor_forward(int sp){
  digitalWrite(Left_motor_forward, HIGH);    //Left motor forward enable
  digitalWrite(Left_motor_backward, LOW);   //Left motor back prohibition
  softPwmWrite(Left_motor_pwm, sp); 
}

void left_motor_backward(int sp){
  digitalWrite(Left_motor_forward, LOW);     //Left motor forward prohibition
  digitalWrite(Left_motor_backward, HIGH);  //Left motor back enable
  softPwmWrite(Left_motor_pwm, sp);
}

void right_motor_forward(int sp){
  digitalWrite(Right_motor_forward, HIGH);  //Right motor forward enable
  digitalWrite(Right_motor_backward, LOW); //Right motor back prohibition
  softPwmWrite(Right_motor_pwm, sp);
}

void right_motor_backward(int sp){
  digitalWrite(Right_motor_forward, LOW);    //Right motor forward prohibition
  digitalWrite(Right_motor_backward, HIGH); //Right motor back enable
  softPwmWrite(Right_motor_pwm, sp);
}


void spin_left(int time)
{
  //Left motor back
  left_motor_backward(150);

  //Right motor forward
  right_motor_backward(150);

  delay(time * 100);
}


void spin_right(int time)
{
  //Left motor forward
  left_motor_forward(200);

  //Right motor back
  right_motor_backward(200);

  delay(time * 100);
}


void back(int time)
{
  //left motor back
  left_motor_backward(150);

  //right motor back
  right_motor_backward(150);

  delay(time * 100);
}


void key_scan()
{
  while (digitalRead(key));       //Loops when the button is not pressed
  while (!digitalRead(key))       //When the button is pressed
  {
    delay(10);	                  //delay 10ms
    if (digitalRead(key)  ==  LOW)//The second time to determine whether the button is pressed
    {
      delay(100);
      while (!digitalRead(key));  //Determine if the button is released
    }
  }
}

int main()
{ 
  //wiringPi initialization
  wiringPiSetup();
  
  //Initialize the motor drive IO port as the output mode
  pinMode(Left_motor_forward, OUTPUT);
  pinMode(Left_motor_backward, OUTPUT);
  pinMode(Right_motor_forward, OUTPUT);
  pinMode(Right_motor_backward, OUTPUT);
  
  //Create two software controlled PWM pins
  softPwmCreate(Left_motor_pwm,0,255); 
  softPwmCreate(Right_motor_pwm,0,255);

  //Define the button interface as the input interface
  pinMode(key, INPUT);

  //Define the left and right sensors as input interfaces
  pinMode(FollowSensorLeft, INPUT);
  pinMode(FollowSensorRight, INPUT);
  
  //Call the button scan function
  key_scan(); 

  while(1)
  {
  
    LeftSensorValue  = digitalRead(FollowSensorLeft);
    RightSensorValue = digitalRead(FollowSensorRight);

    if (LeftSensorValue == LOW && RightSensorValue == LOW)
    {
      run();       
    }
    else if (LeftSensorValue == LOW && RightSensorValue == HIGH)
    {
      spin_left(2); 
    }
    else if (RightSensorValue == LOW && LeftSensorValue == HIGH)
    {
      spin_right(2);
    }
    else if (RightSensorValue == HIGH && LeftSensorValue == HIGH)
    {
      brake(0);     
    }
  }
  return 1;
}
