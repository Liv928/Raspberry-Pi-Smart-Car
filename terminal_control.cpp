

#include "terminal_control.h"

using namespace std;

/**define pin*/
int Left_motor_forward = 28;       //left moter move forward connect to pin 28 with Pi
int Left_motor_backward = 29;     //left moter move backward connect to pin 29 with Pi

int Right_motor_forward = 24;      //right moter move forward connect to pin 24 with Pi
int Right_motor_backward = 25;    //left moter move backward connect to pin 25 with Pi

int Left_motor_pwm = 27;      //pin 27 controls speed of the car, with left moter
int Right_motor_pwm = 23;     //pin 23 controls speed of the car, with right moter


void run(int time)
{
    
    digitalWrite(Left_motor_forward, HIGH);
    digitalWrite(Left_motor_backward, LOW);
    softPwmWrite(Left_motor_pwm, 150);   
    
    
    digitalWrite(Right_motor_forward, HIGH);
    digitalWrite(Right_motor_backward, LOW);
    softPwmWrite(Right_motor_pwm, 150);
    
    delay(time * 100);
    
    brake();

    cout<<"car moves forward successfully"<<endl;
}


void brake()
{
    digitalWrite(Left_motor_forward, LOW);
    digitalWrite(Left_motor_backward, LOW);
    digitalWrite(Right_motor_forward, LOW);
    digitalWrite(Right_motor_backward, LOW);
    
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
    brake();
    cout<<"car moves back successfully"<<endl;
}


void left(int time)
{
    digitalWrite(Left_motor_forward, LOW);     
    digitalWrite(Left_motor_backward, LOW);
    softPwmWrite(Left_motor_pwm, 70);      
    

    digitalWrite(Right_motor_forward, HIGH);  
    digitalWrite(Right_motor_backward, LOW); 
    softPwmWrite(Right_motor_pwm, 100);
    
    delay(time * 100);
    brake();
    cout<<"car moves left successfully"<<endl;
}


void right(int time)
{
    digitalWrite(Left_motor_forward, HIGH);
    digitalWrite(Left_motor_backward, LOW);
    softPwmWrite(Left_motor_pwm, 100);
    
    digitalWrite(Right_motor_forward, LOW);
    digitalWrite(Right_motor_backward, LOW);
    softPwmWrite(Right_motor_pwm, 70);
    
    delay(time * 100);
    brake();
    cout<<"car moves right successfully"<<endl;
}


char get_command(void)
{
  char command ;
  do {
      cout<<"\n";
      cout<<"\nW - Forward";
      cout<<"\nS - Back";
      cout<<"\nA - Turn Left";
      cout<<"\nD - Turn Right";
      cout<<"\nQ - brake";
      cout<<"\nEnter your command:";
      cin>>command;   
  }while((char)tolower(command)!='w'&& (char)tolower(command)=='a'&& (char)tolower(command)=='s'&& (char)tolower(command)=='d'&& (char)tolower(command)=='q');
  return command;
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
    softPwmCreate(Left_motor_pwm,0,255);
    softPwmCreate(Right_motor_pwm,0,255);
    
    char command;
    do{
        command = get_command();
        if(command=='w')
            run(30);
        if(command=='a')
            right(20);
        if(command=='s')
            back(30);
        if(command=='d')
            left(20); 
        }while((char)tolower(command)!='q');
        brake();
        
    return 0;
   
}

