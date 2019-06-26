#include "Name.h"

Name::Name (std::string FirstName, std::string LastName)
    :firstName(FirstName), lastName(LastName) {
}

//get, set
void Name::setFirstName (std::string FirstName) { firstName = FirstName; }
void Name::setLastName (std::string LastName) { lastName = LastName; }
std::string Name::getFirstName () const { return firstName; }
std::string Name::getLastName () const  { return lastName; }

//operator overloading
bool Name::operator==(const Name &rhs) const{
    return firstName == rhs.firstName && lastName == rhs.lastName;
}

bool Name::operator<(const Name &rhs) const{
    if (lastName == rhs.lastName)
        return firstName < rhs.firstName;
    return lastName < rhs.lastName;
}

//-----------------------DIVIDER NON CLASS MEMBERS-----------------------

constexpr char DELIM ='_';

std::ostream &operator<<(std::ostream &os, const Name &name)
{
    os << name.getFirstName() << DELIM;
    os << name.getLastName() << DELIM;
    return os;
}

std::istream &operator>>(std::istream &is, Name &name)
{
    std::string tempString;

    std::getline(is,tempString,DELIM);
    name.setFirstName(tempString);
    std::getline(is,tempString,DELIM);
    name.setLastName(tempString);

    return is;
}