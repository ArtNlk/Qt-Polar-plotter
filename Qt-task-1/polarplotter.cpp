#include "polarplotter.h"

#include <QPainter>
#include <QColor>
#include <QRectF>

#include <cmath>
#include <stdexcept>
#include <vector>

PolarPlotter::PolarPlotter()
{

}

void PolarPlotter::plot(QPixmap *plot, PolarFunction* plottedFunc)
{
    std::vector<QPointF> results(resolution);

    double plotRange = plotToRad-plotFromRad;
    QPointF maxDistPoint = QPoint(0,0);

    for(int i = 0; i < resolution; i++)
    {
        double theta = plotFromRad + i*plotRange/resolution;
        double r = plottedFunc->eval(theta);
        results[i] = QPointF(r,theta);
        QPointF cartesianPoint = polarToCartesianTransform(results[i]);
        if(abs(cartesianPoint.x()) > abs(maxDistPoint.x())) {maxDistPoint.setX(abs(cartesianPoint.x()));}
        if(abs(cartesianPoint.y()) > abs(maxDistPoint.y())) {maxDistPoint.setY(abs(cartesianPoint.y()));}
    }

    maxDistPoint.setX(abs(maxDistPoint.x()) * 1.05);//Padding
    maxDistPoint.setY(abs(maxDistPoint.y()) * 1.05);


    QPointF prevPoint = polarToPixmapTransform(results[0],plot,maxDistPoint);
    QPainter painter(plot);
    painter.fillRect(0,0,plot->width(),plot->height(),QColor::fromRgb(255,255,255));
    //painter.drawLine(0,plot->size().height()/2,plot->size().width(),plot->size().height()/2);
    //painter.drawLine(plot->size().width()/2,0,plot->size().width()/2,plot->size().height());
    drawAxis(painter,plot,maxDistPoint);

    for(int i = 1; i < resolution; i++)
    {
        QPointF newPoint = polarToPixmapTransform(results[i],plot,maxDistPoint);
        painter.drawLine(prevPoint,newPoint);
        prevPoint = newPoint;
    }
}

void PolarPlotter::setPlotLimits(double _plotFromRad, double _plotToRad)
{
    if(_plotFromRad > _plotToRad)
    {
        throw std::invalid_argument("PolarPlotter::setPlotLimits plotFrom bigger than plotTo");
    }

    plotFromRad = _plotFromRad;
    plotToRad = _plotToRad;
}

void PolarPlotter::setResolution(unsigned int _resolution)
{
    if(resolution == 0)
    {
        throw std::invalid_argument("PolarPlotter::setResolution zero resolution is not allowed");
    }
    resolution = _resolution;
}

QPointF PolarPlotter::polarToCartesianTransform(const QPointF point)
{
    QPointF output;
    output.setX(point.x()*cos(point.y()));
    output.setY(point.x()*sin(point.y()));

    return output;
}

QPointF PolarPlotter::plotToPixmapTranform(const QPointF point, const QPixmap *map, const QPointF maxPoint)
{
    QPointF output;
    double xRatio = (point.x()/maxPoint.x());
    double yRatio = (point.y()*-1/maxPoint.y());

    double plotspaceX = xRatio*map->size().width()/2;
    double plotspaceY = yRatio*map->size().height()/2;

    double correctX = plotspaceX + map->size().width()/2;
    double correctY = plotspaceY + map->size().height()/2;
    assert(correctX > 0);
    assert(correctY > 0);
    assert(correctX < map->size().width());
    assert(correctY < map->size().height());
    output.setX(correctX);
    output.setY(correctY);

    return output;
}

QPointF PolarPlotter::polarToPixmapTransform(const QPointF point, const QPixmap *map, const QPointF maxPoint)
{
    QPointF output = polarToCartesianTransform(point);
    return plotToPixmapTranform(output,map,maxPoint);
}

void PolarPlotter::drawAxis(QPainter& painter, QPixmap *map, QPointF maxDistPoint)
{
    painter.drawLine(0,map->size().height()/2,map->size().width(),map->size().height()/2);
    painter.drawLine(map->size().width()/2,0,map->size().width()/2,map->size().height());
}

double PolarPlotter::distFromOrigin(QPointF point)
{
    return sqrt(point.x()*point.x() + point.y()*point.y());
}
