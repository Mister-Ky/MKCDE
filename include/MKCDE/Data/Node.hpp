#pragma once

#ifndef MK_NODE_HPP
#define MK_NODE_HPP

#include <iostream>
#include <memory>
#include <vector>
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

    void addChild(std::shared_ptr<Node> child);

    void addChild(NodeLevel level, std::shared_ptr<Node> child);

    void removeChild(NodeLevel level);
};
}

#endif
