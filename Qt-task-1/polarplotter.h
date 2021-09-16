#ifndef POLARPLOTTER_H
#define POLARPLOTTER_H

#include <QPixmap>
#include <QPoint>
#include <QColor>
#include <QPen>

#include "polarfunc.h"

class PolarPlotter
{
public:
    PolarPlotter();

    void plot(QPixmap* plot, PolarFunction* plottedFunc);
    void setPlotLimits(double _plotFromRad,double _plotToRad);
    void setResolution( int _resolution);

    void setBackgroundColor(QColor color);
    void setAxisPen(QPen pen);
    void setAxisColor(QColor color);
    void setPlotPen(QPen pen);
    void setPlotColor(QColor color);
    void setMinBoundaryPen(QPen pen);
    void setMinBoundaryColor(QColor color);
    void setMaxBoundaryPen(QPen pen);
    void setMaxBoundaryColor(QColor color);
private:
    double plotFromRad;
    double plotToRad;
     int resolution;

    QPointF polarToCartesianTransform(const QPointF point);
    QPointF cartesianToPolarTransform(const QPointF point);
    QPointF plotToPixmapTranform(const QPointF point,const QPixmap* map,const QPointF maxPoint);
    QPointF polarToPixmapTransform(const QPointF point,const QPixmap* map,const QPointF maxPoint);
    void drawAxis(QPainter& painter,QPixmap* map, QPointF maxDistPoint);
    double distFromOrigin(QPointF point);

    QColor backgroundColor;
    QPen axisPen;
    QPen plotPen;
    QPen minBoundaryPen;
    QPen maxBoundaryPen;
    QPen redPen;
};

#endif // POLARPLOTTER_H
