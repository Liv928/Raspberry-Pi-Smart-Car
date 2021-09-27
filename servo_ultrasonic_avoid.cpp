
#include "servo_ultrasonic_avoid.h"

#define ON  1       //Enable LED
#define OFF 0       //Disable LED

//Define pin
int Left_motor_forward = 28;   //Left motor forward AIN2 connection Raspberry wiringPi code 28 port
int Left_motor_backward = 29; //Left motor back AIN1 connected to Raspberry's wiringPi code 29

int Right_motor_forward = 24;  //Right motor forward BIN2 connection Raspberry wiringPi code 24 port
int Right_motor_backward = 25;//Right motor back BIN1 connection Raspberry wiringPi code 25 port

int Left_motor_pwm = 27;  //Left motor speed control PWMA connects Raspberry's wiringPi code 27 port
int Right_motor_pwm = 23; //Right motor speed control PWMB connects Raspberry's wiringPi code 23 port

//button
int key = 10;             //Define the button as Raspberry's wiringPi code 10 port

//Ultrasonic
int EchoPin = 30;         //Define the echo foot to connect to Raspberry's wiringPi code 30 port
int TrigPin = 31;         //Define the trigger pin to connect Raspberry's wiringPi code to port 31

//Define pin
int LED_R = 3;           //LED_R is connected to the wiringPi code 3 port on Raspberry
int LED_G = 2;           //LED_G is connected to the wiringPi code 2 port on Raspberry
int LED_B = 5;           //LED_B is connected to the wiringPi code 5 on Raspberry

//Define the servo pin
int ServoPin = 4;

//Initialize the servo position forward
int ServoPos = 90;

const int AvoidSensorLeft =  26; //The infrared sensor pin that defines the obstacle avoidance on the left is the wiring of the wiringPi encoding 26
const int AvoidSensorRight = 0;  //The infrared sensor pin that defines the obstacle avoidance on the right is the wiring of the trackingPi code 0.

int LeftSensorValue ;            //Define variables to save the size of the data collected by the infrared sensor
int RightSensorValue ;

//Function declaration
void brake();
void spin_left(int);
void spin_right(int);
void back(int);
float Distance_test();
void bubble(unsigned long *, int);
void corlor_led(int, int, int);


void servo_pulse(int ServoPin, int myangle)
{
  int PulseWidth;                    //Define pulse width variable
  PulseWidth = (myangle * 11) + 500; //Convert the angle to a pulse width of 500-2480
  digitalWrite(ServoPin, HIGH);      //Set the servo interface level high
  delayMicroseconds(PulseWidth);     //The number of microseconds of the delay pulse width value
  digitalWrite(ServoPin, LOW);       //Lower the servo interface level
  delay(20 - PulseWidth / 1000);     //Remaining time in the delay period
  return;
}


void servo_appointed_detection(int pos)
{
  int i = 0;
  for (i = 0; i <= 15; i++)    //Generate PWM number, equivalent delay to ensure that it can be turned to response angle
  {
    servo_pulse(ServoPin, pos);//Analog generation PWM
  }
}


void servo_color_carstate()
{
  float distance;
  //Define the servo position variable and the front, left and right distance of the cart
  int iServoPos = 0;
  int LeftDistance = 0;    
  int RightDistance = 0;   
  int FrontDistance = 0;
  corlor_led(ON, OFF, OFF);//Red light
  back(80);                //Avoid sudden stop, can't stop the car
  brake();

  //The steering gear is rotated to 0 degrees, that is, the right side, ranging
  servo_appointed_detection(0);
  delay(500);
  distance = Distance_test();  //Ranging
  RightDistance = distance;    //The measured right distance is assigned to the variable RightDistance
 
  //The steering gear is rotated to 180 degrees, that is, the left side, ranging
  servo_appointed_detection(180);
  delay(500);
  distance = Distance_test();  //Ranging
  LeftDistance = distance;//The measured left distance is assigned to the variable LeftDistance

  //The steering gear is rotated to 90 degrees, that is, the middle, ranging
  servo_appointed_detection(90);
  delay(500);
  distance = Distance_test();
  FrontDistance = distance;//The measured front side distance is given to the variable FrontDistance
 
  if (LeftDistance < 30 && RightDistance < 30 && FrontDistance < 30  )
  {
    //Bright magenta, U-turn
    corlor_led(ON, OFF, ON);
    spin_right(700);
  }
  else if ( LeftDistance >= RightDistance) //When the distance on the left side is found to be greater than the right side, turn left in place.
  {
    //bright blue
    corlor_led(OFF, OFF, ON);
    spin_left(350);
  }
  else if (LeftDistance < RightDistance ) //When the right side distance is greater than the left side, turn right and turn right.
  {
    //Bright magenta, turn right
    corlor_led(ON, OFF, ON);
    spin_right(350);
  }
}


void run(int leftSpeed,int rightSpeed)
{
  //Left motor forward
  digitalWrite(Left_motor_forward, HIGH);   //Left motor forward enable
  digitalWrite(Left_motor_backward, LOW);  //Left motor backward disable
  softPwmWrite(Left_motor_pwm, leftSpeed);

  //Right motor forward
  digitalWrite(Right_motor_forward, HIGH);  //Right motor forward enable
  digitalWrite(Right_motor_backward, LOW); //Right motor backward disable
  softPwmWrite(Right_motor_pwm, rightSpeed);
}


void brake()
{
  digitalWrite(Left_motor_forward, LOW);
  digitalWrite(Left_motor_backward, LOW);
  digitalWrite(Right_motor_forward, LOW);
  digitalWrite(Right_motor_backward, LOW);
}


void left()
{
  //Left motor stop
  digitalWrite(Left_motor_forward, LOW);    //Left motor forward prohibition
  digitalWrite(Left_motor_backward, LOW);  //Left motor backward prohibition
  softPwmWrite(Left_motor_pwm, 0);

  //Right motor forward
  digitalWrite(Right_motor_forward, HIGH);  //Right motor forward prohibition
  digitalWrite(Right_motor_backward, LOW); //Right motor backward prohibition
  softPwmWrite(Right_motor_pwm, 16);
}


void right()
{
  //Left motor forward
  digitalWrite(Left_motor_forward, HIGH);   //Left motor forward enable
  digitalWrite(Left_motor_backward, LOW);  //Left motor backward enable
  softPwmWrite(Left_motor_pwm, 16);

  //Right motor stop
  digitalWrite(Right_motor_forward, LOW);   //Right motor forward enable
  digitalWrite(Right_motor_backward, LOW); //Right motor forward enable
  softPwmWrite(Right_motor_pwm, 0);
}


void spin_left(int time)
{
  //Left motor back
  digitalWrite(Left_motor_forward, LOW);     //Left motor forward prohibition
  digitalWrite(Left_motor_backward, HIGH);  //Left motor back enable
  softPwmWrite(Left_motor_pwm, 40);

  //Left motor back enable
  digitalWrite(Right_motor_forward, HIGH);  //Right motor forward enable
  digitalWrite(Right_motor_backward, LOW); //Right motor back prohibition
  softPwmWrite(Right_motor_pwm, 40);

  delay(time);
}


void spin_right(int time)
{
  //Left motor forward
  digitalWrite(Left_motor_forward, HIGH);   //Left motor forward enable
  digitalWrite(Left_motor_backward, LOW);  //Left motor back prohibition
  softPwmWrite(Left_motor_pwm, 40);

  //Right motor back
  digitalWrite(Right_motor_forward, LOW);    //Right motor forward prohibition
  digitalWrite(Right_motor_backward, HIGH); //Right motor back enable
  softPwmWrite(Right_motor_pwm, 40);

  delay(time);
}


void back(int time)
{
  //Left motor back
  digitalWrite(Left_motor_forward, LOW);     //Left motor forward prohibition
  digitalWrite(Left_motor_backward, HIGH);  //Left motor back enable
  softPwmWrite(Left_motor_pwm, 80);

  //Right motor back
  digitalWrite(Right_motor_forward, LOW);    //Right motor forward prohibition
  digitalWrite(Right_motor_backward, HIGH); //Right motor back enable
  softPwmWrite(Right_motor_pwm, 80);

  delay(time);
}


void corlor_led(int v_iRed, int v_iGreen, int v_iBlue)
{
  //red LED
  v_iRed == ON ? digitalWrite(LED_R, HIGH): digitalWrite(LED_R, LOW);
 
  //green LED
  v_iGreen == ON ? digitalWrite(LED_G, HIGH) : digitalWrite(LED_G, LOW);
  
  //blue LED
  v_iBlue == ON ? digitalWrite(LED_B, HIGH) : digitalWrite(LED_B, LOW);
}


float Distance()
{
	float distance;
	struct timeval tv1;
	struct timeval tv2;
	struct timeval tv3;
	struct timeval tv4;
	long start, stop;
	
	digitalWrite(TrigPin, LOW);
	delayMicroseconds(2);
	digitalWrite(TrigPin, HIGH);      //Input a high level of at least 10 US to the Trig pin
	delayMicroseconds(10);
	digitalWrite(TrigPin, LOW);
    
	//Prevent the program from detecting level changes, get stuck in an infinite loop, and add a timeout retest mechanism
    gettimeofday(&tv3, NULL);        //Timeout retest mechanism starts timing
	start = tv3.tv_sec * 1000000 + tv3.tv_usec;
	while(!digitalRead(EchoPin) == 1)
	{
		gettimeofday(&tv4, NULL);    //Timeout retest mechanism ends timing
		stop = tv4.tv_sec * 1000000 + tv4.tv_usec;
		
		if ((stop - start) > 30000)  //Time value up to 5 meters maximum: 10/340=0.03s
		{
			return -1;               //Timeout return -1
		}
	} 
	
	//Prevent the program from detecting level changes, get stuck in an infinite loop, and add a timeout retest mechanism
	gettimeofday(&tv1, NULL);      //Start timing when the echo foot level becomes high
    start = tv1.tv_sec*1000000+tv1.tv_usec;
	while(!digitalRead(EchoPin) == 0)
	{
		gettimeofday(&tv3,NULL);   //Timeout retest mechanism starts timing
		stop = tv3.tv_sec*1000000+tv3.tv_usec;
		if ((stop - start) > 30000)
		{
			return -1;
		}
	}                              //Timeout retest mechanism ends timing
	gettimeofday(&tv2, NULL);      //End timing when the echo foot level goes low

	start = tv1.tv_sec * 1000000 + tv1.tv_usec;
	stop = tv2.tv_sec * 1000000 + tv2.tv_usec;

	distance = (float)(stop - start)/1000000 * 34000 / 2;
	return distance;
}


float Distance_test()
{
  float distance;
  unsigned long ultrasonic[5] = {0};
  int num = 0;
  while (num < 5)
  {
     distance = Distance();
	 //Timeout returns -1, retest
	 while((int)distance == -1)
	 {
		 distance = Distance();
	 }
    //Filter out the error data that appears in the test distance is greater than 500
    while ( distance >= 500 || (int)distance == 0)
    {
         distance = Distance();
    }
    ultrasonic[num] = distance;
    num++;
	delay(10);
  }
  num = 0;
  bubble(ultrasonic, 5);
  distance = (ultrasonic[1] + ultrasonic[2] + ultrasonic[3]) / 3;
  
  printf("distance:%f\n",distance);      //Print test distance
  return distance;
}


void bubble(unsigned long *a, int n)

{
  int i, j, temp;
  for (i = 0; i < n - 1; i++)
  {
    for (j = i + 1; j < n; j++)
    {
      if (a[i] > a[j])
      {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
      }
    }
  }
}


void key_scan()
{
  while (digitalRead(key));       //Loops when the button is not pressed
  while (!digitalRead(key))       //When the button is pressed
  {
    delay(10);	                  //Delay 10ms
    if (digitalRead(key)  ==  LOW)//The second time to determine whether the button is pressed
    {
      delay(100);
      while (!digitalRead(key));  //Determine if the button is released
    }
  }
  return;
}


int main()
{
  float distance;
  
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

  //Initialize the IO port of the RGB tri-color LED as the output mode
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);

  //Define the button interface as the output interface
  pinMode(key, INPUT);

  //Initialize the ultrasonic pin
  pinMode(EchoPin, INPUT);    //Define ultrasonic input feet
  pinMode(TrigPin, OUTPUT);   //Define ultrasonic output feet

  //The servo is initialized to forward
  servo_appointed_detection(ServoPos);
  //Steering gear initialized to output mode
  pinMode(ServoPin, OUTPUT);

  //Define the left and right sensors as input interfaces
  pinMode(AvoidSensorLeft, INPUT);
  pinMode(AvoidSensorRight, INPUT);

  //Call the button scan function
  key_scan();
  
  while(1)
  {
   distance = Distance_test();        
   if (distance > 50  )   
   {
    
    LeftSensorValue = digitalRead(AvoidSensorLeft);
    RightSensorValue = digitalRead(AvoidSensorRight);

    if (LeftSensorValue == HIGH && RightSensorValue == LOW)
    {
      spin_left(200);
    }
    else if (RightSensorValue == HIGH && LeftSensorValue == LOW)
    {
      spin_right(200);
    }
    else if (RightSensorValue == LOW && LeftSensorValue == LOW)
    {
      spin_right(200);
    }
    
    run(50, 50);
    corlor_led(OFF, ON, OFF);
  }
  else if ((distance >= 30 && distance <= 50))
  {
    LeftSensorValue = digitalRead(AvoidSensorLeft);
    RightSensorValue = digitalRead(AvoidSensorRight);

    if (LeftSensorValue == HIGH && RightSensorValue == LOW)
    {
      spin_left(200); 
    }
    else if (RightSensorValue == HIGH && LeftSensorValue == LOW)
    {
      spin_right(200);
    }
    else if (RightSensorValue == LOW && LeftSensorValue == LOW)
    {
      spin_right(200);
    }
    run(36, 36);
  }
  else if (  distance < 30  )
  {
    servo_color_carstate();
  }
 }
return 1 ;
}