#ifndef CAGORAOBJECT_H
#define CAGORAOBJECT_H

#include <Memory>
#include <mutex>

//Specify your APP ID here
#define APP_ID ""

#include <QString>
#include <QVariant>
#include <IAgoraRtcEngine.h>
#include <IAgoraMediaEngine.h>
using namespace agora::rtc;

#define XM_BOOL bool
#define XM_TRUE true
#define XM_FALSE false
typedef void* XM_HWND;

typedef QMap<QString,QString> qSSMap;

class CAgoraObject:public QObject
{
    Q_OBJECT
public:

    int joinChannel(const QString& key, const QString& channel, uint uid);
    int leaveChannel();
    int muteLocalAudioStream(bool muted);
    XM_BOOL LocalVideoPreview(XM_HWND hVideoWnd, XM_BOOL bPreviewOn, RENDER_MODE_TYPE renderType = RENDER_MODE_TYPE::RENDER_MODE_FIT);
    XM_BOOL RemoteVideoRender(uid_t uid, XM_HWND hVideoWnd, RENDER_MODE_TYPE renderType = RENDER_MODE_TYPE::RENDER_MODE_HIDDEN);

    int enableVideo(bool enabled);
    int enableAudio(bool enabled);
    XM_BOOL MuteLocalVideo(XM_BOOL bMute);
    XM_BOOL MuteLocalAudio(XM_BOOL bMute);

    XM_BOOL setLogPath(const QString &strDir);
    XM_BOOL SetChannelProfile(CHANNEL_PROFILE_TYPE channelType);
    XM_BOOL SetClientRole(CLIENT_ROLE_TYPE roleType);
    XM_BOOL EnableWebSdkInteroperability(XM_BOOL bEnable);

    qSSMap getRecordingDeviceList();
    qSSMap getPlayoutDeviceList();
    qSSMap getVideoDeviceList();

    int setRecordingDevice(const QString& guid);
    int setPlayoutDevice(const QString& guid);
    int setVideoDevice(const QString& guid);

    XM_BOOL setVideoProfile(int nWidth,int nHeight);
    XM_BOOL setRecordingIndex(int nIndex);
    XM_BOOL setPlayoutIndex(int nIndex);
    XM_BOOL setVideoIndex(int nIndex);

	bool setBeautyEffectOptions(bool enabled, BeautyOptions& options);

signals:
    void sender_videoStopped();
    void sender_joinedChannelSuccess(const QString &qsChannel, unsigned int uid, int elapsed);
    void sender_userJoined(unsigned int uid, int elapsed);
    void sender_userOffline(unsigned int uid, USER_OFFLINE_REASON_TYPE reason);
    void sender_firstLocalVideoFrame(int width, int height, int elapsed);
    void sender_firstRemoteVideoDecoded(unsigned int uid, int width, int height, int elapsed);
    void sender_firstRemoteVideoFrameDrawn(unsigned int uid, int width, int height, int elapsed);
    void sender_localVideoStats(const LocalVideoStats &stats);
    void sender_remoteVideoStats(const RemoteVideoStats &stats);
    void sender_rtcStats(const RtcStats &stats);

public:
    static CAgoraObject* getInstance(QObject *parent = 0);
    static CAgoraObject* m_pInstance;
    static std::mutex    m_mutex;

private:
    explicit CAgoraObject(QObject *parent = 0);
    ~CAgoraObject();

    agora::rtc::IRtcEngine* m_rtcEngine;
    std::unique_ptr<agora::rtc::IRtcEngineEventHandler> m_eventHandler;
};

#endif // CAGORAOBJECT_H
