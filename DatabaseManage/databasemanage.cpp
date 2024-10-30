#include "databasemanage.h"

DatabaseManage::DatabaseManage()
{
    initData();
}

void DatabaseManage::initData()
{
    dataOperate = new DatabaseOperate();
    dataOperate->start();
}
