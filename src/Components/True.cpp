/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** True
*/

#include "True.hpp"

True::True(std::string const &name, std::size_t nbPin) : BaseComp(name, nbPin)
{
    _inPins = std::vector<int> {};
    _outPins = std::vector<int> {1};
    _pins[1] = nts::TRUE;
}

True::~True()
{
}
