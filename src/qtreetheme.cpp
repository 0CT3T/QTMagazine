#include "qtreetheme.h"

QTreeTheme::QTreeTheme()
{
    this->initTreeView();
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
