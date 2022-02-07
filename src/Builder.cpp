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
    // _builders["output"] = &Builder::createOutput;
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
        throw std::invalid_argument("Unknown chipset type");
    return (this->*ptr)(type);
}

uComp Builder::createInput(std::string const &name)
{
    nts::IComponent *component = new Input(name);
    return uComp(component);
}

uComp Builder::createOutput(std::string const &name)
{
    // nts::IComponent *component = new Output();
    // return uComp(component);
    return nullptr;
}
