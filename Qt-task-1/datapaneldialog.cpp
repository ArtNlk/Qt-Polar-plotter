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

void DataPanelDialog::setResolution(int resolution)
{
    ui.resolutionSpinbox->setValue(resolution);
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
    emit onSettingsChanged(ui.functionsComboBox->currentIndex(),ui.fromRadSpinbox->value(),ui.toRadSpinbox->value(), ui.resolutionSpinbox->value());
}


void DataPanelDialog::on_fromRadSpinbox_valueChanged(double arg1)
{
    ui.toRadSpinbox->setMinimum(arg1);
    if(this->isVisible())
    {
    emit onSettingsChanged(ui.functionsComboBox->currentIndex(),ui.fromRadSpinbox->value(),ui.toRadSpinbox->value(), ui.resolutionSpinbox->value());
    }
}


void DataPanelDialog::on_toRadSpinbox_valueChanged(double arg1)
{
    ui.fromRadSpinbox->setMaximum(arg1);
    if(this->isVisible())
    {
    emit onSettingsChanged(ui.functionsComboBox->currentIndex(),ui.fromRadSpinbox->value(),ui.toRadSpinbox->value(), ui.resolutionSpinbox->value());
    }
}

void DataPanelDialog::on_functionsComboBox_activated(int index)
{
    if(this->isVisible())
    {
    emit onSettingsChanged(ui.functionsComboBox->currentIndex(),ui.fromRadSpinbox->value(),ui.toRadSpinbox->value(), ui.resolutionSpinbox->value());
    }
}


void DataPanelDialog::on_resolutionSpinbox_valueChanged(int arg1)
{
    if(this->isVisible())
    {
    emit onSettingsChanged(ui.functionsComboBox->currentIndex(),ui.fromRadSpinbox->value(),ui.toRadSpinbox->value(), ui.resolutionSpinbox->value());
    }
}
