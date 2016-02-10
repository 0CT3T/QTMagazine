

#include "start.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    start w;

    QFile file(":/style.qss");
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        a.setStyleSheet(file.readAll());
        file.close();
    }


    w.show();

    return a.exec();
}
