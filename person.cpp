#include "person.h"

Person::Person(QObject *parent)
    : QObject{parent}
{

}

void Person::setAge(int mAge)
{
    age = mAge;
}

void Person::setCitizen(QString mCitizen)
{
    citizen = mCitizen;
}

void Person::setHardSkills(QString mSkills)
{
    hardSkills = mSkills;
}

void Person::setSurname(QString mSurname)
{
    surname = mSurname;
}

void Person::setName(QString mName)
{
    name = mName;
}
