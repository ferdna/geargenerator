#ifndef DLGCONFIG_H
#define DLGCONFIG_H

#include <QDialog>
#include <QDebug>

#include "globals.h"

namespace Ui {
class dlgConfig;
}

class dlgConfig : public QDialog
{
    Q_OBJECT

public:
    explicit dlgConfig(QWidget *parent = 0);
    ~dlgConfig();

signals:
    void recvGridOptions();

private:
    Ui::dlgConfig *ui;

private slots:
    void dlgaccept();
    void nextprev();

};

#endif // DLGCONFIG_H
