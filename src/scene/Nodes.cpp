#include "Nodes.hpp"
#include "Node.hpp"
#include "SceneExceptions.hpp"

#include "Vector3.h"

Nodes::Nodes()
{
    // preallocate to this size 
    // any more and we'll grow dynamically
    list.reserve(10);
}

Nodes::~Nodes()
{
    list.clear();
}

void Nodes::addNode(std::shared_ptr<Node> newNode)
{
    list.push_back(newNode);
}

int Nodes::getNodeCount()
{
    return list.size();
}

// Throws an exception if the index is out of range. 
std::shared_ptr<Node> Nodes::getNode(int i)
{
    try
    {
        return list.at(i);
    }
    catch(std::out_of_range &e)
    {
        throw NodeIndexOutOfRange();
    }
}

void Nodes::setPosition(std::shared_ptr<Maths::Vector3> position)
{
    this->position = position;
}

std::shared_ptr<Maths::Vector3> Nodes::getPosition()
{
    return position;
}

