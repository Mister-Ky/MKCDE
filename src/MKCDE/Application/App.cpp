#include <MKCDE/Application/App.hpp>

mk::App::App() { init(); }
mk::App::App(int argc, char* argv[]) { init(argc, argv); }
mk::App::~App() {}

byte mk::App::run() {}
void mk::App::init() {}
void mk::App::init(int argc, char* argv[]) {}
void mk::App::shutdown() {}
