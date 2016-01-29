#include "addarticle.h"

addArticle::addArticle()
{

    QLabel *ArticleText = new QLabel("Article");
    QLabel *TitleText = new QLabel("Titre");
    TitleEdit = new QLineEdit;
    QLabel*DescriptionText = new QLabel("Description");
    DescriptionEdit = new QTextEdit;
    QLabel*MagText = new QLabel("Magazine");
    MagEdit = new QLineEdit;


    QPushButton *Modifier = new QPushButton("Ajouter");
    QPushButton *AjTheme = new QPushButton("Ajout theme");
    QPushButton *AjMagazine = new QPushButton("Ajout Magazine");

    QObject::connect(AjTheme, SIGNAL(clicked()), this, SLOT(openModifier()));

    QHBoxLayout *bouton = new QHBoxLayout;
    bouton->addWidget(Modifier);
    bouton->addWidget(AjTheme);
    bouton->addWidget(AjMagazine);

    QVBoxLayout *theme = new QVBoxLayout;
    theme->addWidget(ArticleText);
    theme->addWidget(TitleText);
    theme->addWidget(TitleEdit);
    theme->addWidget(DescriptionText);
    theme->addWidget(DescriptionEdit);
    theme->addWidget(MagText);
    theme->addWidget(MagEdit);
    theme->addLayout(bouton);

    TreeView = new QTreeTheme();
    TreeView->setSelectionMode(QAbstractItemView::MultiSelection);

    QHBoxLayout *back = new QHBoxLayout;
    back->addLayout(theme);
    back->addWidget(TreeView);

    this->setLayout(back);
}

void addArticle::openModifier()
{
    AddTheme w;
    w.exec();
    TreeView->initTreeView();
}
