#ifndef REDMOVING_H
#define REDMOVING_H
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <iostream>
#include <QWidget>
#include <QPainter>
#include <stdio.h>
#include "common.h"

using namespace std;

class RedMoving : public QGraphicsItem{
    public:
        RedMoving();
        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
        void advance(int step);

    public:
        QPointF p;
};
#endif
