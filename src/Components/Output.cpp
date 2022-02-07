/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** Output
*/

#include "Output.hpp"

Output::Output(std::string const &name) : _name(name), _value(nts::UNDEFINED)
{
}

Output::~Output()
{
}

void Output::dump() const
{
    std::cout << "Output " << _name << ": " << _value << std::endl;
}
