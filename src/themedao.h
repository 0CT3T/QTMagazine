#ifndef THEMDAO_H
#define THEMDAO_H

#include <QtSql>
#include <QtWidgets>
#include "theme.h"
#include "sqlconnector.h"

class ThemeDAO
{
private:
public:
   ThemeDAO();
   int addTheme( Theme &theme);
   QList<Theme> selectAll();
};

#endif // THEMDAO_H
