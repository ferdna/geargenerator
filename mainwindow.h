#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <gearobj.h>

#include <QDebug>

#include "globals.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    QGraphicsScene *mainScene;
    QGraphicsItemGroup *gridGroupV;
    QGraphicsItemGroup *gridGroupH;
    QGraphicsItemGroup *gridGroupD;
    gearObj *gear1;
    gearObj *gear2;
    QTimer *timer;

private slots:
    void showOptions();
    void toggleGrid();
    void testslot();
    void drawGrid();
    void showGrid();
    void hideGrid();
    void deleteGrid();
    void drawGear(int teeth, int adendum);
    void hideGear();
    void timer_update();

};

#endif // MAINWINDOW_H
