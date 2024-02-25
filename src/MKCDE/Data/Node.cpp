#include <MKCDE/Data/Node.hpp>

MK::Node::Node(ID_Node id) : id(id) {}

void MK::Node::addChild(std::shared_ptr<Node> child) 
{
    children[child->id] = child;
}

void MK::Node::removeChild(ID_Node id) 
{
    children.erase(id);
}
