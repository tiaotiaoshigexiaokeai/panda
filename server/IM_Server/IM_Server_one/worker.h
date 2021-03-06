#ifndef WORKER_H
#define WORKER_H
#include <QDebug>
#include <QObject>
#include <QThread>
#include <QString>
#include "mysql.h"
#include "dataparsing.h"
#include <QTcpSocket>
#include <QTimer>
class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);
    Dataparsing* m_dataParse = nullptr;
    QVariantMap m_returnDataToClient;
    QByteArray m_sendData;
    static QMap<QString, QTcpSocket *> m_userSocket;//socket 列表
    QTimer* m_timer = nullptr;


signals:
    void finish();


public slots:
    void doWork(QByteArray& message);//入口函数
    QVariantMap registe(QStringList & registerInfo);//注册函数
    QVariantMap updateUserList();//更新用户名列表函数
    QVariantMap loginIn(QStringList & userInfoList);//登录函数
    QVariantMap privateChat(QVariantMap&);//私聊函数
    QVariantMap doingCAPTCHA(QStringList &CAPTCHAInfo);
    QVariantMap helpingOther(QStringList &HelpingInfo);

    void abnormalHeartBeat();
    QVariantMap normalHeartBeat();
    QVariantMap Signout(QStringList &SignoutInfo);//退出函数
    QVariantMap groupChat(QVariantMap &groupChatInfo);//群聊函数
    void recSocketDescriptor(qintptr);//接受socket 描述符号

private:
    QMap<QString ,QString> userinfo;
    QMap<QString ,QString> userVerification;
    QTcpSocket* m_tcpSocket = nullptr;
    QByteArray m_recData;
    int m_count = 0;
    QString m_userName;


};

#endif // WORKER_H
