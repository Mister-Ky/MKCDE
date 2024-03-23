#include <MKCDE/Data/Node.hpp>

mk::Node::Node() = default;

mk::Node::Node(NodeID id) : m_id(id) {}

void mk::Node::add_child(std::shared_ptr<Node> child)
{
    m_children[m_children.size() + 1] = child;
}

void mk::Node::add_child(NodeLevel level, std::shared_ptr<Node> child)
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

void mk::Node::remove_child(NodeLevel level)
{
    m_children.erase(level);
}

mk::NodeID mk::Node::get_id()
{
    return m_id;
}

void mk::Node::update() {}

void mk::Node::update_children()
{
    for (auto& child : m_children) 
    {
        child.second->refresh();
    }
}

void mk::Node::refresh()
{
    update();
    update_children();
}
