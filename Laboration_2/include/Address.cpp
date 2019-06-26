#include "Address.h"

Address::Address (std::string Street, std::string Zip, std::string City)
    :street{Street}, zip{Zip}, city{City} {
    std::cout << "three args" << std::endl;
}

//get, set
void Address::setStreet (std::string Street) { street = Street; }
void Address::setZip (std::string Zip) { zip = Zip; }
void Address::setCity (std::string City) { city = City; }
std::string Address::getStreet () const { return street; }
std::string Address::getZip () const { return zip; }
std::string Address::getCity () const { return city; }