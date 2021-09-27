# Raspberry Pi Smart Car Project

This project is about making matching programs for remote control car. There are 7 different functions come true. 

(1) Users can start the car, then the car is able to move forward, backward, lfet and right automatically according to the route set by the program. 

(2) Users can turn on the color lights.

(3) Users can control the car do movement by cammand line in terminal.

(4) Users can control the camera to move up, down, left and right.

(5) Users can make LED lights controlled by steering gear, make them show different colors in different position.

(6) Users can use infrared to avoid the bstacle.

(7) Users can use ultrasonic obstacle avoidance with servo head(sound measurement first, and then avoid).

## Motivation

Use Raspbreey pi make a remote control car and give it several functions.

## Installation

If not work with a standard Raspbian systems, please install [wiringpi](https://github.com/WiringPi/WiringPi.git) with command git clone then enter the clone responsitory run " ./build " to install the dynamic library

## Code example

```c++
extern "C"{
	#include <wiringPi.h>
	#include <softPwm.h>
}
#include <iostream>

using namespace std;
```

