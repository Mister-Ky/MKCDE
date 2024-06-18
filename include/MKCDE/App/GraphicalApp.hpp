#pragma once

#ifndef MK_GRAPHICALAPP_HPP
#define MK_GRAPHICALAPP_HPP

#ifndef MK_APP_CONTINUE_SUCCESSFULLY
// The MK_APP_CONTINUE_SUCCESSFULLY constant indicates the successful continuation of the application
#define MK_APP_CONTINUE_SUCCESSFULLY 61
#endif

#ifndef MK_APP_SHUTDOWN
// Use the MK_APP_SHUTDOWN macro at the beginning of your shutdown() function to improve the shutdown() function
#define MK_APP_SHUTDOWN                                                                                              \
if (wasShutdown) return;                                                                                \
wasShutdown = true;
#endif

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

	void set_framerate(const int new_framerate);
	int get_framerate() const;

	//AppMode app_mode;

	bool initializationSuccessful;

	bool wasShutdown;

	sf::RenderWindow window;
private:
	int m_framerate;
};
}

#endif
