#pragma once

#ifndef MK_NODE_TREE_HPP
#define MK_NODE_TREE_HPP

#include <memory>
#include <MKCDE/Application/Node.hpp>

namespace mk
{
class NodeTree
{
public:
	NodeTree();

	NodeTree(std::shared_ptr<Node>& parent);

	void update();

	std::shared_ptr<Node> get_parent();
private:
	std::shared_ptr<Node> m_parent;
};
}

#endif
