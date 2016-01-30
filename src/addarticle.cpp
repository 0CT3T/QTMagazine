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

    //Ajout completer magazine
    QList<Magazine> listname = MagazineDAO::selectAll();

    QListIterator<Magazine> i(listname);
    QStringList wordList;
    while(i.hasNext()){
        Magazine tempo = i.next();
        wordList.append( tempo.getName() + " N°"+ QString::number(tempo.getNum()));
        this->listMagazine.append(tempo.getID());
    }

    QCompleter *completer = new QCompleter(wordList, this);
    completer->setCompletionMode(QCompleter::InlineCompletion);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    MagEdit->setCompleter(completer);

    QPushButton *Modifier = new QPushButton("Ajouter");
    QPushButton *AjTheme = new QPushButton("Ajout theme");
    QPushButton *AjMagazine = new QPushButton("Ajout Magazine");

    QObject::connect(AjTheme, SIGNAL(clicked()), this, SLOT(openModifier()));
    QObject::connect(AjMagazine, SIGNAL(clicked()), this, SLOT(openArticle()));

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

void addArticle::openArticle()
{
    AddMagazine w;
    w.exec();
}
