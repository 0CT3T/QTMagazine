#include "addmagazine.h"

AddMagazine::AddMagazine()
{

    QLabel *NameText = new QLabel("Name");
    NameEdit = new QLineEdit;
    QLabel*NumeroText = new QLabel("numero");
    numberEdit = new QSpinBox;

    //Ajout des noms
    QList<QString> listname = MagazineDAO::selectAllName();

    QListIterator<QString> i(listname);
    QStringList wordList;
    while(i.hasNext()){
        QString tempo = i.next();
        wordList.append( tempo);
    }

    QCompleter *completer = new QCompleter(wordList, this);
    completer->setCompletionMode(QCompleter::InlineCompletion);
    completer->setCaseSensitivity(Qt::CaseInsensitive);

    NameEdit->setCompleter(completer);

    QHBoxLayout *top = new QHBoxLayout;
    top->addWidget(NameText);
    top->addWidget(NumeroText);

    QHBoxLayout *bot = new QHBoxLayout;
    bot->addWidget(NameEdit);
    bot->addWidget(numberEdit);

    /*
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
    */


    QPushButton *button = new QPushButton("ADD");

    QObject::connect(button, SIGNAL(clicked()), this, SLOT(add()));

    QVBoxLayout *theme = new QVBoxLayout;
    theme->addLayout(top);
    theme->addLayout(bot);
    theme->addWidget(button);

    this->setLayout(theme);

}

void AddMagazine::add()
{
    Magazine *magazinemod ;

    if (this->NameEdit->text()!=""
            &&this->numberEdit->value()!=0){

        magazinemod = new Magazine(this->NameEdit->text(),this->numberEdit->value());
        MagazineDAO::addMagazine(*magazinemod);
    }

    this->close();
}
