#ifndef BOOK_H
#define BOOK_H
#include <QString>
#include <QList>
#include <QObject>

class Book : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString Author READ getBookAuthor)
    Q_PROPERTY(QString Title READ getBookTitle)
    Q_PROPERTY(double Cost READ getBookCost)

public:
    Book(QString author, QString title, double cost);
    void setBookAuthor(QString author);
    void setBookTitle(QString title);
    void setBookCost(double cost);
    QString getBookAuthor();
    QString getBookTitle();
    double getBookCost();

private:
    QString B_author;
    QString B_title;
    double B_cost;
};

#endif // BOOK_H
