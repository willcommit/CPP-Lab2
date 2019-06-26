/* -------------------------------
 * Laboration 2
 * Uppgift 3
 * William Elfversson, wiel1300
 * 2019-02-03
 * -------------------------------*/

#include <iostream>
#include <string>
#include <vector>
#include "Person.h"

//FUNCTION DECLARATION
void printMenu();
int userSelect ();
// takes user choice, person list and program state to control program flow
void optionSelect (int choice, std::vector<Person> &personList, bool &programState);
//creates new Person objects via user input
Person createPerson ();
//overloaded function for default person
Person createPerson (std::string dName, std::string dAddress, std::string dIdNr, int dShoeNr);
void addPerson (Person person, std::vector<Person> &personList);
void printPerson (Person person);
void printPersonList (std::vector<Person> &personList);
std::string readConsoleString ();
int readConsoleInt ();
bool questionPrompt (std::string question);

//MAIN PROGRAM
int main()
{
    std::vector<Person> personList;
    bool programState = true;

    addPerson(createPerson("Donald Trump", "A white house, Washington", "2004/03/02", 32), personList);
    addPerson(createPerson("Darth Vader", "Death Star, Dark Sector", "423423/03/02", 55), personList);
    addPerson(createPerson("Frodo Baggins", "Fylke, Hobbits place", "213/03/02", 45), personList);

    do{
        printMenu();
        optionSelect(userSelect(), personList, programState);
    }
    while (programState);

    return 0;
}

//FUNCTION DEFINITIONS, consider new headers/classes.
void printMenu()
{
    std::cout <<"\nMENU"
        <<"\n=============================="
        <<"\n1. Add a person to list"
        <<"\n2. Print person list"
        <<"\n3. Quit"
        <<"\n=============================="
        <<"\nPlease select menu option: " << std::endl;
}

int userSelect ()
{
    int userChoice {0};
    std::cin >> userChoice;
    std::cin.get();
    return userChoice;
}

void optionSelect (int choice, std::vector<Person> &personList, bool &programState)
{
    switch (choice){
        case 1:
            addPerson(createPerson(), personList);
            break;
        case 2:
            printPersonList(personList);
            break;
        case 3:
            programState = !questionPrompt("Do wish to quit?");
            break;
    }
}

Person createPerson ()
{
    Person newPerson;

    std::cout << "Please enter your name: ";
    newPerson.setName(readConsoleString());
    std::cout << "Please enter your address(STREET, ZIP, CITY): ";
    newPerson.setAddress(readConsoleString());
    std::cout << "Please enter your ID number: ";
    newPerson.setIdNr(readConsoleString());
    std::cout << "Please enter you shoe size: ";
    newPerson.setShoeNr(readConsoleInt());

    return newPerson;
}

Person createPerson (std::string dName, std::string dAddress, std::string dIdNr, int dShoeNr)
{
    Person newPerson (dName,dAddress,dIdNr,dShoeNr);

    return newPerson;
}

void addPerson (Person person, std::vector<Person> &personList)
{
    personList.push_back(person);
}

void printPerson (Person person)
{
    std::cout <<"\n==========[PERSON DATA]========="
              <<"\nName: " << person.getName()
              <<"\nAddress: " << person.getAddress()
              <<"\nID number: " << person.getIdNr()
              <<"\nShoe size: " << person.getShoeNr()
              <<"\n==============================" << std::endl;
}

void printPersonList (std::vector<Person> &personList)
{
    for(auto person: personList)
        printPerson(person);
}

std::string readConsoleString ()
{
    std::string str;
    std::getline(std::cin, str);
    return str;
}

int readConsoleInt ()
{
  int integer {0};
  std::cin >> integer;
  std::cin.get();
  return integer;
}

bool questionPrompt (std::string question)
{
    char reply;
    std::cout << question << " [Y/N] ";
    std::cin >> reply;
    std::cin.get();

    return !(reply == 'n' || reply == 'N');
}