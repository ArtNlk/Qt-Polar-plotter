#ifndef POLARGRAPHWINDOW_H
#define POLARGRAPHWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QAction>

#include "polarfunc.h"
#include "datapaneldialog.h"
#include "polarplotter.h"

#include "ui_PolarGraphWindow.h"
class PolarGraphWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit PolarGraphWindow(QWidget *parent = nullptr);


signals:

public slots:
    void onOpenDataPanelAction();
    void onAboutAction();
    void changePlotSettings(int functionListIndex, double fromRad, double toRad, int resolution);

protected:
    Ui::PolarGraphWindow ui;
    DataPanelDialog dataPanel;
    QVector<PolarFunction*> functions;
    PolarFunction* currentFunction;
    double fromRad;
    double toRad;
    int resolution;

    PolarPlotter plotter;
    QPixmap plot;
    QPixmap labelPixmap;

    void paintEvent(QPaintEvent* pEvent);
    void resizeEvent(QResizeEvent* event);
    void plotFunction();

};

#endif // POLARGRAPHWINDOW_H
