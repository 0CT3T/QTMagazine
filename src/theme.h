#ifndef TYPE_H
#define TYPE_H

#include <QWidget>


class Theme
{
private:

    int ID;
    QString name;
    int depID;

public:
    Theme(QString name,int depID);
    Theme(int ID,QString name,int depID);
    int getID();
    QString getName();
    int getDep();
};

#endif // TYPE_H
