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

    QGridLayout *content = new QGridLayout;


    content->addWidget(NameText,0,0);
    content->addWidget(NumeroText,0,1);


    content->addWidget(NameEdit,1,0);
    content->addWidget(numberEdit,1,1);

    QPushButton *button = new QPushButton("ADD");

    QObject::connect(button, SIGNAL(clicked()), this, SLOT(add()));

    QVBoxLayout *theme = new QVBoxLayout;
    theme->addLayout(content);
    theme->addWidget(button);

    this->resize(800, 200);
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
