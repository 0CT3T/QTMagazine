#ifndef CIRCLELAYOUT_H
#define CIRCLELAYOUT_H


#include <QtGui>
#include <QList>
#include <QLayout>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <math.h>

#include "../../DAO/themedao.h"
#include "../../Model/theme.h"
#include "../../Model/article.h"

#define SPACE 10
#define PARENTCOLOR QColor(255,100,100,100)
#define ARTICLECOLOR QColor(100,255,100,100)
#define THEMECOLOR QColor(100,100,255,100)
#define WHITE QColor(255,255,255,255)


class CircleLayout : public QGraphicsView
{
    Q_OBJECT
public:
    explicit CircleLayout();
    void initlayout(Theme *theme);

private slots:
    void scenechanged();

private:
    void paint();
    void ajoutBulle(float x, float y,QString text,QColor color);

    Theme* parent;
    QGraphicsScene *scene;


};

#endif // CIRCLELAYOUT_H
