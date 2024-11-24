#ifndef FILETOOLS_H
#define FILETOOLS_H

#include <QDir>
#include <QMap>
#include <QFile>
#include <QtMath>
#include <QDebug>
#include <QString>
#include <QFileInfo>
#include <QDateTime>
#include <QTextCodec>
#include <QTextStream>

#include "publictools.h"
#include "PublicTools_global.h"

class PUBLICTOOLS_EXPORT FileTools
{
public:
    FileTools();

    void    txtAnalysis(QString filePath);                          // txt文件简单读写分析
    bool    AddressIsDir(QString filePath);                         // 判断文件路径是否为文件夹
    void    getAllFilePath(QString Dir, QStringList &filesPath);    // 获取路径下所有文件名
    void    FileInfoAnalysis(const QStringList &filesPath);         // 文件信息分析
    double  CalculateStringSimilarity(QString Str1, QString Str2);  // 计算两个词的相似度 余弦
};

#endif // FILETOOLS_H
