/* -------------------------------
 * Laboration 2
 * Uppgift 1
 * William Elfversson, wiel1300
 * 2019-02-03
 * -------------------------------*/


#include "Name.h"

void testDefaultConstructor ();
void testSetConstructor ();
std::string readConsole ();

int main()
{
    testDefaultConstructor();

    testSetConstructor();

    return 0;
}

void testDefaultConstructor ()
{
    Name testName1;
    std::cout << "Please enter your first name: ";
    testName1.setFirstName(readConsole());
    std::cout << "And last name please: ";
    testName1.setLastName(readConsole());
    std::cout << "Welcome " << testName1.getFirstName() + " " + testName1.getLastName() << std::endl;
}

void testSetConstructor ()
{
    Name testName2 ("William", "Elfversson");
    std::cout << "Welcome " << testName2.getFirstName() + " " + testName2.getLastName() << std::endl;
}

std::string readConsole ()
{
    std::string str;
    std::getline(std::cin, str);
    return str;
}