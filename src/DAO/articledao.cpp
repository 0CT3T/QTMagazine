#include "articledao.h"

articledao::articledao()
{

}

/*
 * AJJOUTEZ UN ARTICLE
 *
*/
int articledao::addArticle(Article &article)
{
    QSqlDatabase db = QSqlDatabase::database();
    if(db.open()){
        QSqlQuery q;

        q.prepare(QLatin1String("insert into Article(name,description,magazine) values(?,?,?)"));
        q.addBindValue(article.getTitle());
        q.addBindValue(article.getDescription());
        q.addBindValue(article.getmagID());

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
QList<Article> articledao::selectAll()
{
    QList<Article> temp;
    QSqlDatabase db = QSqlDatabase::database();

    if(db.open()){

    QSqlQuery q;
    q.exec(QLatin1String("SELECT * FROM Article "));

    while (q.next()) {
            int ID = q.value(0).toInt();
            QString title = q.value(1).toString();
            QString description = q.value(2).toString();
            int nummag = q.value(3).toInt();
            Article *tempm = new Article(ID,title,description,nummag);
            temp.append(*tempm);
        }

    db.close();
    }
    return temp;
}


