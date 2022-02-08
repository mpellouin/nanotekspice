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
}

Input::~Input()
{
}

bool Input::setValue(nts::Tristate value)
{
    if (value != _pins[1]) {
        _pins[1] = value;
        return true;
    }
    return false;
}

void Input::simulate(std::size_t tick)
{
    return;
}

void Input::dump() const
{
    std::cout << "Input " << _name << ": " << _pins.at(1) << std::endl;
}
