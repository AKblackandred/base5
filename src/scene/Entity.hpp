#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include <string>

class Entity {
    private:
        std::string meshfile;

    public:
        Entity();
        ~Entity();

        void setMeshfile(std::string& mesh);
        std::string& getMeshfile();
};

#endif