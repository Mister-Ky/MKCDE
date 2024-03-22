#pragma once

#ifndef MK_APP_HPP
#define MK_APP_HPP

#include <MKCDE/Data/NodeTree.hpp>
#include <SFML/System/NonCopyable.hpp>
#include <Windows.h>

namespace mk
{
class App : public sf::NonCopyable
{
public:
	virtual App() = 0;
	virtual ~App() = 0;

	virtual byte init() = 0;
	virtual byte run() = 0;
	virtual void shutdown() = 0;
protected:
	virtual NodeTree tree = 0;
};
}

#endif
