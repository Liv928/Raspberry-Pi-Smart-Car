#include "interface_control.h"
#include "ui_interface_control.h"
#include "wiringPi.h"
#include "wiringSerial.h"
#include "softPwm.h"

//define pin
static int Left_motor_forward = 28;       //left moter move forward connect to pin 28 with Pi
static int Left_motor_backward = 29;     //left moter move backward connect to pin 29 with Pi

static int Right_motor_forward = 24;      //right moter move forward connect to pin 24 with Pi
static int Right_motor_backward = 25;    //left moter move backward connect to pin 25 with Pi

static int Left_motor_pwm = 27;      //pin 27 controls speed of the car, with left moter
static int Right_motor_pwm = 23;     //pin 23 controls speed of the car, with right moter

interface_control::interface_control(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::interface_control)
{
    ui->setupUi(this);
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
}

interface_control::~interface_control()
{
    delete ui;
}

//button for brake
void interface_control::on_pushButton_4_clicked()
{
    digitalWrite(Left_motor_forward, LOW);
    digitalWrite(Left_motor_backward, LOW);
    digitalWrite(Right_motor_forward, LOW);
    digitalWrite(Right_motor_backward, LOW);

    delay(300);
}

//button for forward
void interface_control::on_pushButton_2_pressed()
{
    digitalWrite(Left_motor_forward, HIGH);
    digitalWrite(Left_motor_backward, LOW);
    softPwmWrite(Left_motor_pwm, 150);   //control tire's speed


    digitalWrite(Right_motor_forward, HIGH);
    digitalWrite(Right_motor_backward, LOW);
    softPwmWrite(Right_motor_pwm, 150);

    delay(200);
    digitalWrite(Right_motor_forward, LOW);
    digitalWrite(Left_motor_forward, LOW);
}

void interface_control::on_pushButton_5_pressed()
{
    digitalWrite(Left_motor_forward, LOW);
    digitalWrite(Left_motor_backward, HIGH);
    softPwmWrite(Left_motor_pwm, 150);

    digitalWrite(Right_motor_forward, LOW);
    digitalWrite(Right_motor_backward, HIGH);
    softPwmWrite(Right_motor_pwm, 150);

    delay(200);
    digitalWrite(Right_motor_backward, LOW);
    digitalWrite(Left_motor_backward, LOW);
}

//button for left
void interface_control::on_pushButton_3_pressed()
{
    digitalWrite(Left_motor_forward, LOW);
    digitalWrite(Left_motor_backward, HIGH); //left moter move back
    softPwmWrite(Left_motor_pwm, 150);


    digitalWrite(Right_motor_forward, HIGH);    // right moter move forward
    digitalWrite(Right_motor_backward, LOW);
    softPwmWrite(Right_motor_pwm, 150);


    delay(200);
    digitalWrite(Left_motor_backward, LOW);
    digitalWrite(Right_motor_forward, LOW);
}

//button for right
void interface_control::on_pushButton_6_pressed()
{
    digitalWrite(Left_motor_forward, HIGH);
    digitalWrite(Left_motor_backward, LOW);
    softPwmWrite(Left_motor_pwm, 100);

    digitalWrite(Right_motor_forward, LOW);
    digitalWrite(Right_motor_backward, LOW);
    softPwmWrite(Right_motor_pwm, 70);

    delay(200);
    digitalWrite(Left_motor_forward, LOW);
}
