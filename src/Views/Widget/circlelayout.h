#ifndef CIRCLELAYOUT_H
#define CIRCLELAYOUT_H


#include <QtGui>
#include <QList>
#include <QLayout>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <math.h>

#include "../../DAO/themedao.h"
#include "../../DAO/articledao.h"
#include "../../Model/theme.h"
#include "../../Model/article.h"
#include "../Dialogue/addarticle.h"
#include "../../color.h"

#define SPACE 10

class CustomEllipse : public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT

private:
    int ID;
    QString name = "";
public:
    void setID(int value){
        ID = value;
    }
    void setName(QString value){
        name=value;
    }

signals:
    void keypress(int,QString);
    void keypress(int);


protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event)
    {
        if(event->button() == Qt::LeftButton){
            if (name!="")
                emit keypress(ID,name);
            else
                emit keypress(ID);
        }
    }
};

class CircleLayout : public QGraphicsView
{
    Q_OBJECT

public:
    explicit CircleLayout();
    void initlayout(Theme *theme);

private slots:
    void scenechanged(int ID);
    void themechange(int ID,QString name);
    void resize();

 signals:
    void resizeEvent();

private:
    void paint();
    void ajoutBulle(float x, float y, QString text, QColor color, CustomEllipse *itemEllipse);

    Theme* parent = NULL;
    QGraphicsScene *scene;

protected:
    void mousePressEvent(QMouseEvent *event)
    {
        QGraphicsView::mousePressEvent(event);
    }

    void resizeEvent(QResizeEvent *event)
    {
        emit resizeEvent();
    }




};



#endif // CIRCLELAYOUT_H
