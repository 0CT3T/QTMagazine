#ifndef ADDMAGAZINE_H
#define ADDMAGAZINE_H

#include <QDialog>
#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QObject>
#include <QCompleter>
#include "magazine.h"
#include "magazinedao.h"

class AddMagazine : public QDialog
{
Q_OBJECT

public:
    AddMagazine ();

private slots:
    void add();
private:
    QLineEdit *NameEdit;
    QSpinBox *numberEdit;

};

#endif // ADDTHEME_H
