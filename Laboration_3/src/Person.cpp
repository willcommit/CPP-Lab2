#include "Person.h"

Person::Person() { shoeNr = 0; };

Person::Person(Name name_val, Address address_val, std::string IdNr, int ShoeNr)
    :personName{name_val}, personAddress{address_val}, idNr{IdNr}, shoeNr{ShoeNr} {
}


//SET
void Person::setName (Name name_val) { personName = name_val; }
void Person::setAddress (Address address_val) { personAddress = address_val; }
void Person::setIdNr (std::string IdNr) { idNr = IdNr; }
void Person::setShoeNr (int ShoeNr) { shoeNr = ShoeNr; }

//operator overloading
bool Person::operator==(const Person &rhs) const{
    return personName == rhs.personName
           && personAddress == rhs.personAddress
           && idNr == rhs.idNr
           && shoeNr == rhs.shoeNr;
}

bool Person::operator<(const Person &rhs) const{
    if (personName == rhs.personName)
        return personAddress < rhs.personAddress;
    return personName < rhs.personName;
}

//-----------------------DIVIDER NON CLASS MEMBERS-----------------------

constexpr char DELIM ='_';

std::ostream &operator<<(std::ostream &os, const Person &person)
{
    os << person.getPersonName().getFirstName() << DELIM
       << person.getPersonName().getLastName() << DELIM;
    os << person.getPersonAddress().getStreet() << DELIM
       << person.getPersonAddress().getZip() << DELIM
       << person.getPersonAddress().getCity() << DELIM;
    os << person.getIdNr() << DELIM;
    os << person.getShoeNr() << DELIM;
    return os;
}

std::istream &operator>>(std::istream &is, Person &person)
{
    Name tempName;
    std::string tempString;

    std::getline(is,tempString,DELIM);
    tempName.setFirstName(tempString);
    std::getline(is,tempString,DELIM);
    tempName.setLastName(tempString);
    person.setName(tempName);

    Address tempAddress;
    std::getline(is,tempString,DELIM);
    tempAddress.setStreet(tempString);
    std::getline(is,tempString,DELIM);
    tempAddress.setZip(tempString);
    std::getline(is,tempString,DELIM);
    tempAddress.setCity(tempString);
    person.setAddress(tempAddress);

    std::getline(is,tempString,DELIM);
    person.setIdNr(tempString);

    int tempInt;
    is >> tempInt;
    is.get();
    person.setShoeNr(tempInt);

    return is;
}
