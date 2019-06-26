#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

#include "Name.h"
#include "Address.h"

class Person
{
    private:
        Name personName;
        Address personAddress;
        std::string idNr;
        int shoeNr;
    public:
        Person();
        Person(Name name_val, Address address_val, std::string IdNr, int ShoeNr);
        //~Person();

    //SET
    void setName (Name name_val);
    void setAddress (Address address_val);
    void setIdNr (std::string IdNr);
    void setShoeNr (int ShoeNr);

    //GET
    Name getPersonName () const { return personName; }
    Address getPersonAddress () const { return personAddress; }
    std::string getIdNr () const { return idNr; }
    int getShoeNr () const { return shoeNr; }
};

#endif //PERSON_H
