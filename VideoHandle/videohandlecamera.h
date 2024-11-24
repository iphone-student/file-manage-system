#ifndef VIDEOHANDLECAMERA_H
#define VIDEOHANDLECAMERA_H

#include <vector>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/opencv.hpp>

#include <QDir>
#include <QTimer>
#include <QImage>
#include <QDebug>
#include <QObject>
#include <QThread>
#include <QPixmap>

#include "VideoHandle_Global.h"

using namespace cv;
using namespace std;

class VIDEOHANDLE_EXPORT VideoHandleCamera : public QThread
{
    Q_OBJECT

public:
    VideoHandleCamera(QObject* parent = nullptr);
    ~VideoHandleCamera();

private slots:
    void getVideoFPS();

protected:
    void run() override;

signals:
    void sendVideoFPS(QPixmap);

private:
    VideoCapture *cap;

private:
    QPixmap cvMatToQPixmap(const cv::Mat &inMat);
    QImage cvMatToQImage(const cv::Mat &inMat);

    QVector<Mat> ImageList;
    CascadeClassifier face_detector;
};

#endif // VIDEOHANDLECAMERA_H
