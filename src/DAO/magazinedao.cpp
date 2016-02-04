#include "magazinedao.h"

MagazineDAO::MagazineDAO()
{

}

/*
 * AJJOUTEZ UN MAGAZINE
 *
*/
int MagazineDAO::addMagazine(Magazine &magazine)
{
    QSqlDatabase db = QSqlDatabase::database();
    if(db.open()){
        QSqlQuery q;
        q.prepare(QLatin1String("insert into Magazine(name,numero) values(?,?)"));

        q.addBindValue(magazine.getName());
        q.addBindValue(magazine.getNum());

        q.exec();

        db.close();
        return q.lastInsertId().toInt();
    }
    //fail to connect
    return -1;
}

/*
 * RECUPERER TOUTES LES DONNEES
 *
*/
QList<Magazine> MagazineDAO::selectAll()
{
    QList<Magazine> temp;
    QSqlDatabase db = QSqlDatabase::database();

    if(db.open()){

    QSqlQuery q;
    q.exec(QLatin1String("SELECT * FROM Magazine "));

    while (q.next()) {
            int ID = q.value(0).toInt();
            QString name = q.value(1).toString();
            int numero = q.value(2).toInt();
            Magazine *tempm = new Magazine(ID,name,numero);
            temp.append(*tempm);
        }

    db.close();
    }
    return temp;
}

/*
 * RECUPERER TOUS LES NOMS
 *
*/
QList<QString> MagazineDAO::selectAllName()
{
    QList<QString> temp;
    QSqlDatabase db = QSqlDatabase::database();

    if(db.open()){

    QSqlQuery q;
    q.exec(QLatin1String("SELECT DISTINCT * FROM Magazine "));

    while (q.next()) {
            QString name = q.value(1).toString();
            temp.append(name);
        }

    db.close();
    }
    return temp;
}
