#include "datapaneldialog.h"

DataPanelDialog::DataPanelDialog(QWidget *parent) : QDialog(parent)
{
    ui.setupUi(this);
}

void DataPanelDialog::setPlotLimits(float fromRad, float toRad)
{

}

void DataPanelDialog::setFunctions(QVector<PolarFunction*> functions)
{
    ui.functionsComboBox->clear();
    for(const PolarFunction* funcPtr : functions)
    {
        ui.functionsComboBox->addItem(QString::fromStdString(funcPtr->getName()));
    }
}
