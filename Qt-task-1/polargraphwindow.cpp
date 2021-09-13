#include "polargraphwindow.h"

PolarGraphWindow::PolarGraphWindow(QWidget *parent) : QMainWindow(parent)
{
    ui.setupUi(this);

    functions.append(new ArchSpiralFunc());
    functions.append(new ButterflyFunc());

    dataPanel.setFunctions(functions);
    dataPanel.show();
}
