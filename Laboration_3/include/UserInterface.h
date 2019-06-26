
#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <iostream>
#include <fstream>
#include <sstream>

#include "PersonList.h"

class UserInterface
{
    private:
        PersonList listOfPersons;
    public:
        //runs program, includes several of below member functions
        void run();
        void showMenu();
        int userSelect();
        void optionSelect (int choice, bool &programState);
        void addPersonToList();
        void printPerson (Person person);
        void printPersonList();
        void save();
        void load();
        std::string readConsoleString ();
        int readConsoleInt ();
        bool questionPrompt (std::string question);
};

#endif //USERINTERFACE_H
