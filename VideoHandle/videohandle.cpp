#include "videohandle.h"
VideoHandle* VideoHandle::m_instance = nullptr;

VideoHandle::VideoHandle(QObject* parent)
    : QObject(parent)
{
    HandleThread = new VideoHandleThread();
    HandleThread->start();
    connect(HandleThread, SIGNAL(sendVideoFPS(QPixmap)), this, SLOT(receiveVideoFPS(QPixmap)));

    HandleCamera = new VideoHandleCamera();
    HandleCamera->start();
    connect(HandleCamera, SIGNAL(sendVideoFPS(QPixmap)), this, SLOT(receiveVideoFPS(QPixmap)));
}

VideoHandle::~VideoHandle()
{

}

VideoHandle *VideoHandle::getInstance()
{
    if (!m_instance) {
        m_instance = new VideoHandle;
    }

    return m_instance;
}

void VideoHandle::addVideoPath(QString path)
{
    HandleThread->VideoList.push_back(path);
}

void VideoHandle::receiveVideoFPS(QPixmap pixmap)
{
    emit sendVideoFPS(pixmap);
}
