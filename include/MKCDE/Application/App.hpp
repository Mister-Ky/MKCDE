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
	App();
	App(int argc, char* argv[]);

	virtual ~App();
	
	virtual byte run() = 0;
protected:
	virtual byte init() = 0;
	virtual byte init(int argc, char* argv[]) = 0;
	virtual void shutdown() = 0;

	NodeTree tree;
};
}

#endif
