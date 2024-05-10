#pragma once

#ifndef MK_GRAPHICAL_APP_HPP
#define MK_GRAPHICAL_APP_HPP

// The MK_APP_CONTINUE_SUCCESSFULLY constant indicates the successful continuation of the application
#define MK_APP_CONTINUE_SUCCESSFULLY 61

#include <memory>
#include <MKCDE/Application/Data/NodeTree.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System/NonCopyable.hpp>
#include <Windows.h>

namespace mk
{
//enum AppMode { GRAPHICS_MODE = 1, CONSOLE_MODE = 2 };

class GraphicalApp : public sf::NonCopyable
{
public:
	GraphicalApp();
	GraphicalApp(int argc, char* argv[]);

	virtual ~GraphicalApp();
	
	byte run();
protected:
	virtual void init();
	virtual void init(int argc, char* argv[]);
	virtual byte update();
	virtual void shutdown();

	void set_frameRate(const int new_frameRate);
	int get_frameRate() const;

	NodeTree tree;
	NodeTree* get_tree();
	//AppMode app_mode;

	bool initializationSuccessful;

	std::unique_ptr<sf::RenderWindow> window;
private:
	int m_frameRate;
};
}

#endif
