/*
** EPITECH PROJECT, 2022
** nts
** File description:
** Shell
*/

#include "Shell.hpp"
#include <iostream>
#include <sstream>
#include <csignal>


Shell::Shell()
{
    //! Init commands here
    // Shell::Commands[std::string("test")] = &test_func;
    Shell::Commands["display"] = &Shell::_displayCircuit;
    Shell::Commands["exit"] = &Shell::_exitProgram;
    Shell::Commands["simulate"] = &Shell::_simulateCircuit;
    Shell::Commands["loop"] = &Shell::_loopCircuit;
    Shell::Commands["dump"] = &Shell::_dumpCircuit;
    Shell::Commands["round"] = &Shell::_roundCircuit;
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
        if (!dynamic_cast<Input *>(circuit->operator[](var))) throw Shell::Error("Bad operation.");
        if ((std::stringstream(cmd.substr(cmd.find('=') + 1)) >> state).fail()) {
            std::string undefinedChecker;
            if (!(std::stringstream(cmd.substr(cmd.find('=') + 1)) >> undefinedChecker).fail() && undefinedChecker == "U") {
                dynamic_cast<Input *>(circuit->operator[](var))->setValue(nts::Tristate::UNDEFINED);
                return ;
            }
            throw Shell::Error("Assignment value is not 0 1 or U.");
        }
        if (state < 0 || state > 1) throw Shell::Error("Assignment value is not 0 1 or U.");
        dynamic_cast<Input *>(circuit->operator[](var))->setValue(state ? nts::Tristate::TRUE : nts::Tristate::FALSE);
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

void Shell::_exitProgram(Circuit *test)
{
    test->isExiting = true;
}

void Shell::_dumpCircuit(Circuit *test)
{
    test->dump();
}

void Shell::_displayCircuit(Circuit *test)
{
    test->display();
}

void Shell::_simulateCircuit(Circuit *test)
{
    test->simulate(1);
}

void Shell::_roundCircuit(Circuit *test)
{
    test->simulate(1);
    test->display();
}

void Shell::_sigintHandler(int signal)
{
    (void)signal;
    nts::simulationIsRunning = false;
}


void Shell::_loopCircuit(Circuit *test)
{
    nts::simulationIsRunning = true;
    signal(SIGINT, &Shell::_sigintHandler);
    while (nts::simulationIsRunning) {
        Shell::_simulateCircuit(test);
        Shell::_displayCircuit(test);
    }
    signal(SIGINT, SIG_DFL);
}
