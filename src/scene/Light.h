#ifndef LIGHT_H_
#define LIGHT_H_

#include <string>

class Light
{
private:
    std::string type;

public:
    Light();
    ~Light();

    void setType(std::string& type);
    std::string& getType();
};

#endif
