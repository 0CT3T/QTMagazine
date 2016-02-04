#ifndef ADDARTICLE_H
#define ADDARTICLE_H


#include <QDialog>
#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QComboBox>
#include <QVBoxLayout>
#include <QObject>
#include <QCompleter>
#include <QTextEdit>

#include "../Widget/qtreetheme.h"
#include "../../DAO/magazinedao.h"
#include "../../Model/magazine.h"
#include "addtheme.h"
#include "addmagazine.h"


class addArticle : public QDialog
{
Q_OBJECT

public:
    addArticle();



private:
    QLineEdit *TitleEdit;
    QTextEdit *DescriptionEdit;
    QComboBox *MagEdit;
    QTreeTheme *TreeView;
    QList<int> listMagazine;
private slots:
    void openModifier();
    void openArticle();
};

#endif // ADDARTICLE_H
