#ifndef MAGAZINE_H
#define MAGAZINE_H

#include <QWidget>


class Magazine
{
private:

    int ID;
    QString name;
    int numero;

public:
    Magazine(QString name,int depID);
    Magazine(int ID,QString name,int depID);
    int getID();
    QString getName();
    int getNum();
};

#endif // TYPE_H
