#ifndef ADDTHEME_H
#define ADDTHEME_H

#include <QDialog>
#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QObject>
#include <QCompleter>
#include <QLatin1String>
#include <stdexcept>

#include "../Widget/qtreetheme.h"
#include "../../Model/theme.h"
#include "../../DAO/themedao.h"

class AddTheme : public QDialog
{
Q_OBJECT

public:
    AddTheme();

private slots:
    void add();
private:
    QLineEdit *NameEdit;
    QTreeTheme *TreeView;
};

#endif // ADDTHEME_H
