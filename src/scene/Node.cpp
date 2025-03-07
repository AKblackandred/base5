#include "Node.hpp"
#include "Vector3.h"

Node::Node()
{
    position = nullptr;
    entity = nullptr;
    child = nullptr;
}

Node::~Node()
{
    position.reset();
    entity.reset();
    child.reset();
}

void Node::setPosition(std::shared_ptr<Maths::Vector3> position)
{
    this->position = position;
}

std::shared_ptr<Maths::Vector3> Node::getPosition()
{
    return position;
}

void Node::setEntity(std::shared_ptr<Entity> entity)
{
    this->entity = entity;
}

std::shared_ptr<Entity> Node::getEntity()
{
   return entity;
}

void Node::setChildNode(std::shared_ptr<Node> node)
{
    child = node;
}

std::shared_ptr<Node> Node::getChildNode()
{
    return child;
}