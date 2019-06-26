/* -------------------------------
 * Laboration 2
 * Uppgift 2
 * William Elfversson, wiel1300
 * 2019-02-03
 * -------------------------------*/


#include "Address.h"

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
    Address testAddress1;
    std::cout << "Please enter your street: ";
    testAddress1.setStreet(readConsole());
    std::cout << "And zip code: ";
    testAddress1.setZip(readConsole());
    std::cout << "At last your city please: ";
    testAddress1.setCity(readConsole());
    std::cout << "You live at "
        << testAddress1.getStreet() + " " + testAddress1.getZip() + " " + testAddress1.getCity()
        << std::endl;
}

void testSetConstructor ()
{
    Address testAddress2 ("1600 Pennsylvania Ave NW", "DC 20500", "Washington");
    std::cout << "Your address is: "
        << testAddress2.getStreet() + " " + testAddress2.getZip() + " " + testAddress2.getCity()
        << std::endl;
}

std::string readConsole ()
{
    std::string str;
    std::getline(std::cin, str);
    return str;
}