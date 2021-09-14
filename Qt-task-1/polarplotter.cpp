#include "polarplotter.h"

#include <QPainter>
#include <QRectF>

#include <cmath>
#include <stdexcept>
#include <vector>

PolarPlotter::PolarPlotter()
{
    backgroundColor = QColor::fromRgb(255,255,255);

    axisPen.setColor(QColor::fromRgb(0,0,0));
    axisPen.setWidth(3);

    plotPen.setColor(QColor::fromRgb(0,0,0));
    plotPen.setWidth(1);

    minBoundaryPen.setColor(QColor::fromRgb(64,64,64));
    minBoundaryPen.setWidth(2);

    maxBoundaryPen.setColor(QColor::fromRgb(128,128,128));
    maxBoundaryPen.setWidth(2);
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
    painter.fillRect(0,0,plot->width(),plot->height(),backgroundColor);
    //painter.drawLine(0,plot->size().height()/2,plot->size().width(),plot->size().height()/2);
    //painter.drawLine(plot->size().width()/2,0,plot->size().width()/2,plot->size().height());
    drawAxis(painter,plot,maxDistPoint);

    painter.setPen(plotPen);
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

void PolarPlotter::setBackgroundColor(QColor color)
{
    backgroundColor = color;
}

void PolarPlotter::setAxisPen(QPen pen)
{
    axisPen = pen;
}

void PolarPlotter::setAxisColor(QColor color)
{
    axisPen.setColor(color);
}

void PolarPlotter::setPlotPen(QPen pen)
{
    plotPen = pen;
}

void PolarPlotter::setPlotColor(QColor color)
{
    plotPen.setColor(color);
}

void PolarPlotter::setMinBoundaryPen(QPen pen)
{
    minBoundaryPen = pen;
}

void PolarPlotter::setMinBoundaryColor(QColor color)
{
    minBoundaryPen.setColor(color);
}

void PolarPlotter::setMaxBoundaryPen(QPen pen)
{
    maxBoundaryPen = pen;

}

void PolarPlotter::setMaxBoundaryColor(QColor color)
{
    maxBoundaryPen.setColor(color);
}

QPointF PolarPlotter::polarToCartesianTransform(const QPointF point)
{
    QPointF output;
    output.setX(point.x()*cos(point.y()));
    output.setY(point.x()*sin(point.y()));

    return output;
}

QPointF PolarPlotter::cartesianToPolarTransform(const QPointF point)
{
    QPointF output;
    output.setX(sqrt(point.x()*point.x() + point.y()*point.y()));
    output.setY(atan2(point.y(),point.x()));
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
    QPen prevPen = painter.pen();
    painter.setPen(axisPen);
    painter.drawLine(0,map->size().height()/2,map->size().width(),map->size().height()/2);
    painter.drawLine(map->size().width()/2,0,map->size().width()/2,map->size().height());


    QPointF minBoundaryEnd = cartesianToPolarTransform(maxDistPoint);
    minBoundaryEnd.ry() = plotFromRad;

    QPointF maxBoundaryEnd = minBoundaryEnd;
    maxBoundaryEnd.ry() = plotToRad;
    minBoundaryEnd = polarToPixmapTransform(minBoundaryEnd,map,maxDistPoint);
    maxBoundaryEnd = polarToPixmapTransform(maxBoundaryEnd,map,maxDistPoint);

    QPointF origin = QPointF(map->height()/2,map->width()/2);

    painter.setPen(minBoundaryPen);
    painter.drawLine(origin,minBoundaryEnd);
    painter.setPen(maxBoundaryPen);
    painter.drawLine(origin,maxBoundaryEnd);

    painter.setPen(prevPen);
}

double PolarPlotter::distFromOrigin(QPointF point)
{
    return sqrt(point.x()*point.x() + point.y()*point.y());
}
