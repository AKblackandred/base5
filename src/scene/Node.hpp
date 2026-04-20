#ifndef NODE_HPP_
#define NODE_HPP_

#include <memory>

namespace Maths
{
	class Vector3;
    class Quaternion;
}

class Entity;
class Light;

class Node 
{
    private:
        std::shared_ptr<Maths::Vector3> position;
        std::shared_ptr<Entity> entity;
        std::shared_ptr<Maths::Vector3> scale;
		std::shared_ptr<Maths::Quaternion> rotation;
        std::shared_ptr<Light> light;
        std::shared_ptr<Node> child;
    public:
        Node();
        ~Node();

        void setPosition(std::shared_ptr<Maths::Vector3> position);
        std::shared_ptr<Maths::Vector3> getPosition();

        void setEntity(std::shared_ptr<Entity> entity);
        std::shared_ptr<Entity> getEntity();

        void setScale(std::shared_ptr<Maths::Vector3> scale);
        std::shared_ptr<Maths::Vector3> getScale();

        void setRotation(std::shared_ptr<Maths::Quaternion> rotation);
        std::shared_ptr<Maths::Quaternion> getRotation();

		void setLight(std::shared_ptr<Light> light);
		std::shared_ptr<Light> getLight();

        void setChildNode(std::shared_ptr<Node> node);
        std::shared_ptr<Node> getChildNode();
};

#endif