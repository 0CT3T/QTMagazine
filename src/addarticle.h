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

#include "addtheme.h"
#include "qtreetheme.h"

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
private slots:
    void openModifier();
};

#endif // ADDARTICLE_H
