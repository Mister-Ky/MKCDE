#include <MKCDE/Data/Node.hpp>

MK::Node::Node(NodeID id) : id(id) {}

void MK::Node::add_child(std::shared_ptr<Node> child)
{
    children[children.size() + 1] = child;
}

void MK::Node::add_child(NodeLevel level, std::shared_ptr<Node> child)
{
    if (level == 0 || children.size() + 1 < level) 
    {
        return;
    }
    auto it = children.find(level);
    if (it != children.end())
    {
        NodeLevel tempLevel = children.size();
        while (tempLevel != level - 1)
        {
            children[tempLevel + 1] = children[tempLevel];
            tempLevel--;
        }
    }
    children[level] = child;
}

void MK::Node::remove_child(NodeLevel level)
{
    children.erase(level);
}
