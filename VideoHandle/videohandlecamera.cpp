#include "videohandlecamera.h"
#pragma execution_character_set("utf-8")

VideoHandleCamera::VideoHandleCamera(QObject *parent) :
    QThread(parent)
{
    // 加载特征数据
    QString filterPath = QDir::currentPath() + "/../../PublicTools/opencv/sources/data/haarcascades/haarcascade_frontalface_alt_tree.xml";
    face_detector = cv::CascadeClassifier(filterPath.toStdString());

    cap = new VideoCapture(0);
    if (!cap->isOpened()) {
        qDebug() << "无法打开摄像头";
    }
    else{
        QTimer *timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &VideoHandleCamera::getVideoFPS);
        timer->start(30); // 每秒10帧
    }

}

VideoHandleCamera::~VideoHandleCamera()
{

}

void VideoHandleCamera::getVideoFPS()
{
    cv::Mat outImage;
    cap->read(outImage); // 从摄像头读取新的帧

    ImageList.push_back(outImage);
}

void VideoHandleCamera::run()
{
    while(true){

        if(ImageList.size() != 0){
            Mat outImage = ImageList.first();

            Mat grayImage;
            std::vector<Rect> faceRect;
            cv::cvtColor(outImage, grayImage, cv::COLOR_BGR2GRAY); // 将图片转换为灰度图片
            face_detector.detectMultiScale(grayImage, faceRect, 1.1);
            for(unsigned int i = 0; i < faceRect.size(); i++){
                rectangle(outImage, Point(faceRect[i].x, faceRect[i].y), Point(faceRect[i].x + faceRect[i].width, faceRect[i].y + faceRect[i].height), Scalar(0, 0, 255), 2);
                circle(outImage, Point(faceRect[i].x + faceRect[i].width / 2, faceRect[i].y + faceRect[i].height / 2), faceRect[i].width / 2, Scalar(0, 255, 0), 2);
            }
            qDebug() << "识别人脸数：" << faceRect.size();

            QPixmap outPixmap = cvMatToQPixmap(outImage);
            emit sendVideoFPS(outPixmap);

            ImageList.pop_front();
        }
    }
}

QPixmap VideoHandleCamera::cvMatToQPixmap(const Mat &inMat)
{
    return QPixmap::fromImage(cvMatToQImage(inMat));
}

QImage VideoHandleCamera::cvMatToQImage(const Mat &inMat)
{
    if (inMat.type() == CV_8UC1)
    {
        QImage image(inMat.cols, inMat.rows, QImage::Format_Indexed8);
        // Set the color table (used to translate colour indexes to qRgb values)
        image.setColorCount(256);
        for (int i = 0; i < 256; i++)
        {
            image.setColor(i, qRgb(i, i, i));
        }
        // Copy input Mat
        uchar* pSrc = inMat.data;
        for (int row = 0; row < inMat.rows; row++)
        {
            uchar* pDest = image.scanLine(row);
            memcpy(pDest, pSrc, inMat.cols);
            pSrc += inMat.step;
        }
        return image;
    }
    // 8-bits unsigned, NO. OF CHANNELS = 3
    else if (inMat.type() == CV_8UC3)
    {
        // Copy input Mat
        const uchar* pSrc = (const uchar*)inMat.data;
        // Create QImage with same dimensions as input Mat
        QImage image(pSrc, inMat.cols, inMat.rows, inMat.step, QImage::Format_RGB888);
        return image.rgbSwapped();
    }
    else if (inMat.type() == CV_8UC4)
    {
        // Copy input Mat
        const uchar* pSrc = (const uchar*)inMat.data;
        // Create QImage with same dimensions as input Mat
        QImage image(pSrc, inMat.cols, inMat.rows, inMat.step, QImage::Format_ARGB32);
        return image.copy();
    }
    else
    {
        //MessageInfo("ERROR: Mat could not be converted to QImage.", 1);
        //emit sig_RunInfo("ERROR: Mat could not be converted to QImage.", 1);
        //if (!globalPara.IsInlineRun) Runstateinfo("ERROR: Mat could not be converted to QImage.", 1);
        return QImage();
    }
}
