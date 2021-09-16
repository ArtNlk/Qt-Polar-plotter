#include "polargraphwindow.h"

#include <QDebug>
#include <QString>
#include <QMessageBox>
#include <QPainter>

#include <stdexcept>

PolarGraphWindow::PolarGraphWindow(QWidget *parent) : QMainWindow(parent)
{
    ui.setupUi(this);

    functions.append(new ArchSpiralFunc());
    functions.append(new ButterflyFunc());
    functions.append(new RoseCurveFunc());
    functions.append(new HeadFunc());

    connect(ui.exitAction, &QAction::triggered, this, &PolarGraphWindow::close);
    connect(ui.dataPanelAction, &QAction::triggered, this, &PolarGraphWindow::onOpenDataPanelAction);
    connect(ui.aboutAction, &QAction::triggered, this, &PolarGraphWindow::onAboutAction);

    connect(&dataPanel,&DataPanelDialog::onSettingsChanged,this,&PolarGraphWindow::changePlotSettings);

    currentFunction = functions[0];
    fromRad = 0;
    toRad = 3.14*2;
    resolution = 500;
    QString message = QString("%1 plotted from %2 rad to %3 rad")
            .arg(QString::fromStdString(currentFunction->getName()), QString::number(fromRad,'f',2), QString::number(toRad,'f',2));
    statusBar()->showMessage(message);

    plotter.setResolution(resolution);
    plotter.setPlotLimits(fromRad,toRad);
    plot = QPixmap(ui.centralwidget->width(),ui.centralwidget->height());
    labelPixmap = QPixmap(ui.centralwidget->width(),ui.centralwidget->height());
    ui.plotLabel->setPixmap(labelPixmap);
}

void PolarGraphWindow::onOpenDataPanelAction()
{
    dataPanel.setFunctions(functions);
    dataPanel.setPlotLimits(fromRad,toRad);
    dataPanel.setResolution(resolution);
    dataPanel.show();
}

void PolarGraphWindow::onAboutAction()
{
    QMessageBox::information(
        this,
        tr("Polar plotter"),
        tr("This app was created by ArtNlk") );
}

void PolarGraphWindow::changePlotSettings(int functionListIndex, double _fromRad, double _toRad, int _resolution)
{
    if (functionListIndex >= functions.size() || functionListIndex < 0)
    {
        throw std::out_of_range("PolarGraphWindow::changePlotSettings function index out of range!");
    }

    currentFunction = functions[functionListIndex];
    fromRad = _fromRad;
    toRad = _toRad;
    resolution = _resolution;
    plotter.setPlotLimits(fromRad,toRad);
    plotter.setResolution(_resolution);
    QString message = QString("%1 plotted from %2 rad to %3 rad")
            .arg(QString::fromStdString(currentFunction->getName()), QString::number(fromRad,'f',2), QString::number(toRad,'f',2));
    statusBar()->showMessage(message);
    plotter.plot(&plot,currentFunction);
    qDebug() << message;
}

void PolarGraphWindow::paintEvent(QPaintEvent *pEvent)
{
    QPainter painter(&labelPixmap);
    painter.drawPixmap(0,0,plot);
    ui.plotLabel->setPixmap(labelPixmap);
}

void PolarGraphWindow::resizeEvent(QResizeEvent *event)
{
    double plotSize = std::min(ui.centralwidget->width(),ui.centralwidget->height());
    plot = QPixmap(plotSize,plotSize);
    labelPixmap = QPixmap(plotSize,plotSize);
    plotter.plot(&plot,currentFunction);
    ui.plotLabel->resize(plotSize,plotSize);
}
