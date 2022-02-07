/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** Input
*/

#include "Input.hpp"

Input::Input(std::string const &name) : _name(name), _value(nts::UNDEFINED)
{
}

Input::~Input()
{
}

void Input::dump() const
{
    std::cout << "Input " << _name << ": " << _value << std::endl;
}
