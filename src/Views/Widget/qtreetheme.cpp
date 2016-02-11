#include "qtreetheme.h"

QTreeTheme::QTreeTheme()
{
    this->initTreeView();
    this->setFrameShape(QFrame::NoFrame);

}

/*
 * INITIALISATION DU TREEVIEW DE THEME
*/
void QTreeTheme::initTreeView()
{


    this->clear();
    this->setColumnCount(2);
    this->header()->hide();
    this->hideColumn(1);




    //Recuperer tous les parents
    QList<Theme> listtheme = ThemeDAO::selectAllDepen(0);
    QListIterator<Theme> i(listtheme);

    while(i.hasNext()){
        Theme tempo = i.next();

        QTreeWidgetItem *item = new QTreeWidgetItem(this);
        item->setText(0,tempo.getName());
        item->setText(1,QString::number(tempo.getID()));


        item->setExpanded(true);
        this->addChildren(item,tempo.getID());
    }

    this->resizeColumnToContents(0);
}

/*
 *AJOUTER TREE ITEM RECURSIF
 *
*/
void QTreeTheme::addChildren(QTreeWidgetItem *item,int ID)
{
    QList<Theme> listtheme = ThemeDAO::selectAllDepen(ID);
    QListIterator<Theme> i(listtheme);
    while(i.hasNext()){
        Theme tempo = i.next();
        QTreeWidgetItem *itemtemp = new QTreeWidgetItem(item);
        itemtemp->setText(0,tempo.getName());
        itemtemp->setText(1,QString::number(tempo.getID()));

        itemtemp->setExpanded(true);
        this->addChildren(itemtemp,tempo.getID());
    }
}

/*
 * SET BACKGROUND POUR TOUS LES ITEMS
 *
*/
void QTreeTheme::setBackground(QTreeWidgetItem *item, QColor color)
{
    item->setBackground(0,color);
    for( int i = 0; i < item->childCount(); ++i )
            setBackground( item->child(i),color );
}


/*
 * SELECT ITEMS
 *
*/
void QTreeTheme::select(QTreeWidgetItem *item, QList<int> list)
{
    if(list.contains(item->text(1).toInt())){
        item->setSelected(true);
    }
    for( int i = 0; i < item->childCount(); ++i )
            select( item->child(i),list );
}

/*
 * SEARCH IN THE TREEVIEW
 *
*/
void QTreeTheme::search(QString temp)
{
    setBackground(this->invisibleRootItem(),TREEBACKGROUND);
    if(temp!=""){
         QList<QTreeWidgetItem*> listWidget = this->findItems(temp,Qt::MatchContains | Qt::MatchRecursive);
         foreach(QTreeWidgetItem* tempo,listWidget)
         {
             tempo->setBackgroundColor(0,TREEITEM);
         }
    }
}
