#pragma once

#ifndef MK_NODE_HPP
#define MK_NODE_HPP

#include <memory>
#include <unordered_map>

namespace MK
{
typedef unsigned short NodeID;
typedef unsigned short NodeLevel;

class Node {
public:
    NodeID id;
    std::unordered_map<NodeLevel, std::shared_ptr<Node>> children;

    Node(NodeID id);

    void add_child(std::shared_ptr<Node> child);

    void add_child(NodeLevel level, std::shared_ptr<Node> child);

    void remove_child(NodeLevel level);
};
}

#endif
