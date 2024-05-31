#pragma once

#ifndef MK_NODETREE_HPP
#define MK_NODETREE_HPP

#include <memory>
#include <MKCDE/Graphics/App/Data/Node.hpp>
#include <MKCDE/Graphics/Export.hpp>

namespace mk
{
class MKCDE_GRAPHICS_API NodeTree
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
