#include <MKCDE/Utilities/ArgsProcessor.hpp>

MK::ArgsProcessor::ArgsProcessor() = default;

void MK::ArgsProcessor::registerCommand(const std::string& command, std::function<void(const std::vector<std::string>&)> action, int minArgs, int maxArgs) 
{
    commands[commandSymbol + command] = std::make_tuple(action, minArgs, maxArgs);
}

void MK::ArgsProcessor::registerCommandSymbol(char symbol) 
{
    commandSymbol = symbol;
}

void MK::ArgsProcessor::executeCommand(const std::string& command, const std::vector<std::string>& args) 
{
    if (commands.find(command) != commands.end()) {
        auto [action, minArgs, maxArgs] = commands[command];
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

void MK::ArgsProcessor::parse(int argc, char* argv[]) 
{
    for (int i = 1; i < argc; ++i) {
        std::string command = argv[i];
        std::vector<std::string> args;
        while (i + 1 < argc && argv[i + 1][0] != commandSymbol) {
            args.push_back(argv[++i]);
        }
        executeCommand(command, args);
    }
}