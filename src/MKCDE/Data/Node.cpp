#include <MKCDE/Data/Node.hpp>

MK::Node::Node() = default;

MK::Node::Node(NodeID id) : id(id) {}

void MK::Node::add_child(std::shared_ptr<Node> child)
{
    m_children[m_children.size() + 1] = child;
}

void MK::Node::add_child(NodeLevel level, std::shared_ptr<Node> child)
{
    if (level == 0 || m_children.size() + 1 < level) 
    {
        return;
    }
    auto it = m_children.find(level);
    if (it != m_children.end())
    {
        NodeLevel tempLevel = m_children.size();
        while (tempLevel != level - 1)
        {
            m_children[tempLevel + 1] = m_children[tempLevel];
            tempLevel--;
        }
    }
    m_children[level] = child;
}

void MK::Node::remove_child(NodeLevel level)
{
    m_children.erase(level);
}

void MK::Node::update_children() 
{
    for (auto& child : m_children) 
    {
        child.second->refresh();
    }
}

void MK::Node::update() {}

void MK::Node::refresh()
{
    update();
    update_children();
}
