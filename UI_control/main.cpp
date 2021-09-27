#include "interface_control.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    interface_control w;
    w.show();

    return a.exec();
}
