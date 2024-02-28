#include <MKCDE/Data/NodeTree.hpp>

MK::NodeTree::NodeTree() = default;

MK::NodeTree::NodeTree(std::shared_ptr<Node>& parent)
{
	this->parent = parent;
}

void MK::NodeTree::update()
{
	parent->refresh();
}

std::shared_ptr<MK::Node> MK::NodeTree::get_parent()
{
	return parent;
}
