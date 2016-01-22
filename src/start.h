#ifndef START_H
#define START_H


#include <sqlconnector.h>



class start : public QMainWindow
{

public:
    start();
    ~start();

private:
    SQLconnector *temp;
};

#endif // START_H
