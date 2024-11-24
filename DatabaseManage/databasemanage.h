#ifndef DATABASEMANAGE_H
#define DATABASEMANAGE_H

#include "publictools.h"
#include "databaseoperate.h"
#include "DatabaseManage_global.h"

class DATABASEMANAGE_EXPORT DatabaseManage
{
public:
    DatabaseManage();

private:
    void initData();
    DatabaseOperate *dataOperate;
};

#endif // DATABASEMANAGE_H
