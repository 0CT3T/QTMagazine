#include "themedao.h"


ThemeDAO::ThemeDAO()
{

}


QVariant ThemeDAO::addTheme(Theme &theme)
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(  QDir::currentPath() + "/Data.sqlite" );

    db.open();

    QSqlQuery q;
    q.prepare(QLatin1String("insert into Theme(name,dependance) values(?,?)"));

    q.addBindValue(theme.getName());
    q.addBindValue(theme.getDep());

    q.exec();

    db.close();

    return q.lastInsertId();


}
