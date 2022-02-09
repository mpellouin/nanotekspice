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

void Output::simulate(std::size_t tick)
{
    _pins[1] = compute(1);
    return;
}

nts::Tristate Output::compute(std::size_t pin)
{
    if (pin != 1)
        return nts::UNDEFINED;
    if (_link[pin].component != nullptr)
        return _link[pin].component->compute(_link[pin].pin);
    return nts::UNDEFINED;
}

void Output::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin != 1)
        return;
    _link[pin].component = &other;
    _link[pin].pin = otherPin;
}

void Output::dump() const
{
    std::cout << "Output " << _name << ": "<<_pins.at(1) << std::endl;
}
