#include <QApplication>

#include "mainwindow.h"
#include "publictools.h"
#include "cameramanage.h"
#include "databasemanage.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    new PublicTools();      // 公共工具模块
    new CameraManage();     // 相机模块
//    new DatabaseManage();   // 数据库管理模块
    new MainWindow();       // 主界面模块

    return a.exec();
}
