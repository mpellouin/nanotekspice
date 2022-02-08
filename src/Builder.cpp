/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** Builder
*/

#include "Builder.hpp"

Builder::Builder()
{
    _builders["input"] = &Builder::createInput;
    _builders["output"] = &Builder::createOutput;
    _builders["clock"] = &Builder::createClock;
    _builders["4081"] = &Builder::create4081;
}

Builder::~Builder()
{
}

uComp Builder::createComponent(const std::string &type, const std::string &name)
{
    builderFunc ptr = NULL;

    if (_builders.find(type) != _builders.end())
        ptr = _builders[type];
    else
        throw std::invalid_argument("Unknown chipset type");
    return (this->*ptr)(name);
}

uComp Builder::createInput(std::string const &name)
{
    nts::IComponent *component = new Input(name);
    return uComp(component);
}

uComp Builder::createOutput(std::string const &name)
{
    nts::IComponent *component = new Output(name);
    return uComp(component);
}

uComp Builder::createClock(std::string const &name)
{
    nts::IComponent *component = new Clock(name);
    return uComp(component);
}

uComp Builder::create4081(std::string const &name)
{
    nts::IComponent *component = new And(name);
    return uComp(component);
}
