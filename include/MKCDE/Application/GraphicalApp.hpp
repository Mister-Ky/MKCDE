#pragma once

#ifndef MK_GRAPHICAL_APP_HPP
#define MK_GRAPHICAL_APP_HPP

#include <memory>
#include <MKCDE/Data/NodeTree.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System/NonCopyable.hpp>
#include <Windows.h>

namespace mk
{
enum AppMode { GRAPHICS_MODE = 1, CONSOLE_MODE = 2 };

class GraphicalApp : public sf::NonCopyable
{
public:
	GraphicalApp();
	GraphicalApp(int argc, char* argv[]);

	virtual ~GraphicalApp();
	
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

	std::unique_ptr<sf::RenderWindow> window;
private:
	int m_frameRate;
};
}

#endif
