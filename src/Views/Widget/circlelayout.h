#ifndef CIRCLELAYOUT_H
#define CIRCLELAYOUT_H


#include <QtGui>
#include <QList>
#include <QLayout>

#include "../../Model/theme.h"

class CircleLayout : public QLayout
{
public:
    CircleLayout();
    ~CircleLayout();
    void initlayout(Theme theme);
    void addItem(QLayoutItem *item);
    QSize sizeHint() const;
    QSize minimumSize() const;
    int count() const;
    QLayoutItem *itemAt(int) const;
    QLayoutItem *takeAt(int);
    void setGeometry(const QRect &rect);

private:
    QList<QLayoutItem*> list;
};

#endif // CIRCLELAYOUT_H
