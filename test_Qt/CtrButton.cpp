#include "CtrButton.h"

CtrButton::CtrButton(QWidget *parent):
    QWidget(parent)
{
}
CtrButton::~CtrButton()
{
}

void CtrButton::initPushButton()
{
    boxLayout   = new QHBoxLayout();

    startButton = new QPushButton(this);
    pauseButton = new QPushButton(this);

    startButton->setText(TXT_START);
    pauseButton->setText(TXT_PAUSE);

    startButton->setFixedWidth(BUTTON_WIDTH);
    pauseButton->setFixedWidth(BUTTON_WIDTH);

    boxLayout->addWidget(startButton);
    boxLayout->addWidget(pauseButton);
    
    this->setLayout(boxLayout);

    connect(startButton, SIGNAL(clicked()), this, SIGNAL(sendStartSignal()));
    connect(pauseButton, SIGNAL(clicked()), this, SIGNAL(sendPauseSignal()));
}

