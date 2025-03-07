#ifndef A_H
#define A_H

#include <string>

class A {
private:
    std::string name;

public:
    // Constructor
    A(const std::string& name);

    // Getter for name
    std::string getName() const;

    // Setter for name
    void setName(const std::string& name);
};

#endif // A_H