#ifndef START_H
#define START_H


#include <sqlconnector.h>


namespace Ui {
class start;
}

class start : public QMainWindow
{
    Q_OBJECT

public:
    explicit start(QWidget *parent = 0);
    ~start();

private:
    Ui::start *ui;
    SQLconnector *temp;
};

#endif // START_H
