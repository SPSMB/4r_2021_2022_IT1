#include "letadlo.h"
#include <QPainter>

Letadlo::Letadlo()
{
    obrysLetadla.append(QPoint(0,0));
    obrysLetadla.append(QPoint(200,70));
    obrysLetadla.append(QPoint(200,300));
}

QRectF Letadlo::boundingRect() const
{
    /*
    QRectF o = QRectF(0,0,200,100);
    return o;
    */
    return QRectF(0,0,200,100);
}

void Letadlo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(QBrush(QColor(255,125,0,255)));
    painter->drawPolygon(obrysLetadla);

    //painter->drawRect(10,10,100,50);
}

int Letadlo::height()
{
    return boundingRect().height();
}

QPainterPath Letadlo::shape() const
{
    QPainterPath kolizniObrys;
    kolizniObrys.addPolygon(obrysLetadla);
    return kolizniObrys;
}
