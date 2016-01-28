#ifndef START_H
#define START_H


#include <sqlconnector.h>
#include <QWidget>
#include "addtheme.h"
#include "qtreetheme.h"


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
    void setBackground(QTreeWidgetItem *item, QColor color);

    //variable de classe
    QTreeTheme *TreeView;

};

#endif // START_H
