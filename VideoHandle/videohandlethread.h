#ifndef VIDEOHANDLETHREAD_H
#define VIDEOHANDLETHREAD_H

#include <vector>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/opencv.hpp>

#include <QDir>
#include <QImage>
#include <QDebug>
#include <QObject>
#include <QThread>
#include <QPixmap>

#include "VideoHandle_Global.h"

using namespace cv;
using namespace std;

class VIDEOHANDLE_EXPORT VideoHandleThread : public QThread
{
    Q_OBJECT

public:
    VideoHandleThread(QObject* parent = nullptr);
    ~VideoHandleThread();

    QVector<QString> VideoList;

protected:
    void run() override;

signals:
    void sendVideoFPS(QPixmap);

private:
    QPixmap cvMatToQPixmap(const cv::Mat &inMat);
    QImage cvMatToQImage(const cv::Mat &inMat);

};

#endif // VIDEOHANDLETHREAD_H
