#include "Entity.hpp"

Entity::Entity()
{
    meshfile = "not set";
}

Entity::~Entity()
{
}

void Entity::setMeshfile(std::string &mesh)
{
    meshfile = mesh;
}

std::string &Entity::getMeshfile()
{
    return meshfile;
}
