#ifndef MAGAZINEDAO_H
#define MAGAZINEDAO_H

#include <QtSql>
#include <QtWidgets>
#include "magazine.h"
#include "sqlconnector.h"

class MagazineDAO
{
private:
public:
   MagazineDAO();
   static int addMagazine( Magazine &magazine);
   static QList<Magazine> selectAll();
   static QList<QString> selectAllName();
};

#endif // THEMDAO_H
