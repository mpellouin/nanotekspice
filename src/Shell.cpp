/*
** EPITECH PROJECT, 2022
** nts
** File description:
** Shell
*/

#include "Shell.hpp"
#include <iostream>
#include <sstream>

void test_func() {
    std::cout << "pouet" << std::endl;
}

Shell::Shell()
{
    //! Init commands here
    // Shell::Commands[std::string("test")] = &test_func;
    // if (cmd == "display")
    // if (cmd == "exit")
    // if (cmd == "simulate")
    // if (cmd == "loop")
    // if (cmd == "dump");
}

Shell::~Shell()
{
}

void Shell::getInputFromUser()
{
    getline(std::cin, this->_userInput);
}

bool Shell::isEofReached() {
    return std::cin.eof();
}

void Shell::executeCommand()
{
    std::stringstream stream(this->_userInput);
    std::string cmd;
    stream >> cmd;
    if (isEofReached())
        throw std::runtime_error("EOF");
    if (cmd.find('=') != std::string::npos && cmd.find('=') != 0) {
        std::string var = cmd.substr(0, cmd.find('='));
        //! Check if var exists
        int state;
        if ((std::stringstream(cmd.substr(cmd.find('=') + 1)) >> state).fail()) {
            std::string undefinedChecker;
            if (!(std::stringstream(cmd.substr(cmd.find('=') + 1)) >> undefinedChecker).fail() && undefinedChecker == "U")
                return ; //! Set chipset value to Undefined
            throw std::invalid_argument("Assignment value is not 0 1 or U.");
        }
        if (state < 0 || state > 1) throw std::invalid_argument("Assignment value is not 0 1 or U.");
        //! Set chipset to state
        return;
    }
    if (Shell::Commands.count(cmd) == 0)
        throw std::invalid_argument("Unknown command.");
    Shell::Commands[cmd]();
}