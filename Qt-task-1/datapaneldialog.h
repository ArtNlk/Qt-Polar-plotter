#ifndef DATAPANELDIALOG_H
#define DATAPANELDIALOG_H

#include <QDialog>
#include <QVector>
#include "polarfunc.h"

#include "ui_DataPanelDialog.h"
class DataPanelDialog : public QDialog
{
    Q_OBJECT
public:
    DataPanelDialog(QWidget *parent = nullptr);

signals:
    void onSettingsChanged(int vectorIndex, double fromRad, double toRad);

public slots:
    void setPlotLimits(double fromRad, double toRad);
    void setFunctions(QVector<PolarFunction*> functions);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DataPanelDialog ui;

};

#endif // DATAPANELDIALOG_H
