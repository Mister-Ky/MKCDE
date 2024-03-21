#include <MKCDE/Data/NodeTree.hpp>

MK::NodeTree::NodeTree() = default;

MK::NodeTree::NodeTree(std::shared_ptr<Node>& parent)
{
	m_parent = parent;
}

void MK::NodeTree::update()
{
	m_parent->refresh();
}

std::shared_ptr<MK::Node> MK::NodeTree::get_parent()
{
	return m_parent;
}
