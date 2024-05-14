#include "client.h"


Client::Client(QString name, QDate date)
{
    C_Name = name;
    C_Date = date;
}

void Client::setClient(QString name)
{
    C_Name = name;

}

void Client::setClientDate(QDate date)
{
    C_Date = date;
}

QString Client::getClientName()
{
    return C_Name;
}

QDate Client::getClientDate()
{
    return C_Date;
}
