#include "start.h"


start::start()
{
    SQLconnector *initdb = new SQLconnector();

    QPushButton *Modifier = new QPushButton("Modifier");
    QLineEdit *Edit = new QLineEdit;
    TreeView = new QTreeWidget;
    this->initTreeView();

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
 * INITIALISATION DU TREEVIEW DE THEME
*/
void start::initTreeView()
{

    TreeView->clear();
    TreeView->setColumnCount(1);
    TreeView->setHeaderLabel("Theme");

    //Recuperer tous les parents
    QList<Theme> listtheme = ThemeDAO::selectAllDepen(0);
    QListIterator<Theme> i(listtheme);

    while(i.hasNext()){
        Theme tempo = i.next();
        QTreeWidgetItem *item = new QTreeWidgetItem(TreeView,QStringList(tempo.getName()));

        this->addChildren(item,tempo.getID());
    }
}

/*
 *AJOUTER TREE ITEM RECURSIF
 *
*/
void start::addChildren(QTreeWidgetItem *item,int ID)
{
    QList<Theme> listtheme = ThemeDAO::selectAllDepen(ID);
    QListIterator<Theme> i(listtheme);
    while(i.hasNext()){
        Theme tempo = i.next();
        QTreeWidgetItem *itemtemp = new QTreeWidgetItem(item,QStringList(tempo.getName()));

        this->addChildren(itemtemp,tempo.getID());
    }
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
    this->initTreeView();
}
