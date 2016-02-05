#include "article.h"

Article::Article(QString title,QString description,int magID)
{
    this->title = title;
    this->description = description;
    this->magID = magID;
}

Article::Article(int ID,QString title,QString description,int magID)
{
    this->ID = ID;
    this->title = title;
    this->description = description;
    this->magID = magID;
}

int Article::getID(){
    return this->ID;
}

QString Article::getTitle(){
    return this->title;
}

QString Article::getDescription(){
    return this->description;
}

int Article::getmagID() {
    return this->magID;
}
