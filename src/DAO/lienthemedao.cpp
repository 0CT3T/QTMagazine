#include "lienthemedao.h"

lienthemeDAO::lienthemeDAO()
{

}

/*
 * AJJOUTEZ UN LIEN ENTRE THEME
 *
*/
int lienthemeDAO::addLienTheme(LienTheme &lientheme)
{
    QSqlDatabase db = QSqlDatabase::database();
    if(db.open()){
        QSqlQuery q;

        q.prepare(QLatin1String("insert into LienTheme(idArticle,idTheme) values(?,?)"));
        q.addBindValue(lientheme.getartID());
        q.addBindValue(lientheme.getthemeID());

        q.exec();

        db.close();
        return q.lastInsertId().toInt();
    }
    //fail to connect
    return -1;
}

/*
 * DELETE ITEM WITH AN ARTICLE ID
 *
*/
int lienthemeDAO::deleteAllArticle(int ID)
{
    QSqlDatabase db = QSqlDatabase::database();
    if(db.open()){
        QSqlQuery q;

        q.prepare(QLatin1String("DELETE FROM LienTheme WHERE idArticle = ?"));
        q.addBindValue(ID);

        q.exec();

        db.close();
        return ID;
    }
    //fail to connect
    return -1;
}

/*
 * RECUPERER TOUTES LES DONNEES
 *
*/
QList<LienTheme> lienthemeDAO::selectAll()
{
    QList<LienTheme> temp;
    QSqlDatabase db = QSqlDatabase::database();

    if(db.open()){

    QSqlQuery q;
    q.exec(QLatin1String("SELECT * FROM LienTheme "));

    while (q.next()) {
            int artID = q.value(0).toInt();
            int themeID = q.value(1).toInt();
            LienTheme *tempm = new LienTheme(artID,themeID);
            temp.append(*tempm);
        }

    db.close();
    }
    return temp;
}

/*
 * RECUPERER TOUTES LES DONNEES AVEC ARTICLE
 *
*/
QList<int> lienthemeDAO::selectAllwithArticle(int ID)
{
    QList<int> temp;
    QSqlDatabase db = QSqlDatabase::database();

    if(db.open()){

    QSqlQuery q;
    q.prepare(QLatin1String("SELECT * FROM LienTheme WHERE idArticle = ?"));
    q.addBindValue(ID);
    q.exec();

    while (q.next()) {
            temp.append(q.value(1).toInt());
        }

    db.close();
    }
    return temp;
}
