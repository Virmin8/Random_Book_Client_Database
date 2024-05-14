#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private slots:
    void on_Add_book_pushButton_clicked();

    void on_Add_Client_pushButton_clicked();

    void on_Issue_Book_pushButton_clicked();

    void on_Return_Book_pushButton_clicked();

    void on_List_all_pushButton_clicked();

    void on_Client_Return_comboBox_currentTextChanged(const QString &arg1);

    void on_Write_Book_pushButton_clicked();

    void on_Write_Client_pushButton_clicked();

    void printList(QList<QObject *> object);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
