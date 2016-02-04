#ifndef SQLCONNECTOR_H
#define SQLCONNECTOR_H


#include <QtSql>
#include <QtWidgets>


class SQLconnector
{
public:
    SQLconnector();
    QVariant addMagazine(QSqlQuery &q, const QString &title);
    QVariant addArticle(QSqlQuery &q, const QString &name,const QString &description, const QVariant &MagazineID);
    QVariant addTheme(QSqlQuery &q, const QString &name, const QVariant &ThemeID);
    QVariant addLienTheme(QSqlQuery &q, const QVariant &ArticleID, const QVariant &ThemeID);
    QSqlError initDb();
    QSqlDatabase getDatabase();
    void showError(const QSqlError &err);

    QSqlDatabase db;
};

#endif // SQLCONNECTOR_H
