#ifndef CTRBUTTON_H
#define CTRBUTTON_H
#include <QPushButton>
#include <QWidget>
#include <QHBoxLayout>
#include <string>
#include "common.h"

using namespace std;

class CtrButton : public QWidget{
    Q_OBJECT
    public:
        CtrButton(QWidget *parent = 0);
        ~CtrButton();
        void initPushButton();
    private:
        QHBoxLayout *boxLayout;
        QPushButton *startButton;
        QPushButton *pauseButton;
    signals:
        void sendStartSignal();
        void sendPauseSignal();
};
#endif
