

QT       += core gui sql widgets
INCLUDEPATH += .

include(Sqlite/Sqlite.pri)
include(DAO/Dao.pri)
include(Model/Model.pri)
include(Views/Views.pri)

TARGET = QTMagazine
TEMPLATE = app
SOURCES += main.cpp start.cpp
HEADERS  += start.h


wince {
    CONFIG(debug, debug|release):sqlPlugins.files = $$QT_BUILD_TREE/plugins/sqldrivers/*d4.dll
    CONFIG(release, debug|release):sqlPlugins.files = $$QT_BUILD_TREE/plugins/sqldrivers/*[^d]4.dll
    sqlPlugins.path = sqldrivers
    DEPLOYMENT += sqlPlugins
}
