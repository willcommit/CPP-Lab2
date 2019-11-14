
#include "PersonList.h"

void PersonList::setFileName(std::string FileName)
{
    fileName = FileName;
}

std::string PersonList::getFileName () const
{
    return fileName;
}

void PersonList::addPerson (Person const &person)
{
    personList.push_back(person);
}

Person PersonList::getPerson(int idx) const
{
    return personList[idx];
}

int PersonList::getPersonCount ()
{
    return personList.size();
}

void PersonList::sortName ()
{
    std::sort(personList.begin(), personList.end(),
              [](Person p1, Person p2) { return p1.getPersonName() < p2.getPersonName(); });
    std::cout << "List sorted!" << std::endl;
}

void PersonList::sortIDnr()
{
    std::sort(personList.begin(), personList.end(),
              [](Person p1, Person p2) { return p1.getIdNr() < p2.getIdNr(); });
    std::cout << "List sorted!" << std::endl;
}

void PersonList::sortShoeNr()
{
    std::sort(personList.begin(), personList.end(),
              [](Person p1, Person p2) { return p1.getShoeNr() < p2.getShoeNr(); });
    std::cout << "List sorted!" << std::endl;
}

