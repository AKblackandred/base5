#include "Node.hpp"
#include "Vector3.h"

Node::Node()
{
    position = nullptr;
    entity = nullptr;
	scale = nullptr;
	rotation = nullptr;
	light = nullptr;
    child = nullptr;
}

Node::~Node()
{
    position.reset();
    entity.reset();
	scale.reset();
	rotation.reset();
	light.reset();
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

void Node::setScale(std::shared_ptr<Maths::Vector3> scale)
{
    this->scale = scale;
}

std::shared_ptr<Maths::Vector3> Node::getScale()
{
    return scale;
}

void Node::setRotation(std::shared_ptr<Maths::Quaternion> rotation)
{
    this->rotation = rotation;
}

std::shared_ptr<Maths::Quaternion> Node::getRotation()
{
    return rotation;
}

void Node::setLight(std::shared_ptr<Light> light)
{
    this->light = light;
}

std::shared_ptr<Light> Node::getLight()
{
    return light;
}

void Node::setChildNode(std::shared_ptr<Node> node)
{
    child = node;
}

std::shared_ptr<Node> Node::getChildNode()
{
    return child;
}