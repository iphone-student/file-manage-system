#include "publictools.h"
PublicTools* PublicTools::m_instance = nullptr;

PublicTools::PublicTools(QObject* parent): QObject(parent)
{
    initData();
}

PublicTools::~PublicTools()
{

}

QString PublicTools::randomString(int minLength, int maxLength)
{
    int randomNumber;

    if(minLength > maxLength)return "";
    else if(minLength == maxLength)randomNumber = minLength;
    else randomNumber = (qrand() % (maxLength - minLength + 1)) + minLength;

    QString randomString;
    int CharaLength = PossibleCharacters.size();
    for(int i = 0; i < randomNumber; ++i)
    {
        int index = qrand() % CharaLength;
        QChar nextChar = PossibleCharacters[index];
        randomString.append(nextChar);
    }
    return randomString;
}

PublicTools *PublicTools::getInstance()
{
    if (!m_instance) {
        m_instance = new PublicTools;
    }

    return m_instance;
}

void PublicTools::initData()
{
    initDatabaseConnectInfo(); // 初始化数据库连接信息
}

void PublicTools::initDatabaseConnectInfo()
{
    DatabasePort        =   3306;                   // 数据库连接端口
    DatabaseDrive       =   "QMYSQL";               // 数据库驱动
    DatabaseHostName    =   "localhost";            // 数据库主机地址
    DatabaseUserName    =   "FileManage";           // 数据库用户名
    DatabasePassword    =   "123456789";            // 数据库用户密码
    DatabaseName        =   "file_manage_database"; // 数据库名称
}
