/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** Clock
*/

#include "Clock.hpp"

Clock::Clock(std::string const &name) : _name(name), _value(nts::UNDEFINED)
{
}

Clock::~Clock()
{
}

void Clock::simulate(std::size_t tick)
{
    if (this->_value != nts::UNDEFINED) {
        for (size_t i = 0; i < tick; i++) {
            this->_value = (this->_value == nts::TRUE) ? nts::FALSE : nts::TRUE;
        }
    }
}

void Clock::dump() const
{
    std::cout << "Clock " << _name << ": " << _value << std::endl;
}
