#ifndef ADDARTICLE_H
#define ADDARTICLE_H

#include "addtheme.h"
#include <QDialog>
#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QComboBox>
#include <QVBoxLayout>
#include <QObject>
#include <QCompleter>
#include <QTextEdit>
#include <addmagazine.h>
#include "qtreetheme.h"
#include "magazinedao.h"
#include "magazine.h"

class addArticle : public QDialog
{
Q_OBJECT

public:
    addArticle();



private:
    QLineEdit *TitleEdit;
    QTextEdit *DescriptionEdit;
    QLineEdit *MagEdit;
    QTreeTheme *TreeView;
    QList<int> listMagazine;
private slots:
    void openModifier();
    void openArticle();
};

#endif // ADDARTICLE_H
