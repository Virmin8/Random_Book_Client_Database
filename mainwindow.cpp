#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "book.h"
#include "client.h"
#include <QMap>
#include <QMessageBox>
#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QMetaProperty>
#include <QVariant>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

QList<QObject*> book;
QList<QObject*> client;
QMap<QString,QStringList> lists;

void MainWindow::printList(QList<QObject*> obj)
{
    QString filename = ui->write_linedit->text();
    QFile file(filename);
    file.open(QIODevice::Append);
    QTextStream toFile(&file);



        for(int k = 0; k < obj.count(); k++)
        {
            const QMetaObject *mo = obj[k]->metaObject();

            for( int i = mo->propertyOffset(); i < mo->propertyCount(); i++)
            {

                QMetaProperty prop = mo->property(i);
                QString name = prop.name();
                QVariant value = prop.read(obj[k]);
                QString valStr = value.toString();

                toFile << name << ": " << valStr << Qt::endl;
            }
        }
        toFile << Qt::endl;
    file.close();
    ui->write_linedit->clear();


}

 void MainWindow::on_Add_book_pushButton_clicked()
{

   QString _author = ui->Author_lineEdit->text();
    QString _title = ui->Title_lineEdit->text();
    double _cost = ui->Cost_doubleSpinBox->value();

    Book* defaultBook = new Book(_author,_title,_cost);

    book.append(defaultBook);

    ui->Author_lineEdit->clear();
    ui->Title_lineEdit->clear();
    ui->Cost_doubleSpinBox->clear();

    ui->Book_Issue_comboBox->addItem(defaultBook->getBookTitle());
    ui->Book_Issue_comboBox->model()->sort(0);

}

void MainWindow::on_Add_Client_pushButton_clicked()
{
    QString _name = ui->Name_lineEdit->text();
    QDate _date = ui->Joining_dateEdit->date();

    Client* defaultClient = new Client(_name,_date);

    client.append(defaultClient);


    ui->Name_lineEdit->clear();
    ui->Joining_dateEdit->clear();


    ui->Client_Issue_comboBox->addItem(defaultClient->getClientName());
    ui->Client_Issue_comboBox->model()->sort(0);

}


void MainWindow::on_Issue_Book_pushButton_clicked()
{

    QString name = ui->Client_Issue_comboBox->currentText();
    QString book = ui->Book_Issue_comboBox->currentText();

    QStringList add = lists.value(name);
    add << book;
    lists.insert(name,add);


    QStringList ComboBoxList;
    for(int k = 0; k < ui->Client_Return_comboBox->count(); k++)
    {
        ComboBoxList << ui->Client_Return_comboBox->itemText(k);
    }
    if(!ComboBoxList.contains(name))
    {
        ui->Client_Return_comboBox->addItem(name);
        ui->Client_Return_comboBox->model()->sort(0);
    }

    ui->Book_return_comboBox->clear();
    QStringList temp = lists.value(ui->Client_Return_comboBox->currentText());
    temp.sort();
    ui->Book_return_comboBox->addItems(temp);


}

void MainWindow::on_Return_Book_pushButton_clicked()
{
    QString name = ui->Client_Return_comboBox->currentText();
    QString book = ui->Book_return_comboBox->currentText();

    QStringList ComboBoxList = lists.value(name);


    for(int k = 0; k < ComboBoxList.count(); k++)
    {
        if(ComboBoxList[k] == book)
        {
            ComboBoxList.removeAt(k);
            break;
        }
    }

    lists.insert(name,ComboBoxList);

    ui->Book_return_comboBox->clear();
    QStringList temp = lists.value(name);
    temp.sort();
    ui->Book_return_comboBox->addItems(temp);

    if(ComboBoxList.isEmpty())
    {
        QStringList ComboBox;
        for(int k = 0; k < ui->Client_Return_comboBox->count(); k++)
        {
            if(ui->Client_Return_comboBox->itemText(k) == name)
                ui->Client_Return_comboBox->removeItem(k);
        }

    }
}

void MainWindow::on_List_all_pushButton_clicked()
{
    ui->listWidget->clear();
    foreach (QStringList value, lists)
    ui->listWidget->addItems(value);
}


void MainWindow::on_Client_Return_comboBox_currentTextChanged(const QString &arg1)
{
    ui->Book_return_comboBox->clear();
    QStringList temp = lists.value(ui->Client_Return_comboBox->currentText());
    temp.sort();
    ui->Book_return_comboBox->addItems(temp);

}

void MainWindow::on_Write_Book_pushButton_clicked()
{
     printList(book);
}

void MainWindow::on_Write_Client_pushButton_clicked()
{ 
   printList(client);
}

