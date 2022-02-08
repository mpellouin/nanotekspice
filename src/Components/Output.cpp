/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** Output
*/

#include "Output.hpp"

Output::Output(std::string const &name)
{
    _name = name;
    _pins[1] = nts::UNDEFINED;
}

Output::~Output()
{
}

bool Output::setValue(nts::Tristate value)
{
    if (value != _pins[1]) {
        _pins[1] = value;
        return true;
    }
    return false;
}

void Output::simulate(std::size_t tick)
{
    return;
}

void Output::dump() const
{
    std::cout << "Output " << _name << ": "<<_pins.at(1) << std::endl;
}
