#ifndef PERSON_H
#define PERSON_H

#include <QObject>
#include <QList>

class Person : public QObject
{
    Q_OBJECT
public:
    explicit Person(QObject *parent = nullptr);

    QString name;
    QString surname;
    int age;
    QString citizen;
    QString hardSkills;
    bool flag;

    void setName(QString mName);
    void setAge(int mAge);
    void setSurname(QString mSurname);
    void setCitizen(QString mCitizen);
    void setHardSkills(QString mSkills);

    QList<Person*> personList;
    void addPersonToList(Person *p);
};

#endif // PERSON_H
