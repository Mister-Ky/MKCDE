#pragma once

#ifndef MK_APP_HPP
#define MK_APP_HPP

#include <MKCDE/Data/NodeTree.hpp>
#include <SFML/System/NonCopyable.hpp>
#include <Windows.h>

namespace mk
{
enum AppMode { GRAPHICS_MODE = 1, CONSOLE_MODE = 2 };

class App : public sf::NonCopyable
{
public:
	App();
	App(int argc, char* argv[]);

	virtual ~App();
	
	byte run() const;
protected:
	virtual void init();
	virtual void init(int argc, char* argv[]);
	virtual byte update() const;
	virtual void shutdown();

	void set_frameRate(const int new_frameRate);
	int get_frameRate() const;

	NodeTree tree;
	AppMode app_mode;

#ifdef MK_APP_GRAPHICS_MODE
	sf::RenderWindow window;
#elif MK_APP_CONSOLE_MODE
	
#else
#error "Please define either MK_APP_GRAPHICS_MODE or MK_APP_CONSOLE_MODE"
#endif
private:
	int m_frameRate;
};
}

#endif
