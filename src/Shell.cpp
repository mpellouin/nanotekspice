/*
** EPITECH PROJECT, 2022
** nts
** File description:
** Shell
*/

#include "Shell.hpp"
#include <iostream>
#include <sstream>

void test_func(Circuit *test) {
    std::cout << "pouet" << std::endl;
    (void)test;
}

void exitProgram(Circuit * test)
{
    (void)test;
    exit(0);
}

void displayCircuit(Circuit *test)
{
    test->dump();
}

Shell::Shell()
{
    //! Init commands here
    // Shell::Commands[std::string("test")] = &test_func;
    Shell::Commands[std::string("display")] = &displayCircuit;
    Shell::Commands[std::string("exit")] = &exitProgram;
    Shell::Commands[std::string("simulate")] = &test_func;
    Shell::Commands[std::string("loop")] = &test_func;
    Shell::Commands[std::string("dump")] = &test_func;
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

void Shell::executeCommand(Circuit *circuit)
{
    std::stringstream stream(this->_userInput);
    std::string cmd;
    stream >> cmd;
    if (isEofReached())
        throw Shell::Error("EOF");
    if (cmd.find('=') != std::string::npos && cmd.find('=') != 0) {
        std::string var = cmd.substr(0, cmd.find('='));
        //! Check if var exists
        int state;
        if ((std::stringstream(cmd.substr(cmd.find('=') + 1)) >> state).fail()) {
            std::string undefinedChecker;
            if (!(std::stringstream(cmd.substr(cmd.find('=') + 1)) >> undefinedChecker).fail() && undefinedChecker == "U") {
                Input *toChange = dynamic_cast<Input *>(circuit->operator[](var));
                toChange->setValue(nts::Tristate::UNDEFINED);
                return ;
            }
            throw Shell::Error("Assignment value is not 0 1 or U.");
        }
        if (state < 0 || state > 1) throw Shell::Error("Assignment value is not 0 1 or U.");
        Input *toChange = dynamic_cast<Input *>(circuit->operator[](var));
        toChange->setValue(state ? nts::Tristate::TRUE : nts::Tristate::FALSE);
        return;
    }
    if (Shell::Commands.count(cmd) == 0)
        throw Shell::Error("Unknown command.");
    Shell::Commands[cmd](circuit);
}

const char *Shell::Error::what() const noexcept
{
    return this->message->c_str();
}