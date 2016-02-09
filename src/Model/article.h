#ifndef ARTICLE_H
#define ARTICLE_H

#include <QWidget>


class Article
{
private:

    int ID;
    QString title;
    QString description;
    int page;
    int magID;

public:
    Article(QString title,QString description,int page,int magID);
    Article(int ID,QString title,QString description,int page,int magID);
    int getID();
    QString getTitle();
    QString getDescription();
    int getPage();
    int getmagID();
};

#endif // TYPE_H
