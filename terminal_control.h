/**
* @file         terminal_control.h
* @author       Yu Wu
* @date         2019.11.27
* @brief        input commands on terminal to control the car to move	
*/

#ifndef TERMINAL_CONTROL_H
#define TERMINAL_CONTROL_H

extern "C"{
#include <wiringPi.h>
#include <softPwm.h>
}
#include <iostream>

/**
 * @brief car moves forward
 */
void run(int time);

/**
 * @brief car moves back
 */
void back(int time);

/**
 * @brief car moves left
 */
void left(int time);

/**
 * @brief car moves right
 */
void right(int time);

/**
 * @brief stop car move
 */
void brake();

/**
 * @brief get input commands from user
 */
char get_command(void);

#endif