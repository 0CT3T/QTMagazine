#ifndef ARTICLEDAO_H
#define ARTICLEDAO_H


#include <QtSql>
#include <QtWidgets>
#include "../Model/article.h"
#include "../Sqlite/sqlconnector.h"

class articledao
{
public:
    articledao();
    static int addArticle( Article &article);
    static QList<Article> selectAll();
};

#endif // ARTICLEDAO_H
