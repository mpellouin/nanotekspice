/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** And
*/

#include "Or.hpp"

Or::Or(const std::string &name)
{
    _name = name;
    for (int i = 1; i <= 3 ; i++)
        _pins[i] = nts::UNDEFINED;
}

Or::~Or()
{
}

void Or::simulate(std::size_t tick)
{
    (void)tick;
    _pins[1] = compute(1);
    _pins[2] = compute(2);

    if (_pins[1] == nts::TRUE || _pins[2] == nts::TRUE)
        _pins[3] = nts::TRUE;
    else if (_pins[1] == nts::FALSE && _pins[2] == nts::FALSE)
        _pins[3] = nts::FALSE;
    else
        _pins[3] = nts::UNDEFINED;
}

nts::Tristate Or::compute(std::size_t pin)
{
    if (pin == 3)
        return _pins[3];
    if (_link[pin].component != nullptr)
        return _link[pin].component->compute(_link[pin].pin);
    return nts::UNDEFINED;
}

void Or::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin != 1 && pin != 2)
        return;
    _link[pin].component = &other;
    _link[pin].pin = otherPin;
}

void Or::dump() const
{
    std::cout << "== Or \"" << _name << "\" ==" << std::endl;
    std::cout << "= " << _pins.at(1) << " & " << _pins.at(2) << " -> " << _pins.at(3) << std::endl;
}
