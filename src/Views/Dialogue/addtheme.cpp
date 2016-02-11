#include "addtheme.h"

AddTheme::AddTheme(){
    this->initFrame();

    QObject::connect(button, SIGNAL(clicked()), this, SLOT(add()));
}

AddTheme::AddTheme(Theme theme){

    this->initFrame();
    //set data
    this->ID = theme.getID();
    this->NameEdit->setText(theme.getName());

    QList<int> list;
    list.append(theme.getDep());
    this->TreeView->select(this->TreeView->invisibleRootItem(),list);

    QObject::connect(button, SIGNAL(clicked()), this, SLOT(update()));
}

void AddTheme::initFrame(){
    QLabel *ArticleText = new QLabel("Theme");
    ArticleText->setAlignment(Qt::AlignHCenter);
    QFont font = ArticleText->font();
    font.setBold(true);
    ArticleText->setFont(font);

    QLabel *NameText = new QLabel("Name");
    NameEdit = new QLineEdit;
    QLabel*DepText = new QLabel("Depend");

    TreeView = new QTreeTheme();


    this->button = new QPushButton("AJOUTER");



    QVBoxLayout *theme = new QVBoxLayout;
    theme->addWidget(ArticleText);
    theme->addWidget(NameText);
    theme->addWidget(NameEdit);
    theme->addWidget(DepText);
    theme->addWidget(TreeView);
    theme->addWidget(button);

    theme->setMargin(0);
    theme->setSpacing(0);

    this->setLayout(theme);
    this->resize(800, 600);
}

void AddTheme::add()
{
    Theme *thememod ;

    if(!this->TreeView->selectedItems().isEmpty()){
        QList<QTreeWidgetItem*> listWidget = this->TreeView->selectedItems();
        QTreeWidgetItem *item = listWidget.at(0);
        thememod = new Theme(this->NameEdit->text(),item->text(1).toInt());
    }
    else
        thememod = new Theme(this->NameEdit->text(),0);

    ThemeDAO::addTheme(*thememod);

    this->close();
}

void AddTheme::update()
{
    Theme *thememod ;

    if(!this->TreeView->selectedItems().isEmpty()){
        QList<QTreeWidgetItem*> listWidget = this->TreeView->selectedItems();
        QTreeWidgetItem *item = listWidget.at(0);
        thememod = new Theme(this->ID,this->NameEdit->text(),item->text(1).toInt());
    }
    else
        thememod = new Theme(this->ID,this->NameEdit->text(),0);

    ThemeDAO::updateTheme(*thememod);

    this->close();
}
