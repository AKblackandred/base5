#include "A.hpp"

// Constructor
A::A(const std::string& name) : name(name) 
{

}

// Getter for name
std::string A::getName() const 
{
    return name;
}

// Setter for name
void A::setName(const std::string& name) 
{
    this->name = name;
}