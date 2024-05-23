#include <MKCDE/Graphics/App/Data/Node.hpp>

mk::Node::Node() = default;

mk::Node::Node(const NodeID id) : m_id(id) {}

void mk::Node::add_child(const std::shared_ptr<Node> child)
{
    m_children[m_children.size() + 1] = child;
}

void mk::Node::add_child(const NodeLevel level, const std::shared_ptr<Node> child)
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

void mk::Node::remove_child(const NodeLevel level)
{
    m_children.erase(level);
}

mk::NodeID mk::Node::get_id() const
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
