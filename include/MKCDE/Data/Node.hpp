#pragma once

#ifndef MK_NODE_HPP
#define MK_NODE_HPP

#include <map>
#include <memory>

namespace MK
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
protected:
    virtual void update();
private:
    NodeID id;
    std::map<NodeLevel, std::shared_ptr<Node>> children;

    friend class NodeTree;

    void refresh();
};
}

#endif
