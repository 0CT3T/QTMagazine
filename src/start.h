#ifndef START_H
#define START_H


#include <sqlconnector.h>
#include <QWidget>



class start : public QMainWindow
{

public:
    start();
    ~start();

private:
    SQLconnector *temp;
};

#endif // START_H
