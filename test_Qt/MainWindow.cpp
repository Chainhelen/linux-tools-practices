#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
}

MainWindow::~MainWindow()
{
}

void MainWindow::initMainWindow()
{
    mainWidget= new QWidget(this);
    boxLayout = new QVBoxLayout(mainWidget);
    scene     = new QGraphicsScene();
    view      = new QGraphicsView(scene);
    ctrButton = new CtrButton(mainWidget);
    redMoving = new RedMoving();

    scene->setSceneRect(-TILE_SIZE, -TILE_SIZE, 2 * TILE_SIZE, 2 * TILE_SIZE);
    scene->addItem(redMoving);

    QPixmap bg(RECT_SIZE, RECT_SIZE);
    QPainter p(&bg);
    p.setBrush(QBrush(Qt::yellow));
    p.drawRect(0, 0, RECT_SIZE, RECT_SIZE);
    view->setBackgroundBrush(QBrush(bg));
    view->show();

    ctrButton->initPushButton();
    boxLayout->addWidget(view);
    boxLayout->addWidget(ctrButton);
    mainWidget->setLayout(boxLayout);

    this->setCentralWidget(mainWidget);
    this->initMovingRed();
}

void MainWindow::initMovingRed()
{
    qTimer   =  new QTimer(this);
    qTimer->start(3);

    connect(qTimer, SIGNAL(timeout()),
            scene,  SLOT(advance()));
    connect(ctrButton, SIGNAL(sendStartSignal()), this, SLOT(receviceStartSignal()));
    connect(ctrButton, SIGNAL(sendPauseSignal()), this, SLOT(recevicePauseSignal()));
}

void MainWindow::receviceStartSignal()
{
    disconnect(qTimer, SIGNAL(timeout()),scene,  SLOT(advance()));
    connect(qTimer, SIGNAL(timeout()),scene,  SLOT(advance()));
}

void MainWindow::recevicePauseSignal()
{
   disconnect(qTimer, SIGNAL(timeout()),scene,  SLOT(advance()));
}
