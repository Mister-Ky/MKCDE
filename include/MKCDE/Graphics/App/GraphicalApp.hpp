#pragma once

#ifndef MK_GRAPHICALAPP_HPP
#define MK_GRAPHICALAPP_HPP

// The MK_APP_CONTINUE_SUCCESSFULLY constant indicates the successful continuation of the application
#define MK_APP_CONTINUE_SUCCESSFULLY 61

#include <MKCDE/Graphics/App/Data/NodeTree.hpp>
#include <MKCDE/Graphics/Export.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System/NonCopyable.hpp>
#include <Windows.h>

namespace mk
{
class MKCDE_GRAPHICS_API GraphicalApp : public sf::NonCopyable
{
public:
	GraphicalApp();
	GraphicalApp(int argc, char* argv[]);

	virtual ~GraphicalApp();
	
	byte run();

	//enum AppMode { GRAPHICS_MODE = 1, CONSOLE_MODE = 2 };
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

	sf::RenderWindow window;
private:
	int m_frameRate;
};
}

#endif
