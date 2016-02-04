#include "lientheme.h"

LienTheme::LienTheme(int artID,int themeID)
{
    this->artID = artID;
    this->themeID = themeID;
}

int LienTheme::getartID() {
    return this->artID;
}

int LienTheme::getthemeID() {
    return this->themeID;
}
