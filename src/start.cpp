#include "start.h"


start::start()
{
    SQLconnector *initdb = new SQLconnector();

    QPushButton *Modifier = new QPushButton("Modifier");
    QTreeView *TreeView = new QTreeView;
    QLineEdit *Edit = new QLineEdit;

    QObject::connect(Modifier, SIGNAL(clicked()), this, SLOT(openModifier()));


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
    AddTheme w;
    w.exec();
}
