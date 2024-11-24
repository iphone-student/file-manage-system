#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDir>
#include <Windows.h>
#include <QFileDialog>
#include <QMessageBox>
#include <QGridLayout>
#include <QMainWindow>
#include <QResizeEvent>

#include "filetools.h"
#include "videohandle.h"
#include "videohandlethread.h"
#include "cameramanage.h"
#include "MainWindow_global.h"


namespace Ui {
class MainWindow;
}

class MAINWINDOW_EXPORT MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_FileAddressButton_clicked();
    void on_FileAddressAnalysisButton_clicked();
    void on_TestButton_clicked();
    void on_LinkCameraButton_clicked();
    void on_CheckCamera_clicked();
    void on_OpenImageButton_clicked();

    void showVideoFPS(QPixmap imageFPS);
private:
    Ui::MainWindow *ui;
    FileTools *FileTool; // 文件操作工具
    QPixmap imagePixmap;

private:
    void initData();    // 初始化数据
    void initLayout();  // 初始化窗口布局
    void initWidget();  // 初始化控件
};

#endif // MAINWINDOW_H
