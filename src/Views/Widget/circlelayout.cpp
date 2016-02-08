#include "circlelayout.h"

CircleLayout::CircleLayout()
{
    scene = new QGraphicsScene(this);
    QObject::connect(this,SIGNAL(resizeEvent()),this,SLOT(scenechanged()));
    this->setScene(scene);
}

void CircleLayout::initlayout(Theme *theme)
{
    //this->themes= theme;
    this->parent = theme;
    this->paint();
}

void CircleLayout::paint()
{

    this->scene->clear();

    QList<Article> temp = ThemeDAO::selectAllArticle(this->parent->getID());

    int size = temp.size();
    float rayon = fmin(this->width()/4,this->height()/4);
    float x = this->width()/2;
    float y = this->height()/2;
    qDebug() << QString::number(x) + "@" + QString::number(y);

    for (int i = 0; i < size;i++){
        float theta = (2*M_PI*i)/size;
        qDebug() << QString::number(theta) + "|" + QString::number(cos(theta)) + "-" + QString::number(rayon*cos(theta));
        float x2 = x + (rayon*cos(theta));
        float y2 = y + (rayon*sin(theta));
        qDebug() << QString::number(x2) + "-" + QString::number(y2);
        QGraphicsLineItem *Line = new QGraphicsLineItem(x,y,x2,y2);
        this->scene->addItem(Line);

        Article article = temp.at(i);

        QGraphicsTextItem * itemText = new QGraphicsTextItem;
        itemText->setPlainText(article.getTitle());
        itemText->setPos(x2 - itemText->boundingRect().width()/2,y2 - itemText->boundingRect().height()/2);

        QGraphicsEllipseItem * whiteEllipse = new QGraphicsEllipseItem;
        whiteEllipse->setRect(itemText->x() - SPACE,itemText->y() - SPACE,itemText->boundingRect().width() + 2*SPACE,itemText->boundingRect().height() + 2*SPACE);
        whiteEllipse->setBrush(QBrush(WHITE));
        whiteEllipse->setPen(QPen(-1));

        QGraphicsEllipseItem * itemEllipse = new QGraphicsEllipseItem;
        itemEllipse->setRect(itemText->x() - SPACE,itemText->y() - SPACE,itemText->boundingRect().width() + 2*SPACE,itemText->boundingRect().height() + 2*SPACE);
        itemEllipse->setBrush(QBrush(ARTICLECOLOR));
        itemEllipse->setPen(QPen(-1));

        this->scene->addItem(whiteEllipse);
        this->scene->addItem(itemEllipse);
        this->scene->addItem(itemText);
        qDebug() << article.getTitle();
    }


    QGraphicsTextItem * parentText = new QGraphicsTextItem;
    parentText->setPlainText(this->parent->getName());

    parentText->setPos(x-parentText->boundingRect().width()/2,y-parentText->boundingRect().height()/2);

    QGraphicsEllipseItem * whiteEllipse = new QGraphicsEllipseItem;
    whiteEllipse->setRect(parentText->x() - SPACE,parentText->y() - SPACE,parentText->boundingRect().width() + 2*SPACE,parentText->boundingRect().height() + 2*SPACE);
    whiteEllipse->setBrush(QBrush(WHITE));
    whiteEllipse->setPen(QPen(-1));

    QGraphicsEllipseItem * parentEllipse = new QGraphicsEllipseItem;
    parentEllipse->setRect(parentText->x() - SPACE,parentText->y() - SPACE,parentText->boundingRect().width() + 2*SPACE,parentText->boundingRect().height() + 2*SPACE);
    parentEllipse->setBrush(QBrush(THEMECOLOR));
    parentEllipse->setPen(QPen(-1));

    this->scene->addItem(whiteEllipse);
    this->scene->addItem(parentEllipse);
    this->scene->addItem(parentText);

    //Auto Size change
    QRectF rect = scene->itemsBoundingRect();
    this->scene->setSceneRect(rect);

}

void CircleLayout::scenechanged()
{
    paint();
}

