#include "book.h"

Book::Book(QString author, QString title, double cost)
{
    B_author = author;
    B_title = title;
    B_cost = cost;
}

void Book::setBookAuthor(QString author)
{
    B_author = author;
}

void Book::setBookTitle(QString title)
{
     B_title = title;
}

void Book::setBookCost(double cost)
{
     B_cost = cost;
}

QString Book::getBookAuthor()
{
    return B_author;
}

QString Book::getBookTitle()
{
    return B_title;
}

double Book::getBookCost()
{
    return B_cost;
}

