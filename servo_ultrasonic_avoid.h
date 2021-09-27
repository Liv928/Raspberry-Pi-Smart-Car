extern "C"{
  #include <wiringPi.h>
  #include <softPwm.h>
  #include <sys/time.h>
  #include <stdio.h>
  #include <stdlib.h>
}
void servo_pulse(int ServoPin, int myangle);
void servo_appointed_detection(int pos);
void servo_color_carstate();
void run(int leftSpeed,int rightSpeed);
void brake();
void left();
void right();
void spin_left(int time);
void spin_right(int time);
void back(int time);
void corlor_led(int v_iRed, int v_iGreen, int v_iBlue);
float Distance();
float Distance_test();
void bubble(unsigned long *a, int n);
void key_scan();