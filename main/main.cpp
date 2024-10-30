#include <QApplication>

#include "mainwindow.h"
#include "databasemanage.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    new MainWindow();
    new DatabaseManage();

    return a.exec();
}
