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

    Node(NodeID id);

    void add_child(std::shared_ptr<Node> child);

    void add_child(NodeLevel level, std::shared_ptr<Node> child);

    void remove_child(NodeLevel level);

    void update_children();

    NodeID id;
protected:
    virtual void update();
private:
    std::map<NodeLevel, std::shared_ptr<Node>> m_children;

    friend class NodeTree;

    void refresh();
};
}

#endif
