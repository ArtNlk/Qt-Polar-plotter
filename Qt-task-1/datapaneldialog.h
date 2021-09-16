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
    void onSettingsChanged(int vectorIndex, double fromRad, double toRad, int resolution);

public slots:
    void setPlotLimits(double fromRad, double toRad);
    void setResolution(int resolution);
    void setFunctions(QVector<PolarFunction*> functions);

private slots:
    void on_buttonBox_accepted();

    void on_fromRadSpinbox_valueChanged(double arg1);

    void on_toRadSpinbox_valueChanged(double arg1);

    void on_functionsComboBox_activated(int index);

    void on_resolutionSpinbox_valueChanged(int arg1);

private:
    Ui::DataPanelDialog ui;

};

#endif // DATAPANELDIALOG_H
