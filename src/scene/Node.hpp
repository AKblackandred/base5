#ifndef NODE_HPP_
#define NODE_HPP_

#include <memory>

namespace Maths {
	class Vector3;
}

class Entity;

class Node 
{
    private:
        std::shared_ptr<Maths::Vector3> position;
        std::shared_ptr<Entity> entity;
        std::shared_ptr<Node> child;
    public:
        Node();
        ~Node();

        void setPosition(std::shared_ptr<Maths::Vector3> position);
        std::shared_ptr<Maths::Vector3> getPosition();

        void setEntity(std::shared_ptr<Entity> entity);
        std::shared_ptr<Entity> getEntity();

        void setChildNode(std::shared_ptr<Node> node);
        std::shared_ptr<Node> getChildNode();
};

#endif