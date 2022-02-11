/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** Input
*/

#include "Input.hpp"

Input::Input(std::string const &name, std::size_t nbPin) : BaseComp(name, nbPin)
{
    _inPins = std::vector<int> {};
    _outPins = std::vector<int> {1};
    _newPins.clear();
}

Input::~Input()
{
}

void Input::simulate(std::size_t tick)
{
    (void)tick;
    if (_newPins.size() > 0) {
        _pins = _newPins;
        _newPins.clear();
    }
}

bool Input::setValue(nts::Tristate value)
{
    if (value != _pins[1]) {
        _newPins[1] = value;
        return true;
    }
    return false;
}
