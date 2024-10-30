#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDir>
#include <QFile>
#include <QTextCodec>
#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>
#include <QGridLayout>
#include <QMainWindow>

#include "filetools.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_FileAddressButton_clicked();
    void on_FileAddressAnalysisButton_clicked();
    void on_TXTAnalysisButton_clicked();
    void on_TestButton_clicked();

private:
    Ui::MainWindow *ui;
    FileTools *FileTool; // 文件操作工具

private:
    void initData();    // 初始化数据
    void initLayout();  // 初始化窗口布局
    void initWidget();  // 初始化控件
};

#endif // MAINWINDOW_H
