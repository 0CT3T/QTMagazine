#include "start.h"


start::start()
{
    SQLconnector *initdb = new SQLconnector();

    QPushButton *Modifier = new QPushButton("Modifier");

    //completer liste de choix
    QList<Theme> listtheme = ThemeDAO::selectAll();
    QListIterator<Theme> i(listtheme);
    QStringList wordList;
    while(i.hasNext()){
        Theme tempo = i.next();
        wordList.append( tempo.getName());
    }

    QCompleter *completer = new QCompleter(wordList, this);
    completer->setCompletionMode(QCompleter::InlineCompletion);
    completer->setCaseSensitivity(Qt::CaseInsensitive);

    QLineEdit *Edit = new QLineEdit;
    Edit->setCompleter(completer);
    TreeView = new QTreeTheme;

    QObject::connect(Modifier, SIGNAL(clicked()), this, SLOT(openModifier()));
    QObject::connect(Edit,SIGNAL(textChanged(QString)),TreeView,SLOT(search(QString)));


    QVBoxLayout *theme = new QVBoxLayout;
    theme->addWidget(Edit);
    theme->addWidget(TreeView);
    theme->addWidget(Modifier);

    //QLayout *graphlayout = new QLayout;

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addLayout(theme);
    //layout->addLayout(graphlayout);


    QWidget *test = new QWidget;
    test->setLayout(layout);
    this->resize(800, 600);
    this->setCentralWidget(test);

}




start::~start()
{

}

void start::openModifier()
{
    addArticle w;
    w.exec();
    TreeView->initTreeView();
}
