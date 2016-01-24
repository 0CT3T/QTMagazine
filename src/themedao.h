#ifndef THEMDAO_H
#define THEMDAO_H

#include <QtSql>
#include <QtWidgets>
#include "theme.h"
#include "sqlconnector.h"

class ThemeDAO
{
private:
    SQLconnector *SQLiteHelper;
public:
   ThemeDAO();
   QVariant addTheme( Theme &theme);
};

#endif // THEMDAO_H
