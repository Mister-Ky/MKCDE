#include <MKCDE/Data/Node.hpp>

MK::Node::Node(NodeID id) : id(id) {}

void MK::Node::addChild(NodeLevel level, std::shared_ptr<Node> child)
{
    children[level] = child;
}

void MK::Node::removeChild(NodeLevel level)
{
    children.erase(level);
}
