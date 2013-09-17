#ifndef GLOBALS_H
#define GLOBALS_H

#include <QString>
#include <QColor>

struct gridOptions {
private:
    bool XVisible;
    bool YVisible;
    bool DVisible;
    float Xorigin;
    float Yorigin;
    float Xspacing;
    float Yspacing;
    QColor Xcolor;
    QColor Ycolor;
    int munits;

public:
    bool getXvisible() { return XVisible; }
    void setXvisible(bool visible) { XVisible = visible; }

    bool getYvisible() { return YVisible; }
    void setYvisible(bool visible) { YVisible = visible; }

    bool getDvisible() { return DVisible; }
    void setDvisible(bool visible) { DVisible = visible; }

    float getXorigin() { return Xspacing; }
    void setXorigin(float origin) { Xspacing = origin; }

    float getYorigin() { return Yspacing; }
    void setYorigin(float origin) { Yspacing = origin; }

    float getXspacing() { return Xspacing; }
    void setXspacing(float spacing) { Xspacing = spacing; }

    float getYspacing() { return Yspacing; }
    void setYspacing(float spacing) { Yspacing = spacing; }

    QColor getXcolor() { return Xcolor; }
    void setXcolor(QColor color) { Xcolor = color; }

    QColor getYcolor() { return Ycolor; }
    void setYcolor(QColor color) { Ycolor = color; }

    int getUnits() { return munits; }
    void setUnits(int units) { munits = units; }

    //drawGrid(double hspacing, double vspacing, double horigin, double vorigin, QColor hcolor, QColor vcolor);
};

struct animationOptions {
private:
    bool varEnabled;
    float varSpeed;

public:
    bool getEnabled() { return varEnabled; }
    void setEnabled(bool enable) { varEnabled = enable; }

    float getSpeed() { return varSpeed; }
    void setSpeed(float speed) { varSpeed = speed; }
};

struct MainOptions {
private:
    bool _test;

public:
    animationOptions animation;
    gridOptions grid;
    bool getTest() { return _test; }
    void setTest(bool test) { _test = test; }

};

extern MainOptions *mainOptions;

#endif // GLOBALS_H
