#ifndef LIENTHEME_H
#define LIENTHEME_H

#include <QWidget>


class LienTheme
{
private:

    int artID;
    int themeID;

public:
    LienTheme(int artID,int themeID);
    int getartID();
    int getthemeID();
};

#endif // TYPE_H
