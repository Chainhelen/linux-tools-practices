#include "RedMoving.h"

RedMoving::RedMoving()
{
    p = QPoint(0, 0);
}

QRectF RedMoving::boundingRect() const 
{
    return QRectF(-RECT_SIZE, -RECT_SIZE, 2 * RECT_SIZE,  2 * RECT_SIZE);
}

void RedMoving::paint(QPainter *painter,const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->save();
    painter->setPen(Qt::red);

    painter->setBrush(QBrush(Qt::red));
    QPointF itemp = mapFromScene(p);
    painter->drawEllipse(itemp.x(), itemp.y(), RECT_SIZE, RECT_SIZE);
    painter->restore();

    setPos(p.x(), p.y());
    update();
}

void RedMoving::advance(int step)
{
    if(!step)
        return ;
    p.setX(p.x() + 1);
    if(p.x() > TILE_SIZE)
    {
        p.setX(-TILE_SIZE);
    }
}
