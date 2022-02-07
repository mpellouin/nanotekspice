/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** Builder
*/

#include "Builder.hpp"

Builder::Builder()
{
}

Builder::~Builder()
{
}

uComp Builder::createComponent(const std::string &type)
{
    builderFunc ptr = NULL;

    if (_builders.find(type) != _builders.end())
        ptr = _builders[type];
    else
        throw std::invalid_argument("Unknown component type");
    return (this->*ptr)(type);
}

uComp Builder::createInput()
{
    return nullptr;
}

uComp Builder::createOutput()
{
    return nullptr;
}

uComp Builder::create4001()
{
    return nullptr;
}
