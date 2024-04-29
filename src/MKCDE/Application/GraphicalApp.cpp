#include <MKCDE/Application/GraphicalApp.hpp>

mk::GraphicalApp::GraphicalApp()
{
	//app_mode = GRAPHICS_MODE;
	//init();
}
mk::GraphicalApp::GraphicalApp(int argc, char* argv[])
{
	//app_mode = GRAPHICS_MODE;
	//init(argc, argv);
}

mk::GraphicalApp::~GraphicalApp() {}

byte mk::GraphicalApp::run()
{ 
	window->setFramerateLimit(get_frameRate());
	while (window->isOpen())
	{
		byte update_return = update();
		if (update_return != MK_APP_CONTINUE_SUCCESSFULLY)
		{
			shutdown();
			return update_return;
		}
	}
	return EXIT_FAILURE;
}
void mk::GraphicalApp::init() {}
void mk::GraphicalApp::init(int argc, char* argv[]) {}
byte mk::GraphicalApp::update() { return EXIT_SUCCESS; }
void mk::GraphicalApp::shutdown() {}

void mk::GraphicalApp::set_frameRate(const int new_frameRate)
{
	m_frameRate = new_frameRate;
	window->setFramerateLimit(m_frameRate);
}
int mk::GraphicalApp::get_frameRate() const { return m_frameRate; }
mk::NodeTree* mk::GraphicalApp::get_tree() { return &tree; }
