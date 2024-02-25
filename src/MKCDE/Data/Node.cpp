#include <MKCDE/Data/Node.hpp>

MK::Node::Node(NodeID id) : id(id) {}

void MK::Node::add_child(std::shared_ptr<Node> child)
{
    if (children.empty()) 
    {
        children[1] = child;
    }
    else
    {
        children[children.size() + 1] = child;
    }
}

void MK::Node::add_child(NodeLevel level, std::shared_ptr<Node> child)
{
    if (level == 0 || children.size() + 1 < level) 
    {
        return;
    }
    //beta
}

void MK::Node::remove_child(NodeLevel level)
{
    children.erase(level);
}
