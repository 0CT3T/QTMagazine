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
