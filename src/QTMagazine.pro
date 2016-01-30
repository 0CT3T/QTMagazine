

QT       += core gui sql widgets
INCLUDEPATH += .

TARGET = QTMagazine
TEMPLATE = app
SOURCES += main.cpp start.cpp sqlconnector.cpp \
    theme.cpp \
    themedao.cpp \
    addtheme.cpp \
    qtreetheme.cpp \
    addarticle.cpp \
    magazine.cpp \
    article.cpp \
    lientheme.cpp \
    magazinedao.cpp \
    addmagazine.cpp
HEADERS  += start.h sqlconnector.h \
    theme.h \
    themedao.h \
    addtheme.h \
    qtreetheme.h \
    addarticle.h \
    magazine.h \
    article.h \
    lientheme.h \
    magazinedao.h \
    addmagazine.h
FORMS    +=


wince {
    CONFIG(debug, debug|release):sqlPlugins.files = $$QT_BUILD_TREE/plugins/sqldrivers/*d4.dll
    CONFIG(release, debug|release):sqlPlugins.files = $$QT_BUILD_TREE/plugins/sqldrivers/*[^d]4.dll
    sqlPlugins.path = sqldrivers
    DEPLOYMENT += sqlPlugins
}
