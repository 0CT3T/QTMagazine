#ifndef START_H
#define START_H


#include <sqlconnector.h>
#include <QWidget>
#include "addtheme.h"


class start : public QMainWindow
{
Q_OBJECT

public:
    start();
    ~start();

private slots:
    void openModifier();
    void search(QString temp);
private:
    void initTreeView();
    void addChildren(QTreeWidgetItem *item,int ID);
    void setBackground(QTreeWidgetItem *item, QColor color);

    //variable de classe
    QTreeWidget *TreeView;

};

#endif // START_H
