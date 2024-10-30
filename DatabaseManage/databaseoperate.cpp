#include "databaseoperate.h"

DatabaseOperate::DatabaseOperate(QObject *parent) :
    QThread(parent)
{

}

DatabaseOperate::~DatabaseOperate()
{
    if(database.isOpen()){
        database.close();
    }
    QSqlDatabase::removeDatabase(QSqlDatabase::database().connectionName());

    delete this;
}

void DatabaseOperate::run()
{
    while(ThreadControl){
        if(database.isOpen()){

        }
        else if(DatabaseConnectNumber < DatabaseConnectMaxNumber){
            if(true == ConnectDatabase()){

            }
            else{
                sleep(5); // 如果连接失败，则暂停x秒后重连
            }
        }
        else{
            ThreadControl = false;
            this->exit();
        }
    }
}

bool DatabaseOperate::ConnectDatabase()
{
    qDebug() << "开始第" << ++DatabaseConnectNumber << "次连接数据库...";

    database = QSqlDatabase::addDatabase(PublicTools::getInstance()->DatabaseDrive);
    database.setPort(PublicTools::getInstance()->DatabasePort);
    database.setHostName(PublicTools::getInstance()->DatabaseHostName);
    database.setUserName(PublicTools::getInstance()->DatabaseUserName);
    database.setPassword(PublicTools::getInstance()->DatabasePassword);
    database.setDatabaseName(PublicTools::getInstance()->DatabaseName);
    database.setConnectOptions("MYSQL_OPT_RECONNECT=1"); // 断网重联

    if(database.open()){
        qDebug()<<"数据库连接成功！";
        return true;
    }
    else qDebug()<<"数据库连接失败！，失败说明：" << database.lastError().text();

    return false;
}
