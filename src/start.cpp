#include "start.h"


start::start()
{
    SQLconnector *initdb = new SQLconnector();

    QPushButton *Modifier = new QPushButton("Ajouter Article");

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

    QObject::connect(TreeView, SIGNAL(itemClicked(QTreeWidgetItem*,int)),this, SLOT(doubleclick(QTreeWidgetItem*,int)));



    QVBoxLayout *theme = new QVBoxLayout;
    theme->addWidget(Edit);
    theme->addWidget(TreeView);
    theme->addWidget(Modifier);
    theme->setMargin(0);
    theme->setSpacing(0);

    graphlayout = new CircleLayout();

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addLayout(theme);
    layout->addWidget(graphlayout);

    layout->setSpacing(0);
    layout->setMargin(0);


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

void start::doubleclick(QTreeWidgetItem* index,int column)
{
    Theme *theme = new Theme(index->text(1).toInt(),index->text(0));
    graphlayout->initlayout(theme);
}
