#ifndef VIDEOHANDLE_H
#define VIDEOHANDLE_H

#include <QObject>

#include "videohandlethread.h"
#include "videohandlecamera.h"
#include "VideoHandle_Global.h"

class VIDEOHANDLE_EXPORT VideoHandle : public QObject
{
    Q_OBJECT

public:
    VideoHandle(QObject* parent = nullptr);
    ~VideoHandle();
    static VideoHandle* getInstance();

    void addVideoPath(QString path);

public slots:
    void receiveVideoFPS(QPixmap);

signals:
    void sendVideoFPS(QPixmap);


private:
    static VideoHandle* m_instance;
    VideoHandleThread *HandleThread;
    VideoHandleCamera *HandleCamera;
};

#endif // VIDEOHANDLE_H
