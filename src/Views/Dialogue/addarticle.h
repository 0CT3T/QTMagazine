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
#include "../../Model/article.h"
#include "../../DAO/articledao.h"
#include "../../Model/lientheme.h"
#include "../../DAO/lienthemedao.h"
#include "addtheme.h"
#include "addmagazine.h"


class addArticle : public QDialog
{
Q_OBJECT

public:
    addArticle();
    addArticle(Article article);

private:
    QLineEdit *TitleEdit;
    QTextEdit *DescriptionEdit;
    QComboBox *MagEdit;
    QSpinBox *page;
    QTreeTheme *TreeView;
    QList<int> listMagazine;
    void initMagazine();
    void initFrame();

private slots:
    void openModifier();
    void openArticle();
    void Ajouter();
};

#endif // ADDARTICLE_H
