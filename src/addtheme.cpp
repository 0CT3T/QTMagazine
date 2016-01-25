#include "addtheme.h"

AddTheme::AddTheme()
{

    QLabel *NameText = new QLabel("Name");
    NameEdit = new QLineEdit;
    QLabel*DepText = new QLabel("Depend");

    QStringList wordList;
    wordList << "alpha" << "omega" << "omicron" << "zeta";
    QCompleter *completer = new QCompleter(wordList, this);

    DepBox = new QComboBox;
    DepBox->setEditable(true);
    DepBox->setCompleter(completer);


    QPushButton *button = new QPushButton("ADD");

    QObject::connect(button, SIGNAL(clicked()), this, SLOT(add()));

    QVBoxLayout *theme = new QVBoxLayout;
    theme->addWidget(NameText);
    theme->addWidget(NameEdit);
    theme->addWidget(DepText);
    theme->addWidget(DepBox);
    theme->addWidget(button);

    this->setLayout(theme);

    /*QWidget *test = new QWidget;
    test->setLayout(theme);
    this->setCentralWidget(test);*/

}

void AddTheme::add()
{
    Theme *thememod = new Theme(this->NameEdit->text(),0);
    ThemeDAO *Dao = new ThemeDAO() ;
    Dao->addTheme(*thememod);

    this->close();
}
