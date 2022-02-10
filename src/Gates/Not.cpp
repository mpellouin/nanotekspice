/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** Not
*/

#include "Not.hpp"

Not::Not(const std::string &name)
{
    _name = name;
    for (int i = 1; i <= 2; i++)
        _pins[i] = nts::UNDEFINED;
}

Not::~Not()
{
}

void Not::simulate(std::size_t tick)
{
    (void)tick;
    _pins[1] = compute(1);

    if (_pins[1] == nts::TRUE)
        _pins[2] = nts::FALSE;
    else if (_pins[1] == nts::FALSE)
        _pins[3] = nts::TRUE;
    else
        _pins[3] = nts::UNDEFINED;
}

nts::Tristate Not::compute(std::size_t pin)
{
    if (pin == 2)
        return _pins[2];
    if (pin != 1)
        return nts::UNDEFINED;
    if (_link[pin].component != nullptr)
        return _link[pin].component->compute(_link[pin].pin);
    return nts::UNDEFINED;
}

void Not::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin != 1)
        return;
    _link[pin].component = &other;
    _link[pin].pin = otherPin;
}

void Not::dump() const
{
    std::cout << "== Not \"" << _name << "\" ==" << std::endl;
    std::cout << "= " << _pins.at(1) << " -> " << _pins.at(2) << std::endl;
}
