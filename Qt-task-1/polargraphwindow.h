#ifndef POLARGRAPHWINDOW_H
#define POLARGRAPHWINDOW_H

#include <QMainWindow>
#include <QVector>

#include "polarfunc.h"
#include "datapaneldialog.h"

#include "ui_PolarGraphWindow.h"
class PolarGraphWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit PolarGraphWindow(QWidget *parent = nullptr);

signals:


private:
    Ui::PolarGraphWindow ui;
    DataPanelDialog dataPanel;
    QVector<PolarFunction*> functions;
};

#endif // POLARGRAPHWINDOW_H
