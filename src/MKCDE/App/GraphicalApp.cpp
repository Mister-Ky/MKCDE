#include <MKCDE/App/GraphicalApp.hpp>

mk::GraphicalApp::GraphicalApp()
{
	initializationSuccessful = false;
	wasShutdown = false;

	//app_mode = GRAPHICS_MODE;
	//init();
}
mk::GraphicalApp::GraphicalApp(int argc, char* argv[])
{
	initializationSuccessful = false;
	wasShutdown = false;

	//app_mode = GRAPHICS_MODE;
	//init(argc, argv);
}

mk::GraphicalApp::~GraphicalApp() { }

byte mk::GraphicalApp::run()
{ 
	if (initializationSuccessful)
	{
		window.setFramerateLimit(get_framerate());
		while (window.isOpen())
		{
			byte update_return = update();
			if (update_return != MK_APP_CONTINUE_SUCCESSFULLY)
			{
				shutdown();
				return update_return;
			}
		}
		shutdown();
		return EXIT_FAILURE;
	}
	shutdown();
	return EXIT_FAILURE;
}
void mk::GraphicalApp::init() {}
void mk::GraphicalApp::init(int argc, char* argv[]) {}
byte mk::GraphicalApp::update() { return EXIT_SUCCESS; }
void mk::GraphicalApp::shutdown() {}

void mk::GraphicalApp::set_framerate(const int new_framerate)
{
	m_framerate = new_framerate;
	window.setFramerateLimit(m_framerate);
}
int mk::GraphicalApp::get_framerate() const { return m_framerate; }
