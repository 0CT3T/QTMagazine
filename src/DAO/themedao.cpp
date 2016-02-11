#include "themedao.h"

/*
 * Constructeur inutile
*/
ThemeDAO::ThemeDAO()
{
}


/*
 * AJJOUTEZ UN THEME
 *
*/
int ThemeDAO::addTheme(Theme &theme)
{
    QSqlDatabase db = QSqlDatabase::database();
    if(db.open()){
        QSqlQuery q;
        q.prepare(QLatin1String("insert into Theme(name,dependance) values(?,?)"));

        q.addBindValue(theme.getName());
        q.addBindValue(theme.getDep());

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
int ThemeDAO::updateTheme(Theme &theme)
{
    QSqlDatabase db = QSqlDatabase::database();
    if(db.open()){
        QSqlQuery q;

        q.prepare(QLatin1String("UPDATE THEME SET name = ?, dependance = ? WHERE id = ?"));

        q.addBindValue(theme.getName());
        q.addBindValue(theme.getDep());
        q.addBindValue(theme.getID());

        q.exec();

        db.close();
        return theme.getID();
    }
    //fail to connect
    return -1;
}

/*
 * RECUPERER TOUTES LES DONNEES AVEC ID
 *
*/
Theme ThemeDAO::selectAllwithID(int ID)
{
    Theme *temp;
    QSqlDatabase db = QSqlDatabase::database();

    if(db.open()){

    QSqlQuery q;
    q.prepare(QLatin1String("SELECT * FROM Theme WHERE id = ? "));
    q.addBindValue(ID);
    q.exec();

    while (q.next()) {
            int ID = q.value(0).toInt();
            QString name = q.value(1).toString();
            int depID = q.value(2).toInt();
            temp = new Theme(ID,name,depID);

        }

    db.close();
    }
    return *temp;
}


/*
 * RECUPERER TOUTES LES DONNEES
 *
*/
QList<Theme> ThemeDAO::selectAll()
{
    QList<Theme> temp;
    QSqlDatabase db = QSqlDatabase::database();

    if(db.open()){

    QSqlQuery q;
    q.exec(QLatin1String("SELECT * FROM Theme "));

    while (q.next()) {
            int ID = q.value(0).toInt();
            QString name = q.value(1).toString();
            int depID = q.value(2).toInt();
            Theme *tempt = new Theme(ID,name,depID);
            temp.append(*tempt);
        }

    db.close();
    }
    return temp;
}

/*
 * RECUPERER TOUTES LES DONNEES DEPENDANTE D'UN ID
 * @param
*/
QList<Theme> ThemeDAO::selectAllDepen(int ID)
{
    QList<Theme> temp;
    QSqlDatabase db = QSqlDatabase::database();

    if(db.open()){

    QSqlQuery q;
    q.prepare(QLatin1String("SELECT * FROM Theme WHERE dependance = ? ORDER BY name ASC"));
    q.addBindValue(ID);

    q.exec();

    while (q.next()) {
            int ID = q.value(0).toInt();
            QString name = q.value(1).toString();
            int depID = q.value(2).toInt();
            Theme *tempt = new Theme(ID,name,depID);
            temp.append(*tempt);
        }

    db.close();
    }
    return temp;
}

/*
 * RECUPERER TOUS LES ARTICLES
 * @param
*/
QList<Article> ThemeDAO::selectAllArticle(int ID)
{
    QList<Article> temp;
    QSqlDatabase db = QSqlDatabase::database();

    if(db.open()){

    QSqlQuery q;
    q.prepare(QLatin1String("SELECT Article.id, Article.name, Article.description,Article.page, Article.magazine FROM Theme,LienTheme,Article WHERE Theme.id = ? AND LienTheme.idTheme = Theme.id AND LienTheme.idArticle = Article.id ORDER BY Article.name ASC"));
    q.addBindValue(ID);

    q.exec();

    while (q.next()) {
            int ID = q.value(0).toInt();
            QString name = q.value(1).toString();
            QString description = q.value(2).toString();
            int page = q.value(3).toInt();
            int magID = q.value(4).toInt();
            Article *tempt = new Article(ID,name,description,page,magID);
            temp.append(*tempt);
        }

    db.close();
    }
    return temp;
}
