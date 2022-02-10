/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** Input
*/

#include "Input.hpp"

Input::Input(std::string const &name) : _name(name)
{
    _pins[1] = nts::UNDEFINED;
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

nts::Tristate Input::compute(std::size_t pin)
{
    if (pin != 1)
        return nts::UNDEFINED;
    return _pins[pin];
}


void Input::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    (void)pin;
    (void)other;
    (void)otherPin;
   return;
}

void Input::dump() const
{
    std::cout << "Input " << _name << ": " << _pins.at(1) << std::endl;
}

bool Input::setValue(nts::Tristate value)
{
    if (value != _pins[1]) {
        _newPins[1] = value;
        return true;
    }
    return false;
}
