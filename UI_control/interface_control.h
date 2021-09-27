#ifndef INTERFACE_CONTROL_H
#define INTERFACE_CONTROL_H

#include <QMainWindow>

namespace Ui {
class interface_control;
}

class interface_control : public QMainWindow
{
    Q_OBJECT

public:
    explicit interface_control(QWidget *parent = 0);
    ~interface_control();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_2_pressed();

    void on_pushButton_5_pressed();

    void on_pushButton_3_pressed();

    void on_pushButton_6_pressed();

private:
    Ui::interface_control *ui;
};

#endif // INTERFACE_CONTROL_H
