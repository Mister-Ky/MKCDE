#pragma once

#ifndef MK_ARGSPROCESSOR_HPP
#define MK_ARGSPROCESSOR_HPP

#include <functional>
#include <map>
#include <MKCDE/Utils/Export.hpp>
#include <string>
#include <tuple>
#include <vector>

namespace mk
{
class MKCDE_UTILS_API ArgsProcessor
{
public:
    typedef std::vector<std::string> Args;

    ArgsProcessor();

    void registerCommand(const std::string& command, std::function<void(const Args&)> action, int minArgs, int maxArgs);

    void registerCommandSymbol(char symbol);

    void executeCommand(const std::string& command, const Args& args);

    void parse(int argc, char* argv[]);
private:
    std::map<std::string, std::tuple<std::function<void(const Args&)>, int, int>> m_commands;
    char m_commandSymbol;
};
}

#endif
