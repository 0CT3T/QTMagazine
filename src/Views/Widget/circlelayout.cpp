#include "circlelayout.h"

CircleLayout::CircleLayout()
{
    scene = new QGraphicsScene(this);
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
    QList<Theme> tempo = ThemeDAO::selectAllDepen(this->parent->getID());

    int articlesize = temp.size();
    int size = temp.size() + tempo.size();
    float rayon = fmin(this->width()/4,this->height()/4);
    float x = this->width()/2;
    float y = this->height()/2;

    for (int i = 0; i < articlesize;i++){
        float theta = (2*M_PI*i)/size;
        float x2 = x + (rayon*cos(theta));
        float y2 = y + (rayon*sin(theta));

        QGraphicsLineItem *Line = new QGraphicsLineItem(x,y,x2,y2);

        this->scene->addItem(Line);

        Article article = temp.at(i);
        this->ajoutBulle(x2,y2,article.getTitle(),ARTICLECOLOR);
    }

    for (int i = articlesize; i < size;i++){
        float theta = (2*M_PI*i)/size;
        float x2 = x + (rayon*cos(theta));
        float y2 = y + (rayon*sin(theta));

        QGraphicsLineItem *Line = new QGraphicsLineItem(x,y,x2,y2);

        this->scene->addItem(Line);

        Theme theme = tempo.at(i - articlesize);
        this->ajoutBulle(x2,y2,theme.getName(),THEMECOLOR);

    }


    this->ajoutBulle(x,y,this->parent->getName(),PARENTCOLOR);



    //Auto Size change
    QRectF rect = scene->itemsBoundingRect();
    this->scene->setSceneRect(rect);

}

void CircleLayout::scenechanged()
{
    paint();
}

void CircleLayout::ajoutBulle(float x, float y,QString text,QColor color)
{
    QGraphicsTextItem * itemText = new QGraphicsTextItem;
    itemText->setPlainText(text);
    itemText->setPos(x - itemText->boundingRect().width()/2,y - itemText->boundingRect().height()/2);

    QGraphicsEllipseItem * whiteEllipse = new QGraphicsEllipseItem;
    whiteEllipse->setRect(itemText->x() - SPACE,itemText->y() - SPACE,itemText->boundingRect().width() + 2*SPACE,itemText->boundingRect().height() + 2*SPACE);
    whiteEllipse->setBrush(QBrush(WHITE));
    whiteEllipse->setPen(QPen(-1));

    QGraphicsEllipseItem * itemEllipse = new QGraphicsEllipseItem;
    itemEllipse->setRect(itemText->x() - SPACE,itemText->y() - SPACE,itemText->boundingRect().width() + 2*SPACE,itemText->boundingRect().height() + 2*SPACE);
    itemEllipse->setBrush(QBrush(color));
    itemEllipse->setPen(QPen(-1));

    this->scene->addItem(whiteEllipse);
    this->scene->addItem(itemEllipse);
    this->scene->addItem(itemText);
}
