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
    ui->mainTabWidget->setTabText(3, "OpenCV");

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

    QGridLayout *OpenCVLayout = new QGridLayout(ui->OpenCVTab);
    OpenCVLayout->addWidget(ui->ImageAddressLabel,      0, 0, 1, 1);
    OpenCVLayout->addWidget(ui->ImageAddressLineEdit,   0, 1, 1, 4);
    OpenCVLayout->addWidget(ui->OpenImageButton,        0, 5, 1, 1);
    OpenCVLayout->addWidget(ui->ImageBox,               1, 0, 5, 6);

    QGridLayout *imageLayout = new QGridLayout(ui->ImageBox);
    imageLayout->addWidget(ui->ImageLabel, 0, 0, 1, 1);

}

void MainWindow::initWidget()
{
    ui->FileAddressLineEdit->clear();
}

QPixmap MainWindow::cvMatToQPixmap(const Mat &inMat)
{
    return QPixmap::fromImage(cvMatToQImage(inMat));
}

QImage MainWindow::cvMatToQImage(const Mat &mat)
{
    if (mat.type() == CV_8UC1)
    {
        QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);
        // Set the color table (used to translate colour indexes to qRgb values)
        image.setColorCount(256);
        for (int i = 0; i < 256; i++)
        {
            image.setColor(i, qRgb(i, i, i));
        }
        // Copy input Mat
        uchar* pSrc = mat.data;
        for (int row = 0; row < mat.rows; row++)
        {
            uchar* pDest = image.scanLine(row);
            memcpy(pDest, pSrc, mat.cols);
            pSrc += mat.step;
        }
        return image;
    }
    // 8-bits unsigned, NO. OF CHANNELS = 3
    else if (mat.type() == CV_8UC3)
    {
        // Copy input Mat
        const uchar* pSrc = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
        return image.rgbSwapped();
    }
    else if (mat.type() == CV_8UC4)
    {
        // Copy input Mat
        const uchar* pSrc = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
        return image.copy();
    }
    else
    {
        //MessageInfo("ERROR: Mat could not be converted to QImage.", 1);
        //emit sig_RunInfo("ERROR: Mat could not be converted to QImage.", 1);
        //if (!globalPara.IsInlineRun) Runstateinfo("ERROR: Mat could not be converted to QImage.", 1);
        return QImage();
    }
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
    try{
        cv::Mat image = cv::imread("D:\\Qt\\QtCode\\FileManageSystemGit\\build\\debug\\data\\20240404.jpg");
        cv::imshow("Output", image);
    }
    catch(std::exception){
        qDebug() << "OpenCV打开图片错误";
    }
}

void MainWindow::on_LinkCameraButton_clicked()
{
    if(ui->VideoWidget->layout() != nullptr){
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

void MainWindow::on_OpenImageButton_clicked()
{
    // 若当前路径不存在，则直接结束本函数
    QString filePath = QFileDialog::getOpenFileName(this, QObject::tr("选择图片"), QDir::homePath(), "*.jpg;*.png;*.bmp;");
    ui->ImageAddressLineEdit->clear();
    ui->ImageAddressLineEdit->setText(filePath);

    ui->ImageAddressLineEdit->setText(filePath);
    cv::Mat Image1 = cv::imread(filePath.toStdString()); // 原始图片
    cv::Mat Image2; // 尺寸变换
    cv::Mat Image3; // 滤波图片
    cv::Size ImageSize(512, 512);
    cv::resize(Image1, Image2, ImageSize);

//    cv::medianBlur(Image2, Image3, 7); // 中值滤波
    cv::GaussianBlur(Image2, Image3, cv::Size(5, 5), 2); // 高斯滤波
    imagePixmap = cvMatToQPixmap(Image3);
    imagePixmap = imagePixmap.scaled(ui->ImageLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->ImageLabel->setPixmap(imagePixmap);
    ui->ImageLabel->show();

//    QString info;
//    info += "通道数:" + QString::number(newImage.channels()) + "\n";
//    info += "类型:" + QString::number(newImage.type()) + "\n";
//    ui->ImageLabel->setText(info);
}
