#ifndef QTREETHEME_H
#define QTREETHEME_H

#include <QWidget>
#include <QTreeWidget>
#include "addtheme.h"

class QTreeTheme : public QTreeWidget
{
public:
    QTreeTheme();
    void initTreeView();
private:
    void addChildren(QTreeWidgetItem *item,int ID);
};

#endif // QTREETHEME_H
