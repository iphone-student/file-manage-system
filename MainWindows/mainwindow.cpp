#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initLayout();
    initData();

    this->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initData()
{
    this->setWindowTitle("文件管理系统");
    ui->mainTabWidget->setTabText(0, "文件管理");
    ui->mainTabWidget->setTabText(1, "摄像头管理");
    ui->mainTabWidget->setTabText(2, "数据库管理");

    ui->CameraSelect->addItems(CameraManage::getInstance()->CameraNames);
    ui->VideoWidget->setStyleSheet("QWidget{background-color:black}");
}

void MainWindow::initLayout()
{
    // 创建一个 QWidget 作为中心控件
    QWidget *centralWidget = new QWidget(this);

    // 创建一个水平布局
    QGridLayout *mainLayout = new QGridLayout(centralWidget);
    mainLayout->addWidget(ui->mainTabWidget);

    // 设置中心控件
    this->setCentralWidget(centralWidget);


    QGridLayout *fileManageLayout = new QGridLayout(ui->FileManage);
    fileManageLayout->addWidget(ui->FileAddressLabel,           0, 0, 1, 1);
    fileManageLayout->addWidget(ui->FileAddressLineEdit,        0, 1, 1, 4);
    fileManageLayout->addWidget(ui->FileAddressButton,          0, 5, 1, 1);
    fileManageLayout->addWidget(ui->FileAddressAnalysisButton,  1, 0, 1, 6);
    fileManageLayout->addWidget(ui->TestButton,                 2, 0, 1, 6);


    // 添加按钮到布局
    QGridLayout *cameraManageLayout = new QGridLayout(ui->CameraManage);
    cameraManageLayout->addWidget(ui->CameraSelect,     0, 0, 1, 2);
    cameraManageLayout->addWidget(ui->LinkCameraButton, 0, 2, 1, 1);
    cameraManageLayout->addWidget(ui->CheckCamera,      0, 3, 1, 1);
    cameraManageLayout->addWidget(ui->VideoWidget,      1, 0, 1, 4);

}

void MainWindow::initWidget()
{
    ui->FileAddressLineEdit->clear();
}

void MainWindow::on_FileAddressButton_clicked()
{
    // 若当前路径不存在，则直接结束本函数
    QString filePath = ui->FileAddressLineEdit->text();
    // QString currentPath = QDir::currentPath();
    if(!FileTool->AddressIsDir(filePath)) filePath = QDir::homePath();

    filePath = QFileDialog::getExistingDirectory(nullptr, QObject::tr("选择文件路径"), filePath);
    if(!filePath.isEmpty()){
        ui->FileAddressLineEdit->clear();
        ui->FileAddressLineEdit->setText(filePath);
    }
}

void MainWindow::on_FileAddressAnalysisButton_clicked()
{
    QString filePath = ui->FileAddressLineEdit->text();

    // 若当前路径不存在，则直接结束本函数
    if(!FileTool->AddressIsDir(filePath)){
        QMessageBox::warning(this, "路径验证", "路径错误！");
        return;
    }

    // 获取路径下所有文件路径
    QStringList filesPath;
    FileTool->getAllFilePath(filePath, filesPath);

    // 文件信息分析
    FileTool->FileInfoAnalysis(filesPath);
}

void MainWindow::on_TestButton_clicked()
{

}

void MainWindow::on_LinkCameraButton_clicked()
{
    if(ui->VideoWidget->layout() != nullptr){
        int i = 0;
        while(ui->VideoWidget->layout()->count() > 0) {
            delete ui->VideoWidget->layout()->takeAt(0)->widget();
        }
        // 删除布局
        delete ui->VideoWidget->layout();
    }

    CameraManage::getInstance()->linkCamera(ui->CameraSelect->currentText(), ui->VideoWidget);

    QVBoxLayout *VideoLayout = new QVBoxLayout(ui->VideoWidget);
    VideoLayout->addWidget(CameraManage::getInstance()->Viewfinder);
    ui->VideoWidget->setLayout(VideoLayout);
}

void MainWindow::on_CheckCamera_clicked()
{
    CameraManage::getInstance()->initCameraInfo();
    ui->CameraSelect->clear();
    ui->CameraSelect->addItems(CameraManage::getInstance()->CameraNames);
}
