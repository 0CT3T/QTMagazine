#ifndef QTREETHEME_H
#define QTREETHEME_H

#include <QWidget>
#include <QTreeWidget>
#include <QHeaderView>
#include "../../Model/theme.h"
#include "../../DAO/themedao.h"

#include "../../color.h"

class QTreeTheme : public QTreeWidget
{
Q_OBJECT

public:
    QTreeTheme();
    void initTreeView();
    void select(QTreeWidgetItem *item, QList<int> list);
public slots:
    void search(QString temp);
private:
    void addChildren(QTreeWidgetItem *item,int ID);
    void setBackground(QTreeWidgetItem *item, QColor color);
};

#endif // QTREETHEME_H
