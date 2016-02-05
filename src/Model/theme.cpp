#include "theme.h"

Theme::Theme(QString name,int depID)
{
    this->name = name;
    this->depID = depID;
}

Theme::Theme(int ID,QString name,int depID)
{
    this->ID = ID;
    this->name = name;
    this->depID = depID;
}

Theme::Theme(int ID,QString name)
{
    this->ID = ID;
    this->name = name;
}

int Theme::getID()
{
    return this->ID;
}

QString Theme::getName()
{
    return this->name;
}

int Theme::getDep()
{
    return this->depID;
}
