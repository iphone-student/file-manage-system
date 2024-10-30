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
}

void MainWindow::initLayout()
{
    // 创建一个 QWidget 作为中心控件
    QWidget *centralWidget = new QWidget(this);

    // 创建一个水平布局
    QGridLayout *mainLayout = new QGridLayout(centralWidget);

    // 添加按钮到布局
    mainLayout->addWidget(ui->FileAddressLabel,             0, 0, 1, 1);
    mainLayout->addWidget(ui->FileAddressLineEdit,          0, 1, 1, 4);
    mainLayout->addWidget(ui->FileAddressButton,            0, 5, 1, 1);
    mainLayout->addWidget(ui->FileAddressAnalysisButton,    1, 0, 1, 6);
    mainLayout->addWidget(ui->TXTAnalysisButton,            2, 0, 1, 6);
    mainLayout->addWidget(ui->TestButton,                   3, 0, 1, 6);

    // 设置中心控件
    this->setCentralWidget(centralWidget);
}

void MainWindow::initWidget()
{
    QString currentPath = QDir::currentPath();
    ui->FileAddressLineEdit->clear();
}

void MainWindow::on_FileAddressButton_clicked()
{
    // 若当前路径不存在，则直接结束本函数
    QString filePath = ui->FileAddressLineEdit->text();
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

void MainWindow::on_TXTAnalysisButton_clicked()
{
    QString TxtPath = "C:\\Users\\姜丹阳\\Desktop\\文件后缀.txt";
    QTextCodec* codec = QTextCodec::codecForName("UTF-8");
    QFile file(TxtPath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "无法打开文件";
        return;
    }

    QTextStream in(&file);
    in.setCodec(codec);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QString fileSuffix = "";
        QString fileInfo = "";
        for(int i = 0; i < line.size(); i++){
            if(line[i] == " "){
                fileInfo = line.mid(i + 1, line.size());
                break;
            }
            else fileSuffix += line[i];
        }
        qDebug() << "文件后缀：" << fileSuffix << "文件说明：" << fileInfo;
    }

    file.close();
}

void MainWindow::on_TestButton_clicked()
{
    qDebug() << FileTool->CalculateStringSimilarity("REBD-123.mp4", "1");
    qDebug() << PublicTools::getInstance()->randomString(10, 12);
}
