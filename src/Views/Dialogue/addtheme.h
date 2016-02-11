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
    AddTheme(Theme theme);

private slots:
    void add();
    void update();
private:
    QLineEdit *NameEdit;
    QTreeTheme *TreeView;
    QPushButton *button;
    int ID;
    void initFrame();
};

#endif // ADDTHEME_H
