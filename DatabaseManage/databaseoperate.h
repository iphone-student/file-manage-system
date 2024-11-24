#ifndef DATABASEOPERATE_H
#define DATABASEOPERATE_H

#include <QDebug>
#include <QObject>
#include <QThread>
#include <QSqlError>
#include <QSqlDatabase>

#include "publictools.h"
#include "DatabaseManage_global.h"

class DATABASEMANAGE_EXPORT DatabaseOperate : public QThread
{
    Q_OBJECT

public:
    DatabaseOperate(QObject* parent = nullptr);
    ~DatabaseOperate();

protected:
    void run() override;

private:
    bool ThreadControl = true;
    bool ConnectDatabase();
    QSqlDatabase database;
    int DatabaseConnectNumber = 0; // 数据库连接次数
    const int DatabaseConnectMaxNumber = 5; // 数据库重连次数
};

#endif // DATABASEOPERATE_H
