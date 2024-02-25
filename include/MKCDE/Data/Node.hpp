#pragma once

#ifndef MK_NODE_HPP
#define MK_NODE_HPP

#include <iostream>
#include <memory>
#include <vector>
#include <unordered_map>

namespace MK
{
typedef unsigned int ID_Node;

class Node {
public:
    ID_Node id;
    std::unordered_map<ID_Node, std::shared_ptr<Node>> children;

    Node(ID_Node id);

    void addChild(std::shared_ptr<Node> child);

    void removeChild(ID_Node id);
};
}

#endif
