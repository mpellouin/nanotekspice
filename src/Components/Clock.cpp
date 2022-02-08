/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** Clock
*/

#include "Clock.hpp"

Clock::Clock(std::string const &name) : Input(name)
{
}

Clock::~Clock()
{
}

void Clock::simulate(std::size_t tick)
{
    std::cout << "Clock simulation" << std::endl;
    if (_pins[1] != nts::UNDEFINED) {
        _pins[1] = (_pins[1] == nts::TRUE) ? nts::FALSE : nts::TRUE;
    }
}
