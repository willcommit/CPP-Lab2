#include "Person.h"

Person::Person() { shoeNr = 0; };

Person::Person(Name name_val, Address address_val, std::string IdNr, int ShoeNr)
    :personName{name_val}, personAddress{address_val}, idNr{IdNr}, shoeNr{ShoeNr} { }


//SET
void Person::setName (Name name_val) { personName = name_val; }
void Person::setAddress (Address address_val) { personAddress = address_val; }
void Person::setIdNr (std::string IdNr) { idNr = IdNr; }
void Person::setShoeNr (int ShoeNr) { shoeNr = ShoeNr; }

//Person::Person(Name name_val, Address address_val, std::string IdNr, int ShoeNr)
    //:name{name_val}, address{address_val}, idNr{IdNr},shoeNr{ShoeNr} {
//}


