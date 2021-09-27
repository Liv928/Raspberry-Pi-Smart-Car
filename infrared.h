#include <stdio.h>
#include <stdlib.h>
extern "C"{
    #include <wiringPi.h>
    #include <softPwm.h>
}
void run();
void brake(int time);
void left();
void right();
void left_motor_forward(int sp);
void left_motor_backward(int sp);
void right_motor_forward(int sp);
void right_motor_backward(int sp);
void spin_left(int time);
void spin_right(int time);
void back(int time);
void key_scan();
int main();