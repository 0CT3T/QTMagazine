#include "addtheme.h"

AddTheme::AddTheme()
{
    QLabel *ArticleText = new QLabel("Article");
    ArticleText->setAlignment(Qt::AlignHCenter);
    QFont font = ArticleText->font();
    font.setBold(true);
    ArticleText->setFont(font);

    QLabel *NameText = new QLabel("Name");
    NameEdit = new QLineEdit;
    QLabel*DepText = new QLabel("Depend");

    TreeView = new QTreeTheme();


    QPushButton *button = new QPushButton("ADD");

    QObject::connect(button, SIGNAL(clicked()), this, SLOT(add()));

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
