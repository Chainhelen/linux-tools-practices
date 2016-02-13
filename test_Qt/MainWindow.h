#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include "CtrButton.h"
#include "common.h"
#include "RedMoving.h"

class MainWindow : public QMainWindow{
    Q_OBJECT
    public:
        MainWindow(QWidget *parent = 0);
        ~MainWindow();
        void initMainWindow();
        void initMovingRed();
    public slots:
        void receviceStartSignal();
        void recevicePauseSignal();

    private:
        QGraphicsScene  *scene;
        QGraphicsView   *view;
        QVBoxLayout     *boxLayout;
        QWidget         *mainWidget;
        CtrButton       *ctrButton;
        RedMoving       *redMoving;
        QTimer          *qTimer;
};

#endif
