#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <wiringPi.h>
#include <softPwm.h>

//define pin
static int Left_motor_forward = 28;       //left moter move forward connect to pin 28 with Pi
static int Left_motor_backward = 29;     //left moter move backward connect to pin 29 with Pi

static int Right_motor_forward = 24;      //right moter move forward connect to pin 24 with Pi
static int Right_motor_backward = 25;    //left moter move backward connect to pin 25 with Pi

static int Left_motor_pwm = 27;      //pin 27 controls speed of the car, with left moter
static int Right_motor_pwm = 23;     //pin 23 controls speed of the car, with right moter

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
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

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //write HIGH or LOW to a digital pin
       //HIGH indicate activate, LOW indicate deactivate
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

void MainWindow::on_pushButton_2_clicked()
{
    digitalWrite(Left_motor_forward, LOW);
    digitalWrite(Left_motor_backward, LOW);
    digitalWrite(Right_motor_forward, LOW);
    digitalWrite(Right_motor_backward, LOW);

    delay(300);
}


void MainWindow::on_pushButton_3_clicked()
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

void MainWindow::on_pushButton_4_clicked()
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

void MainWindow::on_pushButton_5_clicked()
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
