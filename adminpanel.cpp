#include "adminpanel.h"
#include "ui_adminpanel.h"

#include <QListWidget>

AdminPanel::AdminPanel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminPanel)
{
    ui->setupUi(this);
    this->setWindowTitle("ADMIN PANNEL");
    ui->listWidget->addItem("test");
}

void AdminPanel::showPersons()
{
   for(Person* item : listPerson)
   {
       QString mainLine = item->name + " " + item->surname;
       ui->listWidget->addItem(mainLine);
   }
}

AdminPanel::~AdminPanel()
{
    delete ui;
}

void AdminPanel::takeList(QList<Person *>list)
{
    for(Person * item : list)
    {
        listPerson.append(item);
    }
    showPersons();
}
