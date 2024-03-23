#pragma once

#ifndef MK_CONSOLE_APP_HPP
#define MK_CONSOLE_APP_HPP

#include <MKCDE/Data/NodeTree.hpp>
#include <SFML/System/NonCopyable.hpp>
#include <Windows.h>

namespace mk
{
enum AppMode { GRAPHICS_MODE = 1, CONSOLE_MODE = 2 };

class ConsoleApp : public sf::NonCopyable
{
public:
	ConsoleApp();
	ConsoleApp(int argc, char* argv[]);

	virtual ~ConsoleApp();
	
	byte run();
protected:
	virtual void init();
	virtual void init(int argc, char* argv[]);
	virtual byte update();
	virtual void shutdown();

	void set_frameRate(const int new_frameRate);
	int get_frameRate() const;

	NodeTree tree;
	AppMode app_mode;
private:
	int m_frameRate;
};
}

#endif
