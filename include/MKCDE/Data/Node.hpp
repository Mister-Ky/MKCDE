#pragma once

#ifndef MK_NODE_HPP
#define MK_NODE_HPP

#include <map>
#include <memory>

namespace mk
{
typedef unsigned short NodeID;
typedef unsigned short NodeLevel;

class NodeTree;

class Node
{
public:
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
