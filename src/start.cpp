#include "start.h"


start::start()
{
    SQLconnector *initdb = new SQLconnector();

    QPushButton *Modifier = new QPushButton("Modifier");
    QLineEdit *Edit = new QLineEdit;
    TreeView = new QTreeTheme;

    QObject::connect(Modifier, SIGNAL(clicked()), this, SLOT(openModifier()));
    QObject::connect(Edit,SIGNAL(textChanged(QString)),this,SLOT(search(QString)));


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


/*
 * SET BACKGROUND POUR TOUS LES ITEMS
 *
*/
void start::setBackground(QTreeWidgetItem *item, QColor color)
{
    item->setBackground(0,color);
    for( int i = 0; i < item->childCount(); ++i )
            setBackground( item->child(i),color );
}


/*
 * SEARCH IN THE TREEVIEW
 *
*/
void start::search(QString temp)
{
    setBackground(TreeView->invisibleRootItem(),Qt::white);
    if(temp!=""){
         QList<QTreeWidgetItem*> listWidget = TreeView->findItems(temp,Qt::MatchContains | Qt::MatchRecursive);
         foreach(QTreeWidgetItem* tempo,listWidget)
         {
             tempo->setBackgroundColor(0,QColor::fromRgba(qRgba(0,0,255,20)));
         }
    }


}

start::~start()
{

}

void start::openModifier()
{
    AddTheme w;
    w.exec();
    TreeView->initTreeView();
}
