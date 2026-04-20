#ifndef LIGHT_H_
#define LIGHT_H_

#include <string>
#include <memory>

namespace Maths
{
    class Vector3;
    class Quaternion;
}

class Light
{
private:
    std::string type;
    std::shared_ptr<Maths::Vector3> colourDiffuse;
    std::shared_ptr<Maths::Vector3> colourSpecular;

public:
    Light();
    ~Light();

    void setType(std::string& type);
    std::string& getType();

    void setColourDiffuse(std::shared_ptr<Maths::Vector3> colourDiffuse);
    std::shared_ptr<Maths::Vector3> getColourDiffuse();

    void setColourSpecular(std::shared_ptr<Maths::Vector3> colourSpecular);
    std::shared_ptr<Maths::Vector3> getColourSpecular();
};

#endif
