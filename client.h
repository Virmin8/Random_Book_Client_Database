#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QDate>
#include <QList>

class Client : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString Name READ getClientName)
    Q_PROPERTY(QDate Date READ getClientDate)
public:
    Client(QString name, QDate date);
    void setClient(QString name);
    QString getClientName();
    void setClientDate(QDate date);
    QDate getClientDate();

private:
    QString C_Name;
    QDate C_Date;

};

#endif // CLINET_H
