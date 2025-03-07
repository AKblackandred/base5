#ifndef NODES_HPP_
#define NODES_HPP_

#include <vector>
#include <memory>

class Node;

namespace Maths {
	class Vector3;
}


class Nodes 
{
    private:
        std::vector<std::shared_ptr<Node>> list;

        // Optional elements
        std::shared_ptr<Maths::Vector3> position;
    public:
        Nodes();
        ~Nodes();

        void addNode(std::shared_ptr<Node> newNode);

        int getNodeCount();
        std::shared_ptr<Node> getNode(int i);

        void setPosition(std::shared_ptr<Maths::Vector3> position);
        std::shared_ptr<Maths::Vector3> getPosition();
};

#endif