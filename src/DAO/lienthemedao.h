#ifndef LIENTHEMEDAO_H
#define LIENTHEMEDAO_H


#include <QtSql>
#include <QtWidgets>
#include "../Model/lientheme.h"
#include "../Sqlite/sqlconnector.h"

class lienthemeDAO
{
public:
    lienthemeDAO();
    static int addLienTheme(LienTheme &lientheme);
    static QList<LienTheme> selectAll();
};

#endif // LIENTHEMEDAO_H
