#include <MKCDE/Utils/ArgsProcessor.hpp>

#include <iostream>

mk::ArgsProcessor::ArgsProcessor() = default;

void mk::ArgsProcessor::registerCommand(const std::string& command, std::function<void(const Args&)> action, int minArgs, int maxArgs)
{
    m_commands[m_commandSymbol + command] = std::make_tuple(action, minArgs, maxArgs);
}

void mk::ArgsProcessor::registerCommandSymbol(char symbol)
{
    m_commandSymbol = symbol;
}

void mk::ArgsProcessor::executeCommand(const std::string& command, const Args& args)
{
    if (m_commands.find(command) != m_commands.end()) {
        auto [action, minArgs, maxArgs] = m_commands[command];
        if (args.size() >= minArgs && args.size() <= maxArgs) {
            action(args);
        }
        else {
            std::cout << "error count arg for command: " << command << std::endl;
        }
    }
    else {
        std::cout << "command not found: " << command << std::endl;
    }
}

void mk::ArgsProcessor::parse(int argc, char* argv[])
{
    for (int i = 1; i < argc; ++i) {
        std::string command = argv[i];
        Args args;
        while (i + 1 < argc && argv[i + 1][0] != m_commandSymbol) {
            args.push_back(argv[++i]);
        }
        executeCommand(command, args);
    }
}
