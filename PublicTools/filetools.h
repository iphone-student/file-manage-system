#ifndef FILETOOLS_H
#define FILETOOLS_H

#include <QDir>
#include <QMap>
#include <QDebug>
#include <QString>
#include <QFileInfo>
#include <QDateTime>
#include <QtMath>

#include "publictools.h"

class FileTools
{
public:
    FileTools();

    bool    AddressIsDir(QString filePath);                         // 判断文件路径是否为文件夹
    void    getAllFilePath(QString Dir, QStringList &filesPath);    // 获取路径下所有文件名
    void    FileInfoAnalysis(const QStringList &filesPath);         // 文件信息分析
    double  CalculateStringSimilarity(QString Str1, QString Str2);  // 计算两个词的相似度
};

#endif // FILETOOLS_H
