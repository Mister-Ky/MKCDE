#include <MKCDE/Application/App.hpp>

#include <chrono>
#include <thread>

mk::App::App()
{
#ifdef MK_APP_GRAPHICS_MODE
	app_mode = GRAPHICS_MODE;
#elif MK_APP_CONSOLE_MODE
	app_mode = CONSOLE_MODE;
#else
#error "Please define either MK_APP_GRAPHICS_MODE or MK_APP_CONSOLE_MODE"
#endif
	init();
}
mk::App::App(int argc, char* argv[])
{
#ifdef MK_APP_GRAPHICS_MODE
	app_mode = GRAPHICS_MODE;
#elif MK_APP_CONSOLE_MODE
	app_mode = CONSOLE_MODE;
#else
#error "Please define either MK_APP_GRAPHICS_MODE or MK_APP_CONSOLE_MODE"
#endif
	init(argc, argv);
}

mk::App::~App() {}

byte mk::App::run() const
{ 
#ifdef MK_APP_GRAPHICS_MODE
	window.setFramerateLimit(get_frameRate());
	while (window.isOpen())
	{
		if (update() != EXIT_SUCCESS)
		{
			return EXIT_FAILURE;
		}
	}
#elif MK_APP_CONSOLE_MODE
	while (true)
	{
		auto start = std::chrono::high_resolution_clock::now();

		if (update() != EXIT_SUCCESS)
		{
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
#else
#error "Please define either MK_APP_GRAPHICS_MODE or MK_APP_CONSOLE_MODE"
#endif
}
void mk::App::init() {}
void mk::App::init(int argc, char* argv[]) {}
byte mk::App::update() const { return EXIT_SUCCESS; }
void mk::App::shutdown() {}

void mk::App::set_frameRate(const int new_frameRate) 
{
	m_frameRate = new_frameRate;
#ifdef MK_APP_GRAPHICS_MODE
	window.setFramerateLimit(m_frameRate);
#elif MK_APP_CONSOLE_MODE
	
#else
#error "Please define either MK_APP_GRAPHICS_MODE or MK_APP_CONSOLE_MODE"
#endif
}
int mk::App::get_frameRate() const { return m_frameRate; }
