#pragma once

#ifndef MK_GRAPHICALAPP_HPP
#define MK_GRAPHICALAPP_HPP

// The MK_APP_CONTINUE_SUCCESSFULLY constant indicates the successful continuation of the application
#define MK_APP_CONTINUE_SUCCESSFULLY 61

#include <MKCDE/App/Export.hpp>
#include <MKCDE/Graphics.hpp>
#include <Windows.h>

namespace mk
{
class MKCDE_APP_API GraphicalApp : public sf::NonCopyable
{
public:
	//enum AppMode { GRAPHICS_MODE = 1, CONSOLE_MODE = 2 };

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

	//AppMode app_mode;

	bool initializationSuccessful;

	sf::RenderWindow window;
private:
	int m_frameRate;
};
}

#endif
