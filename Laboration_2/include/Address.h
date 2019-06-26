#ifndef ADDRESS_H
#define ADDRESS_H

#include <iostream>
#include <string>


class Address
{
    private:
        std::string street;
        std::string zip;
        std::string city;
    public:
        Address (std::string Street = "None",std::string Zip = "None", std::string City = "None");
        //~Address();


        //get, set
        void setStreet (std::string Street);
        void setZip (std::string Zip);
        void setCity (std::string City);
        std::string getStreet () const;
        std::string getZip () const;
        std::string getCity () const;
};


#endif //ADDRESS_H
