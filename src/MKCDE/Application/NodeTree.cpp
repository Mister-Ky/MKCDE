#include <MKCDE/Data/NodeTree.hpp>

mk::NodeTree::NodeTree() = default;

mk::NodeTree::NodeTree(std::shared_ptr<Node>& parent)
{
	m_parent = parent;
}

void mk::NodeTree::update()
{
	m_parent->refresh();
}

std::shared_ptr<mk::Node> mk::NodeTree::get_parent()
{
	return m_parent;
}
