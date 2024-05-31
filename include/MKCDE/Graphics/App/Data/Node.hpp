#pragma once

#ifndef MK_NODE_HPP
#define MK_NODE_HPP

#include <map>
#include <memory>
#include <MKCDE/Graphics/Export.hpp>

namespace mk
{
class NodeTree;

class MKCDE_GRAPHICS_API Node
{
public:
    typedef unsigned short NodeID;
    typedef unsigned short NodeLevel;

    Node();

    Node(const NodeID id);

    void add_child(const std::shared_ptr<Node> child);

    void add_child(const NodeLevel level, const std::shared_ptr<Node> child);

    void remove_child(const NodeLevel level);

    NodeID get_id() const;
protected:
    virtual void update();
private:
    friend class NodeTree;

    NodeID m_id;
    std::map<NodeLevel, std::shared_ptr<Node>> m_children;

    void update_children();
    void refresh();
};
}

#endif
