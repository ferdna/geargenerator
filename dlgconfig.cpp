#include "dlgconfig.h"
#include "ui_dlgconfig.h"

#include "mainwindow.h"

dlgConfig::dlgConfig(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlgConfig)
{
    ui->setupUi(this);

    this->rejected();

    connect(ui->btn_cancel, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->btn_ok, SIGNAL(clicked()), this, SLOT(dlgaccept()));

    connect(ui->btn_prev, SIGNAL(clicked()), this, SLOT(nextprev()));
    connect(ui->btn_next, SIGNAL(clicked()), this, SLOT(nextprev()));

    // Animation Options.
    ui->aniEnabled->setChecked(mainOptions->animation.getEnabled());
    ui->aniSpeed->setValue(mainOptions->animation.getSpeed());

    // Grid Options.
    ui->cb_xvisible->setChecked(mainOptions->grid.getXvisible());
    ui->cb_yvisible->setChecked(mainOptions->grid.getYvisible());
    ui->cb_dvisible->setChecked(mainOptions->grid.getDvisible());

    ui->dsb_xorigin->setValue(mainOptions->grid.getXorigin());
    ui->dsb_yorigin->setValue(mainOptions->grid.getYorigin());

    ui->dsb_xspacing->setValue(mainOptions->grid.getXspacing());
    ui->dsb_yspacing->setValue(mainOptions->grid.getYspacing());

    //ui->cb_xcolor->cu
    //mainOptions->grid.setXcolor(QColor(ui->cb_xcolor->currentText()));
    //mainOptions->grid.setYcolor(QColor(ui->cb_ycolor->currentText()));
}

dlgConfig::~dlgConfig()
{
    delete ui;
}

void dlgConfig::nextprev()
{
    QPushButton *senderObj = qobject_cast<QPushButton *>(sender());
    if (senderObj->objectName() == "btn_next")
    {
        int curIdx1 = ui->stackedWidget->currentIndex();
        ui->stackedWidget->setCurrentIndex(( curIdx1 >= ui->stackedWidget->count())? curIdx1 : curIdx1+1);
    }

    if (senderObj->objectName() == "btn_prev")
    {
        int curIdx2 = ui->stackedWidget->currentIndex();
        ui->stackedWidget->setCurrentIndex(( curIdx2 >= 0)? curIdx2-1 : curIdx2);
    }
}

void dlgConfig::dlgaccept()
{
    qDebug() << "Options 'Ok' button pressed.";

    //if (ui->stackedWidget->currentWidget()->objectName() == "anisetup")
    //{
        mainOptions->animation.setEnabled(ui->aniEnabled->isChecked());
        mainOptions->animation.setSpeed(ui->aniSpeed->value());
    //}

    //if (ui->stackedWidget->currentWidget()->objectName() == "gridsetup")
    //{
        mainOptions->grid.setXvisible(ui->cb_xvisible->isChecked());
        mainOptions->grid.setYvisible(ui->cb_yvisible->isChecked());
        mainOptions->grid.setDvisible(ui->cb_dvisible->isChecked());

        mainOptions->grid.setXorigin(ui->dsb_xorigin->value());
        mainOptions->grid.setYorigin(ui->dsb_yorigin->value());

        mainOptions->grid.setXspacing(ui->dsb_xspacing->value());
        mainOptions->grid.setYspacing(ui->dsb_yspacing->value());

        mainOptions->grid.setXcolor(QColor(ui->cb_xcolor->currentText()));
        mainOptions->grid.setYcolor(QColor(ui->cb_ycolor->currentText()));

        emit recvGridOptions();
    //}

    this->accept();
}
