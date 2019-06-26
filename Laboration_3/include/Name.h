
#ifndef NAME_H
#define NAME_H

#include <iostream>
#include <string>

class Name 
{
    private:
        std::string firstName;
        std::string lastName;
    public:
        Name (std::string FirstName = "None", std::string LastName = "None");
        //~Name();

        //set
        void setFirstName (std::string FirstName);
        void setLastName (std::string LastName);
        //get
        std::string getFirstName () const;
        std::string getLastName () const;

        //operator overloading
        bool operator==(const Name &rhs) const;
        bool operator<(const Name &rhs) const;
};
//overloading stream operators, load to and from stream.
std::ostream &operator<<(std::ostream &os, const Name &name);
std::istream &operator>>(std::istream &is, Name &name);

#endif //NAME_H