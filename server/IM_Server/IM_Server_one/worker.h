#ifndef WORKER_H
#define WORKER_H
#include <QDebug>
#include <QObject>
#include <QThread>
#include <QString>


class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);

signals:

public slots:
    void dowork();
    void registe(QStringList & registerInfo);
    void privateChat(QVariantMap&);
	void doingCAPTCHA(QStringList &CAPTCHAInfo);
private:
    QMap<QString ,QString> userinfo;
    QMap<QString ,QString> userVerification;
};

#endif // WORKER_H
