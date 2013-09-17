#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "dlgconfig.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionE_xit, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->actionGrid_Lines, SIGNAL(triggered()), this, SLOT(toggleGrid()));
    connect(ui->action_Options, SIGNAL(triggered()), this, SLOT(showOptions()));

    connect(ui->gB_Gear1, SIGNAL(toggled(bool)), this, SLOT(hideGear()));
    connect(ui->gB_Gear2, SIGNAL(toggled(bool)), this, SLOT(hideGear()));

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timer_update()));

    mainScene = new QGraphicsScene();
    ui->graphicsView->setScene(mainScene);

    gridGroupV = NULL;
    gridGroupH = NULL;
    gridGroupD = NULL;
    gear1 = NULL;
    gear2 = NULL;

    drawGear(8,8);
    timer->start(100);

    gear1->setPos(100,100);
    gear2->setPos(300,100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timer_update()
{
    gear1->setRotation(gear1->rotation() + 10);
    gear2->setRotation(gear2->rotation() + 10);
}

void MainWindow::showOptions()
{
    qDebug() << "Show Options Dialog.";
    dlgConfig *newOptions = new dlgConfig(this);
    connect(newOptions, SIGNAL(recvGridOptions()), this, SLOT(drawGrid()));
    newOptions->exec();
}

//1px = 0.264583333 mm
//1px = 0.026458333 cm
//1px = 0.010416667 in
void MainWindow::drawGear(int teeth, int adendum)
{
    gear1 = new gearObj();
    gear2 = new gearObj();
    mainScene->addItem(gear1);
    mainScene->addItem(gear2);
}

void MainWindow::hideGear()
{
    QGroupBox *senderObj = qobject_cast<QGroupBox *>(sender());
    if (senderObj->objectName() == "gB_Gear1" && senderObj->isChecked())
        gear1->setVisible(true);
    else gear1->setVisible(true);

    if (senderObj->objectName() == "gB_Gear2" && senderObj->isChecked())
        gear2->setVisible(false);
    else gear2->setVisible(false);
}

void MainWindow::toggleGrid()
{
    if (ui->actionGrid_Lines->isChecked())
        showGrid();

    if (!ui->actionGrid_Lines->isChecked())
        hideGrid();
}

void MainWindow::showGrid()
{
    if (gridGroupV != NULL)
        gridGroupV->show();
    if (gridGroupH != NULL)
        gridGroupH->show();
    if (gridGroupD != NULL)
        gridGroupD->show();
}

void MainWindow::hideGrid()
{
    if (gridGroupV != NULL)
        gridGroupV->hide();
    if (gridGroupH != NULL)
        gridGroupH->hide();
    if (gridGroupD != NULL)
        gridGroupD->hide();
}

void MainWindow::deleteGrid()
{
    //must delete object... currently only removing from scene...
    if (gridGroupV != NULL)
        mainScene->removeItem(gridGroupV);
    if (gridGroupH != NULL)
        mainScene->removeItem(gridGroupH);
    if (gridGroupH != NULL)
        mainScene->removeItem(gridGroupD);
}

void MainWindow::drawGrid()
{
    deleteGrid();

    // X Axis = Horizontal.
    if (mainOptions->grid.getXvisible())
    {
        QList<QGraphicsItem*> gXLines;
        for (int x=0; x<=ui->graphicsView->width(); x+=mainOptions->grid.getXspacing())
            if(x >= mainOptions->grid.getXorigin())
            {
                QGraphicsLineItem *newLineX = new QGraphicsLineItem(x,0,x,ui->graphicsView->height()-1);
                newLineX->setPen(QPen(mainOptions->grid.getXcolor(), 1));
                gXLines.append(newLineX);
            }
        gridGroupV = mainScene->createItemGroup(gXLines);
        gridGroupV->setZValue(-1);

    }

    // Y Axis = Vertical.
    if (mainOptions->grid.getYvisible())
    {
        QList<QGraphicsItem*> gYLines;
        for (int y=0; y<=ui->graphicsView->height(); y+=mainOptions->grid.getYspacing())
            if(y >= mainOptions->grid.getYorigin())
            {
                QGraphicsLineItem *newLineY = new QGraphicsLineItem(0,y,ui->graphicsView->width()-1,y);
                newLineY->setPen(QPen(mainOptions->grid.getYcolor(), 1));
                gYLines.append(newLineY);
            }
        gridGroupH = mainScene->createItemGroup(gYLines);
        gridGroupH->setZValue(-1);
    }

    //TODO: still working on this.
    // Diagonal Grid Lines.
    if (mainOptions->grid.getDvisible())
    {
        QList<QGraphicsItem*> gDLines;
        for (int d=0; d<=ui->graphicsView->width(); d+=mainOptions->grid.getXspacing())
        {
            QGraphicsLineItem *newLineD = new QGraphicsLineItem(0,d,d,0);
            newLineD->setPen(QPen(mainOptions->grid.getXcolor(), 1));
            gDLines.append(newLineD);
        }
        gridGroupD = mainScene->createItemGroup(gDLines);
        gridGroupD->setZValue(-1);
    }
}

void MainWindow::testslot()
{
    qDebug() << "test slot";
}
