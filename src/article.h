#ifndef ARTICLE_H
#define ARTICLE_H

#include <QWidget>


class Article
{
private:

    int ID;
    QString title;
    QString description;
    int magID;

public:
    Article(QString title,QString description,int magID);
    Article(int ID,QString title,QString description,int magID);
    int getID();
    QString getTitle();
    QString getDescription();
    int getmagID();
};

#endif // TYPE_H
