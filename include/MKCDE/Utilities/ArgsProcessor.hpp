#pragma once

#ifndef MK_ARGS_PROCESSOR_HPP
#define MK_ARGS_PROCESSOR_HPP

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <functional>
#include <tuple>

namespace MK
{
class ArgsProcessor
{
private:
    std::map<std::string, std::tuple<std::function<void(const std::vector<std::string>&)>, int, int>> commands;
    char commandSymbol;
public:
    ArgsProcessor();

    void registerCommand(const std::string& command, std::function<void(const std::vector<std::string>&)> action, int minArgs, int maxArgs);

    void registerCommandSymbol(char symbol);

    void executeCommand(const std::string& command, const std::vector<std::string>& args);

    void parse(int argc, char* argv[]);
};
}

#endif