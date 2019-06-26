
#ifndef DT019G_PERSONLIST_H
#define DT019G_PERSONLIST_H

#include <vector>
#include <string>
#include <algorithm> //sort

#include "Person.h"

class PersonList
{
    private:
        std::vector<Person> personList;
        std::string fileName;

    public:
        //constructor that initializes filename only
        PersonList() { fileName = "test.txt"; }

        //SET and GET of filename
        void setFileName(std::string FileName);
        std::string getFileName () const;

        Person getPerson(int idx) const;
        int getPersonCount ();
        // add person to list
        void addPerson(Person const &person);
        //sort functions, using algorithm library
        void sortName();
        void sortIDnr();
        void sortShoeNr();

    //choose not to implement below, how does it improve encapsulation?
    //see UserInterface class for load and save function.
    //    void readFromFile();
    //    void writeToFile();
};


#endif //DT019G_PERSONLIST_H
