#include "UserInterface.h"


void UserInterface::run()
{
    bool programState = true;
    do{
        showMenu();
        optionSelect(userSelect(), programState);
    }
    while (programState);
}

void UserInterface::showMenu()
{
    std::cout <<"\nMENU"
              <<"\n=============================="
              <<"\n1. Add a person to list"
              <<"\n2. Print person list"
              <<"\n3. Sort by name"
              <<"\n4. Sort by ID number"
              <<"\n5. Sort by ShoeNr"
              <<"\n6. Save"
              <<"\n7. Load"
              <<"\n8. Quit"
              <<"\n=============================="
              <<"\nPlease select menu option: ";
    std::cout.flush();
}

int UserInterface::userSelect()
{
    int userChoice {0};
    std::cin >> userChoice;
    std::cin.get();
    return userChoice;
}

void UserInterface::optionSelect (int choice,  bool &programState)
{
    switch (choice){
        case 1:
            addPersonToList();
            break;
        case 2:
            printPersonList();
            break;
        case 3:
            listOfPersons.sortName();
            break;
        case 4:
            listOfPersons.sortIDnr();
            break;
        case 5:
            listOfPersons.sortShoeNr();
            break;
        case 6:
            save();
            break;
        case 7:
            load();
            break;
        case 8:
            programState = !questionPrompt("Do wish to quit?");
            break;
        default:
            std::cout << "ERROR!!!" << std::endl;
            break;
    }
}

void UserInterface::addPersonToList()
{
    Name newName;

    std::cout << "Please enter your first name: ";
    newName.setFirstName(readConsoleString());
    std::cout << "Please enter your last name: ";
    newName.setLastName(readConsoleString());

    Address newAddress;

    std::cout << "Please enter your street address: ";
    newAddress.setStreet(readConsoleString());
    std::cout << "Please enter your zip number: ";
    newAddress.setZip(readConsoleString());
    std::cout << "Please enter your city: ";
    newAddress.setCity(readConsoleString());

    Person newPerson (newName,newAddress);

    std::cout << "Please enter your ID number: ";
    newPerson.setIdNr(readConsoleString());
    std::cout << "Please enter your shoe size: ";
    newPerson.setShoeNr(readConsoleInt());

    listOfPersons.addPerson(newPerson);
}


void UserInterface::printPerson (Person person)
{
    std::cout <<"\n==========[PERSON DATA]========="
              <<"\nName: "      << person.getPersonName().getFirstName() << " "
                                << person.getPersonName().getLastName()
              <<"\nAddress: "   << person.getPersonAddress().getStreet() << ", "
                                << person.getPersonAddress().getZip()  << ", "
                                << person.getPersonAddress().getCity()
              <<"\nID number: " << person.getIdNr()
              <<"\nShoe size: " << person.getShoeNr()
              <<"\n==============================" << std::endl;
}

void UserInterface::printPersonList()
{
    for (int i = 0; i < listOfPersons.getPersonCount(); ++i) {
        printPerson(listOfPersons.getPerson(i));
    }
}

void UserInterface::save()
{
    std::cout << "Please enter a filename to save to: ";
    listOfPersons.setFileName(readConsoleString());

    std::ofstream outFile{listOfPersons.getFileName(), std::ios::trunc};

    if(!outFile){
        std::cerr <<"ERROR creating file!" << std::endl;
    }
    for (int i = 0; i < listOfPersons.getPersonCount(); ++i) {
        outFile << listOfPersons.getPerson(i) <<std::endl;
    }
    outFile.close();
    std::cout << "File saved!" << std::endl;
}

void UserInterface::load()
{
    if (!questionPrompt("Do you wish to load " + listOfPersons.getFileName() + "?")){
        std::string tmpFileName;
        std::cout << "Please enter a filename to load: ";
        std::getline(std::cin,tmpFileName);
        listOfPersons.setFileName(tmpFileName);
    }

    std::ifstream inFile;
    std::string line;
    std::string holdFloat;

    inFile.open(listOfPersons.getFileName());

    if(inFile.is_open()){

        while(std::getline(inFile, line)){
            std::istringstream is(line);
            Person newPerson;
            is >> newPerson;
            listOfPersons.addPerson(newPerson);
        }
        std::cout << "File loaded successfully!" << std::endl;
        inFile.close();
    }
    else
        std::cerr <<"ERROR opening file!" << std::endl;
}


std::string UserInterface::readConsoleString ()
{
    std::string str;
    std::getline(std::cin, str);
    return str;
}

int UserInterface::readConsoleInt ()
{
    int integer {0};
    std::cin >> integer;
    std::cin.get();
    return integer;
}

bool UserInterface::questionPrompt (std::string question)
{
    char reply;
    std::cout << question << " [Y/N] ";
    std::cin >> reply;
    std::cin.get();

    return !(reply == 'n' || reply == 'N');
}