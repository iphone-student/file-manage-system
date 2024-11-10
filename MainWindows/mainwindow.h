#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDir>
#include <QFileDialog>
#include <QMessageBox>
#include <QGridLayout>
#include <QMainWindow>
#include <QResizeEvent>

#include "filetools.h"
#include "cameramanage.h"

#include <Windows.h>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/opencv.hpp>

namespace Ui {
class MainWindow;
}

using namespace cv;

class MainWindow : public QMainWindow
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

private:
    Ui::MainWindow *ui;
    FileTools *FileTool; // 文件操作工具
    QPixmap imagePixmap;

private:
    void initData();    // 初始化数据
    void initLayout();  // 初始化窗口布局
    void initWidget();  // 初始化控件

    QPixmap cvMatToQPixmap(const cv::Mat &inMat);
    QImage cvMatToQImage(const cv::Mat &inMat);
};

#endif // MAINWINDOW_H
