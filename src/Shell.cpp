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


void exitProgram(Circuit *test)
{
    test->isExiting = true;
}

void displayCircuit(Circuit *test)
{
    test->dump();
}
void simulateCircuit(Circuit *test)
{
    test->simulate(1);
}

void roundCircuit(Circuit *test)
{
    test->simulate(1);
    test->dump();
}

Shell::Shell()
{
    //! Init commands here
    // Shell::Commands[std::string("test")] = &test_func;
    Shell::Commands["display"] = &displayCircuit;
    Shell::Commands["exit"] = &exitProgram;
    Shell::Commands["simulate"] = &simulateCircuit;
    Shell::Commands["loop"] = &test_func;
    Shell::Commands["dump"] = &test_func;
    Shell::Commands["round"] = &roundCircuit;
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

void Shell::run(Circuit &circuit)
{
    while (!this->isEofReached() && !circuit.isExiting) {
        std::cout << "> ";
        this->getInputFromUser();
        this->executeCommand(&circuit);
    }
}

const char *Shell::Error::what() const noexcept
{
    return this->message->c_str();
}
