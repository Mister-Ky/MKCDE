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
	
	virtual byte run();
protected:
	virtual void init();
	virtual void init(int argc, char* argv[]);
	virtual void shutdown();

	NodeTree tree;
};
}

#endif
