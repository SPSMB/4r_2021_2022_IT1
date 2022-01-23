#ifndef LETADLO_H
#define LETADLO_H

#include <QGraphicsItem>

class Letadlo : public QGraphicsItem
{
private:
    QPolygon obrysLetadla;
public:
    Letadlo();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int height();
    QPainterPath shape() const;

};

#endif // LETADLO_H
