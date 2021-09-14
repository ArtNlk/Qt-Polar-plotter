#include <QApplication>

#include "polargraphwindow.h"
#include "datapaneldialog.h"

#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    PolarGraphWindow *mainWindow =new PolarGraphWindow;
    mainWindow->show();
//    DataPanelDialog* dialog = new DataPanelDialog;
//    dialog->show();

    return a.exec();
}
