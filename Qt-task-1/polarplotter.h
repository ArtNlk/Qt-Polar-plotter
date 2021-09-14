#ifndef POLARPLOTTER_H
#define POLARPLOTTER_H

#include <QPixmap>
#include <QPoint>

#include "polarfunc.h"

class PolarPlotter
{
public:
    PolarPlotter();

    void plot(QPixmap* plot, PolarFunction* plottedFunc);
    void setPlotLimits(double _plotFromRad,double _plotToRad);
    void setResolution(unsigned int _resolution);
private:
    double plotFromRad;
    double plotToRad;
    unsigned int resolution;

    QPointF polarToCartesianTransform(const QPointF point);
    QPointF plotToPixmapTranform(const QPointF point,const QPixmap* map,const QPointF maxPoint);
    QPointF polarToPixmapTransform(const QPointF point,const QPixmap* map,const QPointF maxPoint);
    void drawAxis(QPainter& painter,QPixmap* map, QPointF maxDistPoint);
    double distFromOrigin(QPointF point);
};

#endif // POLARPLOTTER_H
