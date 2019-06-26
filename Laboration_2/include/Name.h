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

        //get, set
        void setFirstName (std::string FirstName);
        void setLastName (std::string LastName);
        std::string getFirstName () const;
        std::string getLastName () const;
};

#endif //NAME_H