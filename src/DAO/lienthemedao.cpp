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
