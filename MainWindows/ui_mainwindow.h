/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *mainTabWidget;
    QWidget *FileManage;
    QPushButton *TestButton;
    QPushButton *FileAddressAnalysisButton;
    QLabel *FileAddressLabel;
    QPushButton *FileAddressButton;
    QLineEdit *FileAddressLineEdit;
    QWidget *CameraManage;
    QPushButton *LinkCameraButton;
    QWidget *VideoWidget;
    QPushButton *CheckCamera;
    QComboBox *CameraSelect;
    QWidget *DatabaseManage;
    QWidget *OpenCVTab;
    QLabel *ImageAddressLabel;
    QGroupBox *ImageBox;
    QLabel *ImageLabel;
    QLineEdit *ImageAddressLineEdit;
    QPushButton *OpenImageButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(692, 562);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        mainTabWidget = new QTabWidget(centralwidget);
        mainTabWidget->setObjectName(QString::fromUtf8("mainTabWidget"));
        mainTabWidget->setGeometry(QRect(10, 10, 671, 541));
        FileManage = new QWidget();
        FileManage->setObjectName(QString::fromUtf8("FileManage"));
        TestButton = new QPushButton(FileManage);
        TestButton->setObjectName(QString::fromUtf8("TestButton"));
        TestButton->setGeometry(QRect(20, 100, 621, 28));
        FileAddressAnalysisButton = new QPushButton(FileManage);
        FileAddressAnalysisButton->setObjectName(QString::fromUtf8("FileAddressAnalysisButton"));
        FileAddressAnalysisButton->setGeometry(QRect(20, 70, 621, 28));
        FileAddressLabel = new QLabel(FileManage);
        FileAddressLabel->setObjectName(QString::fromUtf8("FileAddressLabel"));
        FileAddressLabel->setGeometry(QRect(20, 30, 91, 31));
        FileAddressButton = new QPushButton(FileManage);
        FileAddressButton->setObjectName(QString::fromUtf8("FileAddressButton"));
        FileAddressButton->setGeometry(QRect(550, 30, 92, 31));
        FileAddressLineEdit = new QLineEdit(FileManage);
        FileAddressLineEdit->setObjectName(QString::fromUtf8("FileAddressLineEdit"));
        FileAddressLineEdit->setGeometry(QRect(120, 30, 421, 31));
        mainTabWidget->addTab(FileManage, QString());
        CameraManage = new QWidget();
        CameraManage->setObjectName(QString::fromUtf8("CameraManage"));
        LinkCameraButton = new QPushButton(CameraManage);
        LinkCameraButton->setObjectName(QString::fromUtf8("LinkCameraButton"));
        LinkCameraButton->setGeometry(QRect(160, 60, 301, 28));
        VideoWidget = new QWidget(CameraManage);
        VideoWidget->setObjectName(QString::fromUtf8("VideoWidget"));
        VideoWidget->setGeometry(QRect(10, 120, 641, 381));
        CheckCamera = new QPushButton(CameraManage);
        CheckCamera->setObjectName(QString::fromUtf8("CheckCamera"));
        CheckCamera->setGeometry(QRect(480, 60, 121, 31));
        CameraSelect = new QComboBox(CameraManage);
        CameraSelect->setObjectName(QString::fromUtf8("CameraSelect"));
        CameraSelect->setGeometry(QRect(30, 60, 121, 31));
        mainTabWidget->addTab(CameraManage, QString());
        DatabaseManage = new QWidget();
        DatabaseManage->setObjectName(QString::fromUtf8("DatabaseManage"));
        mainTabWidget->addTab(DatabaseManage, QString());
        OpenCVTab = new QWidget();
        OpenCVTab->setObjectName(QString::fromUtf8("OpenCVTab"));
        ImageAddressLabel = new QLabel(OpenCVTab);
        ImageAddressLabel->setObjectName(QString::fromUtf8("ImageAddressLabel"));
        ImageAddressLabel->setGeometry(QRect(20, 30, 91, 31));
        ImageBox = new QGroupBox(OpenCVTab);
        ImageBox->setObjectName(QString::fromUtf8("ImageBox"));
        ImageBox->setGeometry(QRect(20, 90, 621, 381));
        ImageLabel = new QLabel(ImageBox);
        ImageLabel->setObjectName(QString::fromUtf8("ImageLabel"));
        ImageLabel->setGeometry(QRect(80, 120, 72, 15));
        ImageAddressLineEdit = new QLineEdit(OpenCVTab);
        ImageAddressLineEdit->setObjectName(QString::fromUtf8("ImageAddressLineEdit"));
        ImageAddressLineEdit->setGeometry(QRect(120, 30, 421, 31));
        OpenImageButton = new QPushButton(OpenCVTab);
        OpenImageButton->setObjectName(QString::fromUtf8("OpenImageButton"));
        OpenImageButton->setGeometry(QRect(550, 30, 92, 31));
        mainTabWidget->addTab(OpenCVTab, QString());
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        mainTabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        TestButton->setText(QApplication::translate("MainWindow", "\346\265\213\350\257\225\345\212\237\350\203\275", nullptr));
        FileAddressAnalysisButton->setText(QApplication::translate("MainWindow", "\350\267\257\345\276\204\345\210\206\346\236\220", nullptr));
        FileAddressLabel->setText(QApplication::translate("MainWindow", "\346\226\207\344\273\266\345\244\271\345\234\260\345\235\200\357\274\232", nullptr));
        FileAddressButton->setText(QApplication::translate("MainWindow", "\345\257\274\345\205\245\345\234\260\345\235\200", nullptr));
        mainTabWidget->setTabText(mainTabWidget->indexOf(FileManage), QApplication::translate("MainWindow", "Tab 1", nullptr));
        LinkCameraButton->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245\346\221\204\345\203\217\345\244\264", nullptr));
        CheckCamera->setText(QApplication::translate("MainWindow", "\346\243\200\346\237\245\346\221\204\345\203\217\345\244\264", nullptr));
        mainTabWidget->setTabText(mainTabWidget->indexOf(CameraManage), QApplication::translate("MainWindow", "Tab 2", nullptr));
        mainTabWidget->setTabText(mainTabWidget->indexOf(DatabaseManage), QApplication::translate("MainWindow", "\351\241\265", nullptr));
        ImageAddressLabel->setText(QApplication::translate("MainWindow", "\345\233\276\347\211\207\357\274\232", nullptr));
        ImageBox->setTitle(QString());
        ImageLabel->setText(QString());
        OpenImageButton->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\345\233\276\347\211\207", nullptr));
        mainTabWidget->setTabText(mainTabWidget->indexOf(OpenCVTab), QApplication::translate("MainWindow", "\351\241\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
