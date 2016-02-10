#ifndef START_H
#define START_H



#include <QWidget>

#include "Views/Dialogue/addarticle.h"
#include "Views/Widget/qtreetheme.h"
#include "Sqlite/sqlconnector.h"
#include "Views/Widget/circlelayout.h"
#include "color.h"




class start : public QMainWindow
{
Q_OBJECT

public:
    start();
    ~start();

private slots:
    void openModifier();
    void doubleclick(QTreeWidgetItem* index,int column);

private:


    //variable de classe
    QTreeTheme *TreeView;
    CircleLayout *graphlayout;

};

#endif // START_H
