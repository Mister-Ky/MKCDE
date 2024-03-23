#include <MKCDE/Application/ConsoleApp.hpp>

#include <chrono>
#include <thread>

mk::ConsoleApp::ConsoleApp()
{
	app_mode = CONSOLE_MODE;
	//init();
}
mk::ConsoleApp::ConsoleApp(int argc, char* argv[])
{
	app_mode = CONSOLE_MODE;
	//init(argc, argv);
}

mk::ConsoleApp::~ConsoleApp() {}

byte mk::ConsoleApp::run()
{
	while (true)
	{
		auto start = std::chrono::high_resolution_clock::now();

		if (update() != EXIT_SUCCESS)
		{
			shutdown();
			return EXIT_FAILURE;
		}

		auto end = std::chrono::high_resolution_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
		auto frameRate = get_frameRate();

		if (elapsed.count() < 1000 / frameRate)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(1000 / frameRate - elapsed.count()));
		}
	}
}
void mk::ConsoleApp::init() {}
void mk::ConsoleApp::init(int argc, char* argv[]) {}
byte mk::ConsoleApp::update() const { return EXIT_SUCCESS; }
void mk::ConsoleApp::shutdown() {}

void mk::ConsoleApp::set_frameRate(const int new_frameRate)
{
	m_frameRate = new_frameRate;
}
int mk::ConsoleApp::get_frameRate() const { return m_frameRate; }
