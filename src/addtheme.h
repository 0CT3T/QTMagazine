#ifndef ADDTHEME_H
#define ADDTHEME_H

#include <QDialog>
#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QComboBox>
#include <QVBoxLayout>
#include <QPushButton>
#include <QObject>
#include <QCompleter>
#include "theme.h"
#include "themedao.h"
#include <QLatin1String>

class AddTheme : public QDialog
{
Q_OBJECT

public:
    AddTheme();

private slots:
    void add();
private:
    QLineEdit *NameEdit;
    QComboBox *DepBox;
};

#endif // ADDTHEME_H
