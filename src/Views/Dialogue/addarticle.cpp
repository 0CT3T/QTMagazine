#include "addarticle.h"

addArticle::addArticle()
{

    QLabel *ArticleText = new QLabel("Article");
    QLabel *TitleText = new QLabel("Titre");
    TitleEdit = new QLineEdit;
    QLabel*DescriptionText = new QLabel("Description");
    DescriptionEdit = new QTextEdit;
    QLabel*MagText = new QLabel("Magazine");
    MagEdit = new QComboBox;
    QLabel*pageText = new QLabel("Page");
    page = new QSpinBox();
    this->initMagazine();


    QHBoxLayout *lastgrouptext = new QHBoxLayout;
    lastgrouptext->addWidget(pageText);
    lastgrouptext->addWidget(MagText);

    QHBoxLayout *lastgroup = new QHBoxLayout;
    lastgroup->addWidget(page);
    lastgroup->addWidget(MagEdit);

    QPushButton *Modifier = new QPushButton("Ajouter");
    QPushButton *AjTheme = new QPushButton("Ajout theme");
    QPushButton *AjMagazine = new QPushButton("Ajout Magazine");

    QObject::connect(AjTheme, SIGNAL(clicked()), this, SLOT(openModifier()));
    QObject::connect(AjMagazine, SIGNAL(clicked()), this, SLOT(openArticle()));
    QObject::connect(Modifier, SIGNAL(clicked()), this, SLOT(Ajouter()));

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
    theme->addLayout(lastgrouptext);
    theme->addLayout(lastgroup);
    theme->addLayout(bouton);

    TreeView = new QTreeTheme();
    TreeView->setSelectionMode(QAbstractItemView::MultiSelection);

    QHBoxLayout *back = new QHBoxLayout;
    back->addLayout(theme);
    back->addWidget(TreeView);

    this->resize(1000, 600);
    this->setLayout(back);
}

void addArticle::initMagazine()
{
    MagEdit->clear();
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
    MagEdit->setEditable(true);
    MagEdit->addItems(wordList);
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
    this->initMagazine();

}

void addArticle::Ajouter()
{
    Article *articlemod ;

    if (this->TitleEdit->text()!=""
            && this->DescriptionEdit->toPlainText()!=""
            && this->listMagazine.at(this->MagEdit->currentIndex())!=0
            && this->page->value()!=0){


        articlemod = new Article(this->TitleEdit->text(),this->DescriptionEdit->toPlainText(),this->page->value(),this->listMagazine.at(this->MagEdit->currentIndex()));

        int ID = articledao::addArticle(*articlemod);

        LienTheme *lientheme;

        if(!this->TreeView->selectedItems().isEmpty()){
            QList<QTreeWidgetItem*> listWidget = this->TreeView->selectedItems();
            foreach (QTreeWidgetItem *item, listWidget)
            {
                lientheme = new LienTheme(ID,item->text(1).toInt());
                lienthemeDAO::addLienTheme(*lientheme);
            }
        }
        //selection
    }

    this->close();


}
