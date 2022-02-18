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
    _builders["true"] = &Builder::createTrue;
    _builders["false"] = &Builder::createFalse;
    _builders["clock"] = &Builder::createClock;
    _builders["flipflop"] = &Builder::createFlipFlop;
    _builders["and"] = &Builder::createAnd;
    _builders["4081"] = &Builder::createC4081;
    _builders["or"] = &Builder::createOr;
    _builders["4071"] = &Builder::createC4071;
    _builders["not"] = &Builder::createNot;
    _builders["4069"] = &Builder::createC4069;
    _builders["nand"] = &Builder::createNand;
    _builders["4011"] = &Builder::createC4011;
    _builders["nor"] = &Builder::createNor;
    _builders["4001"] = &Builder::createC4001;
    _builders["xor"] = &Builder::createXor;
    _builders["4030"] = &Builder::createC4030;
    _builders["4040"] = &Builder::createC4040;
    _builders["4512"] = &Builder::createC4512;
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
        throw Builder::Error("Builder error: Unknown chipset type");
    return (this->*ptr)(name);
}

uComp Builder::createInput(std::string const &name)
{
    nts::IComponent *component = new Input(name, 1);
    return uComp(component);
}

uComp Builder::createOutput(std::string const &name)
{
    nts::IComponent *component = new Output(name, 1);
    return uComp(component);
}

uComp Builder::createTrue(std::string const &name)
{
    nts::IComponent *component = new True(name, 1);
    return uComp(component);
}

uComp Builder::createFalse(std::string const &name)
{
    nts::IComponent *component = new False(name, 1);
    return uComp(component);
}

uComp Builder::createClock(std::string const &name)
{
    nts::IComponent *component = new Clock(name);
    return uComp(component);
}

uComp Builder::createFlipFlop(std::string const &name)
{
    nts::IComponent *component = new FlipFlop(name, 6);
    return uComp(component);
}

uComp Builder::createAnd(std::string const &name)
{
    nts::IComponent *component = new And(name, 3);
    return uComp(component);
}

uComp Builder::createC4081(std::string const &name)
{
    nts::IComponent *component = new C4081(name, 14);
    return uComp(component);
}

uComp Builder::createOr(std::string const &name)
{
    nts::IComponent *component = new Or(name, 3);
    return uComp(component);
}

uComp Builder::createC4071(std::string const &name)
{
    nts::IComponent *component = new C4071(name, 14);
    return uComp(component);
}

uComp Builder::createNot(std::string const &name)
{
    nts::IComponent *component = new Not(name, 2);
    return uComp(component);
}

uComp Builder::createC4069(std::string const &name)
{
    nts::IComponent *component = new C4069(name, 14);
    return uComp(component);
}

uComp Builder::createNand(std::string const &name)
{
    nts::IComponent *component = new Nand(name, 3);
    return uComp(component);
}

uComp Builder::createC4011(std::string const &name)
{
    nts::IComponent *component = new C4011(name, 14);
    return uComp(component);
}

uComp Builder::createNor(std::string const &name)
{
    nts::IComponent *component = new Nor(name, 3);
    return uComp(component);
}

uComp Builder::createC4001(std::string const &name)
{
    nts::IComponent *component = new C4001(name, 14);
    return uComp(component);
}

uComp Builder::createXor(std::string const &name)
{
    nts::IComponent *component = new Xor(name, 3);
    return uComp(component);
}

uComp Builder::createC4030(std::string const &name)
{
    nts::IComponent *component = new C4030(name, 14);
    return uComp(component);
}

uComp Builder::createC4040(std::string const &name)
{
    nts::IComponent *component = new C4040(name, 16);
    return uComp(component);
}

uComp Builder::createC4512(std::string const &name)
{
    nts::IComponent *component = new C4512(name, 16);
    return uComp(component);
}

const char *Builder::Error::what() const noexcept
{
    return this->message->c_str();
}
