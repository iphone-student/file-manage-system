#include "cameramanage.h"
CameraManage* CameraManage::m_instance = nullptr;

CameraManage::CameraManage()
{
    initCameraInfo();
}

void CameraManage::linkCamera(QString Info, QWidget *VideoWidget)
{
    if(Camera->status() == QCamera::ActiveStatus) Camera->stop();
    Viewfinder = new QCameraViewfinder(VideoWidget);

    for(int i = 0; i < CamerasInfo.size(); i++){
        if(CamerasInfo[i].description() == Info){
            Camera = new QCamera(CamerasInfo.at(i));
            Camera->setViewfinder(Viewfinder);
            Camera->start();
        }
    }
}

void CameraManage::initCameraInfo()
{
    CamerasInfo = QCameraInfo::availableCameras();
    CameraNum = CamerasInfo.size();
    Camera = new QCamera();

    CameraNames.clear();
    for(int i = 0; i < CamerasInfo.size(); i++)
        CameraNames.push_back(CamerasInfo[i].description());
}

CameraManage *CameraManage::getInstance()
{
    if (!m_instance) {
        m_instance = new CameraManage;
    }

    return m_instance;
}
