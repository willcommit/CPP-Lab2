#include "Name.h"

Name::Name (std::string FirstName, std::string LastName)
    :firstName(FirstName), lastName(LastName) { std::cout << "three args" << std::endl; }

//get, set
void Name::setFirstName (std::string FirstName) { firstName = FirstName; }
void Name::setLastName (std::string LastName) { lastName = LastName; }
std::string Name::getFirstName () const { return firstName; }
std::string Name::getLastName () const  { return lastName; }


