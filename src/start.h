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

};

#endif // START_H
