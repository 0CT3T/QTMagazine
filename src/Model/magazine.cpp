#include "magazine.h"

Magazine::Magazine(QString name,int numero)
{
    this->name = name;
    this->numero = numero;
}

Magazine::Magazine(int ID,QString name,int numero)
{
    this->ID = ID;
    this->name = name;
    this->numero = numero;
}

int Magazine::getID()
{
    return this->ID;
}

QString Magazine::getName()
{
    return this->name;
}

int Magazine::getNum()
{
    return this->numero;
}
