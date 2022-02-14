/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** Output
*/

#include "Output.hpp"

Output::Output(std::string const &name, std::size_t nbPin) : BaseComp(name, nbPin)
{
    _inPins = std::vector<int> {1};
    _outPins = std::vector<int> {};
}

Output::~Output()
{
}

void Output::simulate(std::size_t tick)
{
    (void)tick;
    for (size_t i = 0; i < _inPins.size(); i++) {
        if (_links[_inPins.at(i)].component != nullptr) {
            _pins[_inPins.at(i)] = _links[_inPins.at(i)].component->compute(_links[_inPins.at(i)].pin);
        }
    }
}
