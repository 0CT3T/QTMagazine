#include "addtheme.h"

AddTheme::AddTheme()
{

    Dao = new ThemeDAO();

    QLabel *NameText = new QLabel("Name");
    NameEdit = new QLineEdit;
    QLabel*DepText = new QLabel("Depend");


    QList<Theme> listtheme = Dao->selectAll();
    QListIterator<Theme> i(listtheme);
    QStringList wordList;
    while(i.hasNext()){
        Theme tempo = i.next();
        wordList.append( tempo.getName());
        listid.append(tempo.getID());
    }

    QCompleter *completer = new QCompleter(wordList, this);
    completer->setCompletionMode(QCompleter::InlineCompletion);
    completer->setCaseSensitivity(Qt::CaseInsensitive);

    DepBox = new QComboBox;
    DepBox->setEditable(true);
    DepBox->setCompleter(completer);
    DepBox->addItems(wordList);


    QPushButton *button = new QPushButton("ADD");

    QObject::connect(button, SIGNAL(clicked()), this, SLOT(add()));

    QVBoxLayout *theme = new QVBoxLayout;
    theme->addWidget(NameText);
    theme->addWidget(NameEdit);
    theme->addWidget(DepText);
    theme->addWidget(DepBox);
    theme->addWidget(button);

    this->setLayout(theme);

}

void AddTheme::add()
{
    Theme *thememod ;

    if(this->DepBox->currentIndex()>=0)
        thememod = new Theme(this->NameEdit->text(),this->listid.at(this->DepBox->currentIndex()));
    else
        thememod = new Theme(this->NameEdit->text(),0);

    Dao->addTheme(*thememod);

    this->close();
}
