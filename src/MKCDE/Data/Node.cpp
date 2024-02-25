#include <MKCDE/Data/Node.hpp>

MK::Node::Node(NodeID id) : id(id) {}

void MK::Node::add_child(std::shared_ptr<Node> child)
{
    if (children.empty()) {
        children[1] = child;
    }
    else {
        children[children.size() + 1] = child;
    }
}

void MK::Node::add_child(NodeLevel level, std::shared_ptr<Node> child)
{
    if (level == 0 || children.size() + 1 < level) {
        return;
    }

    std::unordered_map<NodeLevel, std::shared_ptr<Node>> newChildren;

    for (const auto& [currentLevel, currentNode] : children) {
        if (currentLevel >= level) {
            newChildren[currentLevel + 1] = currentNode;
        }
        newChildren[currentLevel] = currentNode;
    }

    newChildren[level] = child;

    children = std::move(newChildren);
}

void MK::Node::remove_child(NodeLevel level)
{
    children.erase(level);
}
