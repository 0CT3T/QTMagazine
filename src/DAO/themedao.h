#ifndef THEMDAO_H
#define THEMDAO_H

#include <QtSql>
#include <QtWidgets>
#include "../Model/theme.h"
#include "../Model/article.h"
#include "../Sqlite/sqlconnector.h"

class ThemeDAO
{
private:
public:
   ThemeDAO();
   static int addTheme( Theme &theme);
   static QList<Theme> selectAll();
   static QList<Theme> selectAllDepen(int ID);
   static QList<Article> selectAllArticle(int ID);
   static int updateTheme(Theme &theme);
   static Theme selectAllwithID(int ID);
};

#endif // THEMDAO_H
