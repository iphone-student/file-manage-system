#ifndef CAMERAMANAGE_H
#define CAMERAMANAGE_H

#include <QCamera>
#include <QCameraInfo>
#include <QCameraViewfinder>
#include <QCameraImageCapture>

#include "CameraManage_global.h"

class CAMERAMANAGE_EXPORT CameraManage
{
public:
    CameraManage();

    void linkCamera(QString Info, QWidget *VideoWidget);
    void initCameraInfo();
    static CameraManage *getInstance();

    int CameraNum = 0;
    QStringList CameraNames;
    QCameraViewfinder *Viewfinder;

private:
    static CameraManage* m_instance;
    QList<QCameraInfo> CamerasInfo;
    QCamera *Camera;
};

#endif // CAMERAMANAGE_H
