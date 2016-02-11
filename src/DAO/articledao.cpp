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

        q.prepare(QLatin1String("insert into Article(name,description,page,magazine) values(?,?,?,?)"));
        q.addBindValue(article.getTitle());
        q.addBindValue(article.getDescription());
        q.addBindValue(article.getPage());
        q.addBindValue(article.getmagID());

        q.exec();

        db.close();
        return q.lastInsertId().toInt();
    }
    //fail to connect
    return -1;
}


/*
 * UPDATE UN ARTICLE
 *
*/
int articledao::updateArticle(Article &article)
{
    QSqlDatabase db = QSqlDatabase::database();
    if(db.open()){
        QSqlQuery q;

        q.prepare(QLatin1String("UPDATE Article SET name = ?, description = ?, page = ?,magazine = ? WHERE ID = ?"));
        q.addBindValue(article.getTitle());
        q.addBindValue(article.getDescription());
        q.addBindValue(article.getPage());
        q.addBindValue(article.getmagID());
        q.addBindValue(article.getID());

        q.exec();

        db.close();
        return article.getID();
    }
    //fail to connect
    return -1;
}

/*
 * GET WITH ID
 *
*/
Article articledao::getwithID(int ID)
{
    Article *tempm;
    QSqlDatabase db = QSqlDatabase::database();
    if(db.open()){
        QSqlQuery q;

        q.prepare(QLatin1String("SELECT * FROM Article where ID = ? "));
        q.addBindValue(ID);

        q.exec();

        while (q.next()) {
                int ID = q.value(0).toInt();
                QString title = q.value(1).toString();
                QString description = q.value(2).toString();
                int page = q.value(3).toInt();
                int nummag = q.value(4).toInt();
                tempm = new Article(ID,title,description,page,nummag);
            }
        q.exec();

        db.close();
    }
    return (*tempm);
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
            int page = q.value(3).toInt();
            int nummag = q.value(4).toInt();
            Article *tempm = new Article(ID,title,description,page,nummag);
            temp.append(*tempm);
        }

    db.close();
    }
    return temp;
}


