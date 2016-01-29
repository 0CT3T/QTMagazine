#ifndef START_H
#define START_H


#include <sqlconnector.h>
#include <QWidget>
#include "addarticle.h"
#include "qtreetheme.h"


class start : public QMainWindow
{
Q_OBJECT

public:
    start();
    ~start();

private slots:
    void openModifier();

private:


    //variable de classe
    QTreeTheme *TreeView;

};

#endif // START_H
