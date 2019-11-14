#include "Address.h"

Address::Address (std::string Street, std::string Zip, std::string City)
    :street{Street}, zip{Zip}, city{City} {
}

//get, set
void Address::setStreet (std::string Street) { street = Street; }
void Address::setZip (std::string Zip) { zip = Zip; }
void Address::setCity (std::string City) { city = City; }
std::string Address::getStreet () const { return street; }
std::string Address::getZip () const { return zip; }
std::string Address::getCity () const { return city; }

//operator overloading
bool Address::operator==(const Address &rhs) const{
    return street == rhs.street && zip == rhs.zip && city == rhs.city;
}

bool Address::operator<(const Address &rhs) const{
    if (city == rhs.city)
        return street < rhs.street;
    return city < rhs.city;
}

//-----------------------DIVIDER NON CLASS MEMBERS-----------------------

constexpr char DELIM ='_';

std::ostream &operator<<(std::ostream &os, const Address &address)
{
    os << address.getCity() << DELIM;
    os << address.getZip() << DELIM;
    os << address.getStreet()<< DELIM;
    return os;
}

std::istream &operator>>(std::istream &is, Address &address)
{
    std::string tempString;

    std::getline(is,tempString,DELIM);
    address.setStreet(tempString);
    std::getline(is,tempString,DELIM);
    address.setZip(tempString);
    std::getline(is,tempString,DELIM);
    address.setCity(tempString);

    return is;
}
