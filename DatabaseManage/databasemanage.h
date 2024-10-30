#ifndef DATABASEMANAGE_H
#define DATABASEMANAGE_H

#include "publictools.h"
#include "databaseoperate.h"

class DatabaseManage
{
public:
    DatabaseManage();

private:
    void initData();
    DatabaseOperate *dataOperate;
};

#endif // DATABASEMANAGE_H
