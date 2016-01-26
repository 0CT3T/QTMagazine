#include "sqlconnector.h"

SQLconnector::SQLconnector()
{
    if (!QSqlDatabase::drivers().contains("QSQLITE"));

        // initialize the database
        QSqlError err = this->initDb();
        if (err.type() != QSqlError::NoError) {
            showError(err);
            return;
        }

}

QVariant SQLconnector::addMagazine(QSqlQuery &q, const QString &title)
{
    q.addBindValue(title);
    q.exec();
    return q.lastInsertId();
}

QVariant SQLconnector::addArticle(QSqlQuery &q, const QString &name,const QString &description, const QVariant &MagazineID)
{
    q.addBindValue(name);
    q.addBindValue(description);
    q.addBindValue(MagazineID);
    q.exec();
    return q.lastInsertId();
}

QVariant SQLconnector::addTheme(QSqlQuery &q, const QString &name, const QVariant &ThemeID)
{
    q.addBindValue(name);
    q.addBindValue(ThemeID);
    q.exec();
    return q.lastInsertId();
}

QVariant SQLconnector::addLienTheme(QSqlQuery &q, const QVariant &ArticleID, const QVariant &ThemeID)
{
    q.addBindValue(ArticleID);
    q.addBindValue(ThemeID);
    q.exec();
    return q.lastInsertId();
}

QSqlError SQLconnector::initDb()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(  QDir::currentPath() + "/Data.sqlite" );

    if (!db.open())
        return db.lastError();

    QStringList tables = db.tables();
    if (tables.contains("Article", Qt::CaseInsensitive)
        && tables.contains("Magazine", Qt::CaseInsensitive)
        && tables.contains("LienTheme", Qt::CaseInsensitive)){
        db.close();
        return QSqlError();
    }

    QSqlQuery q;


    if (!q.exec(QLatin1String("create table Article(id integer primary key, name varchar, description varchar, magazine integer)")))
        return q.lastError();
    if (!q.exec(QLatin1String("create table Magazine(id integer primary key, name varchar)")))
        return q.lastError();
    if (!q.exec(QLatin1String("create table Theme(id integer primary key, name varchar, dependance integer)")))
        return q.lastError();
    if (!q.exec(QLatin1String("create table LienTheme(idArticle integer NOT NULL, idTheme integer NOT NULL, PRIMARY KEY ( idArticle, idTheme))"))){
        qDebug () << q.lastError();
        return q.lastError();
}


    if (!q.prepare(QLatin1String("insert into Magazine(name) values(?)")))
        return q.lastError();
    QVariant linuxId = addMagazine(q, QLatin1String("LINUX PRATIQUE N°93"));



    db.close();
    return QSqlError();
}

void SQLconnector::showError(const QSqlError &err)
{
    //QMessageBox::critical(this, "Unable to initialize Database","Error initializing database: " + err.text());
}

QSqlDatabase SQLconnector::getDatabase()
{
    return this->db;
}
