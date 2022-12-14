#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QMessageBox>

#include "person.h"
#include "adminpanel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_pushButton_send_clicked();

    void on_pushButton_adminpannel_clicked();

private:
    Ui::MainWindow *ui;

    QList<Person*> personList;
    void addPersonToList(Person *pers);
    bool isSomeEmpty(QList<QLineEdit*> &listLines);
    void clearFields();
};
#endif // MAINWINDOW_H
