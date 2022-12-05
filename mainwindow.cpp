#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("IT PROFILE");

}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::isSomeEmpty(QList<QLineEdit *> &listLines)
{
    QList<QLineEdit*> EmptyLinesList;
    for(QLineEdit* item : listLines)
    {
        if(item->text().isEmpty())
            EmptyLinesList.append(item);
        else
            item->setStyleSheet("");
    }

    //отдельно для qplaintext hard skills

    if(ui->plainTextEdit_hardSkills->toPlainText().isEmpty())
        ui->plainTextEdit_hardSkills->setStyleSheet("background-color: rgb(255, 65, 59);");
    else
        ui->plainTextEdit_hardSkills->setStyleSheet("");
    //

    if(!EmptyLinesList.isEmpty())
    {
        for(QLineEdit* item : EmptyLinesList)
        {
            item->setStyleSheet("background-color: rgb(255, 65, 59);");
        }
        QMessageBox::warning(this,"Error!","Вы заполнили не все поля!",QMessageBox::Default);
        return false;
    }
    return true;
}

void MainWindow::on_pushButton_send_clicked()
{
    QList<QLineEdit*> listLines ={ui->lineEdit_age,ui->lineEdit_citizenship,ui->lineEdit_name,
                                  ui->lineEdit_name,ui->lineEdit_secondname,ui->lineEdit_spec};
    if(isSomeEmpty(listLines))
    {
        Person *person = new Person();
        person->setAge(ui->lineEdit_age->text().toInt());
        person->setName(ui->lineEdit_name->text());
        person->setSurname(ui->lineEdit_secondname->text());
        person->setCitizen(ui->lineEdit_citizenship->text());
        person->setHardSkills(ui->plainTextEdit_hardSkills->toPlainText());

        addPersonToList(person);
    }

}

void MainWindow::addPersonToList(Person *pers)
{
    personList.append(pers);
}


void MainWindow::on_pushButton_adminpannel_clicked()
{
    AdminPanel *admin_dialog = new AdminPanel(this);
    admin_dialog->takeList(personList);
    admin_dialog->exec();
}

