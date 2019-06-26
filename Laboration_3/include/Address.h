
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

        //set
        void setStreet (std::string Street);
        void setZip (std::string Zip);
        void setCity (std::string City);
        //get
        std::string getStreet () const;
        std::string getZip () const;
        std::string getCity () const;

        //operator overloading
        bool operator==(const Address &rhs) const;
        bool operator<(const Address &rhs) const;
};
//overloading stream operators, load to and from stream.
std::ostream &operator<<(std::ostream &os, const Address &address);
std::istream &operator>>(std::istream &is, Address &address);

#endif //ADDRESS_H
