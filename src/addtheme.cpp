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
        wordList.append( tempo.getName() + "." +  QString::number(tempo.getID()));
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
    int dep = 0;
    QStringList list  = DepBox->currentText().split(".");
    if(list.size()>=2)
        dep = list.at(1).toInt();


    qDebug() << this->NameEdit->text() + " " + QString::number(dep);
    Theme *thememod = new Theme(this->NameEdit->text(),dep);
    Dao->addTheme(*thememod);

    this->close();
}
