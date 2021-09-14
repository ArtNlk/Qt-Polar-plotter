#include "datapaneldialog.h"

DataPanelDialog::DataPanelDialog(QWidget *parent) : QDialog(parent)
{
    ui.setupUi(this);
}

void DataPanelDialog::setPlotLimits(double fromRad, double toRad)
{
    ui.fromRadSpinbox->setValue(fromRad);
    ui.toRadSpinbox->setValue(toRad);
}

void DataPanelDialog::setFunctions(QVector<PolarFunction*> functions)
{
    ui.functionsComboBox->clear();
    for(const PolarFunction* funcPtr : functions)
    {
        ui.functionsComboBox->addItem(QString::fromStdString(funcPtr->getName()));
    }
}

void DataPanelDialog::on_buttonBox_accepted()
{
    emit onSettingsChanged(ui.functionsComboBox->currentIndex(),ui.fromRadSpinbox->value(),ui.toRadSpinbox->value());
}

