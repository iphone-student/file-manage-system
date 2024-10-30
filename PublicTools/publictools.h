#ifndef PUBLICTOOLS_H
#define PUBLICTOOLS_H

#include <QTime>
#include <QDebug>
#include <QObject>
#include <QString>
#include <qrandom.h>
#include <QRandomGenerator>

class PublicTools : public QObject
{
    Q_OBJECT

public:
    PublicTools(QObject* parent = nullptr);
    ~PublicTools();

    QString randomString(int minLength, int maxLength); // 生成长度[minLength, maxLength]的字符串
    static PublicTools* getInstance();

public:
    // **************数据库连接信息************** //
    int     DatabasePort;       // 数据库连接端口
    QString DatabaseDrive;      // 数据库驱动
    QString DatabaseHostName;   // 数据库主机地址
    QString DatabaseUserName;   // 数据库用户名
    QString DatabasePassword;   // 数据库用户密码
    QString DatabaseName;       // 数据库名称

private:
    void initData();    // 初始化所有公共数据
    void initDatabaseConnectInfo(); // 初始化数据库连接信息

private:
    static PublicTools* m_instance;
    const QString PossibleCharacters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
};
#endif // PUBLICTOOLS_H
