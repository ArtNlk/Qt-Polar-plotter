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
    void onSettingsChanged(int vectorIndex, float fromRad, float toRad);

public slots:
    void setPlotLimits(float fromRad, float toRad);
    void setFunctions(QVector<PolarFunction*> functions);

private:
    Ui::DataPanelDialog ui;

};

#endif // DATAPANELDIALOG_H
