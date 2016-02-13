#include <QMainWindow>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include "MainWindow.h"

int main(int argc,char *argv[])
{
    QApplication a(argc, argv);

    MainWindow *mainWindow = new MainWindow(NULL);
    mainWindow->initMainWindow();
    mainWindow->show();

    return a.exec();
}
