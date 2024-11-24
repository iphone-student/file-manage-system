#include "filetools.h"

FileTools::FileTools()
{

}

void FileTools::txtAnalysis(QString filePath)
{
    // filePath = "C:\\Users\\姜丹阳\\Desktop\\文件后缀.txt"
    QTextCodec* codec = QTextCodec::codecForName("UTF-8");
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "无法打开文件";
        return;
    }

    QTextStream in(&file);
    in.setCodec(codec);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QString fileSuffix = "";
        QString fileInfo = "";
        for(int i = 0; i < line.size(); i++){
            if(line[i] == " "){
                fileInfo = line.mid(i + 1, line.size());
                break;
            }
            else fileSuffix += line[i];
        }
        qDebug() << fileSuffix << fileInfo;
    }

    file.close();
}

bool FileTools::AddressIsDir(QString filePath)
{
    // 检查路径是否存在
    if(filePath.isEmpty()) return false;// 路径为空

    QFileInfo fileInfo(filePath);
    if (fileInfo.exists()) {
        // 如果路径存在，检查它是文件还是目录
        if (fileInfo.isFile()) return false;// 是文件，路径不正确
        else if (fileInfo.isDir()) return true;// 是目录，路径正确
    }
    else return false;// 路径不正确
    return false;
}

void FileTools::getAllFilePath(QString Dir, QStringList &filesPath)
{
    // 获取路径下所有文件名称
    QDir directory(Dir);
    QStringList filesDirs = directory.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
    QStringList files = directory.entryList(QDir::Files | QDir::NoDotAndDotDot);
    foreach (QString file, files) {
        filesPath.push_back(directory.absoluteFilePath(file));
    }

    if(filesDirs.size() == 0){
        return;
    }
    else{
        foreach (QString file, filesDirs) {
            getAllFilePath(directory.absoluteFilePath(file), filesPath);
        }
    }
}

void FileTools::FileInfoAnalysis(const QStringList &filesPath)
{
    int filesNum = filesPath.size();
    QVector<QString>            FileID;         // 文件ID
    QMap<QString, QString>      FileIDtoName;   // 文件ID对应文件名
    QMap<QString, QString>      FileIDtoPath;   // 文件ID对应文件路径
    QMap<QString, QString>      FileIDtoSuffix; // 文件ID对应文件类型
    QMap<QString, long long>    FileIDtoSize;   // 文件ID对应文件大小
    QMap<QString, QDateTime>    FileIDtoTime;   // 文件ID对应文件生成时间

    QMap<QString, unsigned long long> FileSuffixNum;    // 文件类型数量统计
    QMap<QString, unsigned long long> FileSuffixSize;   // 文件类型大小统计

    unsigned long long  FileTotalSize = 0; // 文件总大小

    for(int i = 0; i < filesNum; i++){
        QFileInfo fileInfo(filesPath[i]);
        if(fileInfo.exists()){
            QString ID = PublicTools::getInstance()->randomString(18, 20);
            while(FileID.contains(ID)){
                ID = PublicTools::getInstance()->randomString(18, 20);
            }
            QString     FileName    = fileInfo.fileName();      // 文件名
            QString     FilePath    = fileInfo.absolutePath();  // 文件路径
            QString     FileSuffix  = fileInfo.suffix();        // 文件类型
            long long   FileSize    = fileInfo.size();          // 文件大小
            QDateTime   FileTime    = fileInfo.birthTime();     // 文件生成时间

            FileID.push_back(ID);
            FileIDtoName.insert(ID, FileName);      // 文件ID对应文件名
            FileIDtoPath.insert(ID, FilePath);      // 文件ID对应文件绝对路径
            FileIDtoSuffix.insert(ID, FileSuffix);  // 文件ID对应文件类型
            FileIDtoSize.insert(ID, FileSize);      // 文件ID对应文件大小
            FileIDtoTime.insert(ID, FileTime);      // 文件ID对应文件生成时间

            // 记录文件大小总和
            FileTotalSize += FileSize;

            // 基于文件后缀记录大小总和
            if(FileSuffixSize.contains(FileSuffix))FileSuffixSize[FileSuffix] += FileSize;
            else FileSuffixSize.insert(FileSuffix, FileSize);

            // 基于文件后缀记录大小总数
            if(FileSuffixNum.contains(FileSuffix))FileSuffixNum[FileSuffix] ++;
            else FileSuffixNum.insert(FileSuffix, 1);
        }
    }

    qDebug() << "文件大小总和：" << FileTotalSize;
    qDebug() << "文件后缀记录大小总和：" << FileSuffixSize;
    qDebug() << "文件后缀记录大小总数：" << FileSuffixNum;

    QMap<QString, QMap<QString, double>> FileNameSimilarList;
    QList<QString> FileIDs = FileIDtoName.keys();
    for(int i = 0; i < FileIDs.size(); i++){
        QMap<QString, double> lsList;
        for(int j = 0; j < FileIDs.size(); j++){
            if(FileNameSimilarList.contains(FileIDs[j]) && FileNameSimilarList[FileIDs[j]].contains(FileIDs[i])){
                lsList.insert(FileIDs[j], FileNameSimilarList[FileIDs[j]].value(FileIDs[i]));
            }
            else{
                lsList.insert(FileIDs[j], CalculateStringSimilarity(FileIDtoName[FileIDs[i]], FileIDtoName[FileIDs[j]]));
            }
        }
        FileNameSimilarList.insert(FileIDs[i], lsList);
    }
    qDebug() << FileNameSimilarList;
}

double FileTools::CalculateStringSimilarity(QString Str1, QString Str2)
{
    if(Str1 == Str2)return 1.0;

    Str1 = Str1.toLower();
    Str2 = Str2.toLower();

    QVector<QChar> Str1List;
    QVector<QChar> Str2List;
    QMap<QChar, int> AllStrList;

    for(int i = 0; i < Str1.size(); i++){
        if(Str1[i] != " "){
            Str1List.push_back(Str1[i]);
            AllStrList.insert(Str1[i], 0);
        }
    }

    for(int i = 0; i < Str2.size(); i++){
        if(Str2[i] != " "){
            Str2List.push_back(Str2[i]);
            AllStrList.insert(Str2[i], 0);
        }
    }
    QList<QChar> AllStrListKey = AllStrList.keys();

    const int AllStrSize = AllStrListKey.size();
    QVector<int> Str1ListKey;
    QVector<int> Str2ListKey;

    for(int i = 0; i < Str1List.size(); i++){
        for(int j = 0; j < AllStrSize; j++){
            if(Str1List[i] == AllStrListKey[j]){
                Str1ListKey.push_back(j);
                break;
            }
        }
    }

    for(int i = 0; i < Str2List.size(); i++){
        for(int j = 0; j < AllStrSize; j++){
            if(Str2List[i] == AllStrListKey[j]){
                Str2ListKey.push_back(j);
                break;
            }
        }
    }

    QVector<int> Str1OneHot;
    QVector<int> Str2OneHot;

    for(int i = 0; i < AllStrSize; i++){
        Str1OneHot.push_back(0);
        Str2OneHot.push_back(0);
    }
    for(int i = 0; i < Str1ListKey.size(); i++){
        Str1OneHot[Str1ListKey[i]] ++;
    }
    for(int i = 0; i < Str2ListKey.size(); i++){
        Str2OneHot[Str2ListKey[i]] ++;
    }

    int Key = 0;
    int LowKey1 = 0;
    int LowKey2 = 0;
    for(int i = 0; i < AllStrSize; i++){
        Key += Str1OneHot[i] * Str2OneHot[i];
        LowKey1 += Str1OneHot[i] * Str1OneHot[i];
        LowKey2 += Str2OneHot[i] * Str2OneHot[i];
    }

    double LowKey1Sqrt = qSqrt(LowKey1);
    double LowKey2Sqrt = qSqrt(LowKey2);
    return double(Key) / (LowKey1Sqrt * LowKey2Sqrt);
}
