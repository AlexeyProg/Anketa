#ifndef ADMINPANEL_H
#define ADMINPANEL_H

#include <QDialog>
#include <QList>
#include "person.h"

namespace Ui {
class AdminPanel;
}

class AdminPanel : public QDialog
{
    Q_OBJECT

public:
    explicit AdminPanel(QWidget *parent = nullptr);
    ~AdminPanel();
    void takeList(QList<Person*>&list);

private:
    void showPersons();
    QList<Person*>listPerson;
    Ui::AdminPanel *ui;
};

#endif // ADMINPANEL_H
