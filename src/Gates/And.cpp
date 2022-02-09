/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** And
*/

#include "And.hpp"

And::And(const std::string &name)
{
    _name = name;
    for (int i = 1; i <= 3 ; i++)
        _pins[i] = nts::UNDEFINED;
}

And::~And()
{
}

void And::simulate(std::size_t tick)
{
    _pins[3] = compute(3);
}

nts::Tristate And::compute(std::size_t pin)
{
    if (_pins[1] == nts::FALSE || _pins[2] == nts::FALSE)
        return nts::FALSE;
    else if (_pins[1] == nts::TRUE && _pins[2] == nts::TRUE)
        return nts::TRUE;
    else
        return nts::UNDEFINED;
}

void And::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin != 1 && pin != 2)
        return;
    _link[pin].component = &other;
    _link[pin].pin = otherPin;
}

void And::dump() const
{
    std::cout << "==== And gate \"" << _name << "\" ====" << std::endl;
    std::cout << "|- Door 1: " << _pins.at(1) << " & " << _pins.at(2) << " -> " << _pins.at(3) << std::endl;
//     std::cout << "|- Door 2: " << _pins.at(5) << " & " << _pins.at(6) << " -> " << _pins.at(4) << std::endl;
//     std::cout << "|- Door 3: " << _pins.at(8) << " & " << _pins.at(9) << " -> " << _pins.at(10) << std::endl;
//     std::cout << "|- Door 4: " << _pins.at(12) << " & " << _pins.at(13) << " -> " << _pins.at(11) << std::endl;
}
