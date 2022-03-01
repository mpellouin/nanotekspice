/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** Factory
*/

#include "Factory.hpp"

Factory::Factory()
{
    _factories["logger"] = &Factory::createLogger;
    _factories["input"] = &Factory::createInput;
    _factories["output"] = &Factory::createOutput;
    _factories["true"] = &Factory::createTrue;
    _factories["false"] = &Factory::createFalse;
    _factories["clock"] = &Factory::createClock;
    _factories["flipflop"] = &Factory::createFlipFlop;
    _factories["and"] = &Factory::createAnd;
    _factories["4081"] = &Factory::createC4081;
    _factories["or"] = &Factory::createOr;
    _factories["4071"] = &Factory::createC4071;
    _factories["not"] = &Factory::createNot;
    _factories["4069"] = &Factory::createC4069;
    _factories["nand"] = &Factory::createNand;
    _factories["4011"] = &Factory::createC4011;
    _factories["nor"] = &Factory::createNor;
    _factories["4001"] = &Factory::createC4001;
    _factories["xor"] = &Factory::createXor;
    _factories["4030"] = &Factory::createC4030;
    _factories["4040"] = &Factory::createC4040;
    _factories["4512"] = &Factory::createC4512;
    _factories["4013"] = &Factory::createC4013;
    _factories["4514"] = &Factory::createC4514;
    _factories["2716"] = &Factory::createC2716;
    _factories["4801"] = &Factory::createC4801;
    _factories["4008"] = &Factory::createC4008;
}

Factory::~Factory()
{
}

uComp Factory::createComponent(const std::string &type, const std::string &name)
{
    factoryFunc ptr = NULL;

    if (_factories.find(type) != _factories.end())
        ptr = _factories[type];
    else
        throw Factory::Error("Factory error: Unknown chipset type ['" + type + "']");
    return (this->*ptr)(name);
}

uComp Factory::createLogger(std::string const &name)
{
    return uComp(new Logger(name, 10));
}


uComp Factory::createInput(std::string const &name)
{
    return uComp(new Input(name, 1));
}

uComp Factory::createOutput(std::string const &name)
{
    return uComp(new Output(name, 1));
}

uComp Factory::createTrue(std::string const &name)
{
    return uComp(new True(name, 1));
}

uComp Factory::createFalse(std::string const &name)
{
    return uComp(new False(name, 1));
}

uComp Factory::createClock(std::string const &name)
{
    return uComp(new Clock(name));
}

uComp Factory::createFlipFlop(std::string const &name)
{
    return uComp(new FlipFlop(name, 6));
}

uComp Factory::createAnd(std::string const &name)
{
    return uComp(new And(name, 3));
}

uComp Factory::createC4081(std::string const &name)
{
    return uComp(new LogicalComponent<And>(name, 14));
}

uComp Factory::createOr(std::string const &name)
{
    return uComp(new Or(name, 3));
}

uComp Factory::createC4071(std::string const &name)
{
    return uComp(new LogicalComponent<Or>(name, 14));
}

uComp Factory::createNot(std::string const &name)
{
    return uComp(new Not(name, 2));
}

uComp Factory::createC4069(std::string const &name)
{
    return uComp(new C4069(name, 14));
}

uComp Factory::createNand(std::string const &name)
{
    return uComp(new Nand(name, 3));
}

uComp Factory::createC4011(std::string const &name)
{
    return uComp(new LogicalComponent<Nand>(name, 14));
}

uComp Factory::createNor(std::string const &name)
{
    return uComp(new Nor(name, 3));
}

uComp Factory::createC4001(std::string const &name)
{
    return uComp(new LogicalComponent<Nor>(name, 14));
}

uComp Factory::createXor(std::string const &name)
{
    return uComp(new Xor(name, 3));
}

uComp Factory::createC4030(std::string const &name)
{
    return uComp(new LogicalComponent<Xor>(name, 14));
}

uComp Factory::createC4040(std::string const &name)
{
    return uComp(new C4040(name, 16));
}

uComp Factory::createC4512(std::string const &name)
{
    return uComp(new C4512(name, 16));
}

uComp Factory::createC4013(std::string const &name)
{
    return uComp(new C4013(name, 14));
}

uComp Factory::createC4514(std::string const &name)
{
    return uComp(new C4514(name, 24));
}

uComp Factory::createC4008(std::string const &name)
{
    return uComp(new C4008(name, 16));
}

uComp Factory::createC2716(std::string const &name)
{
    return uComp(new C2716(name, 24));
}

uComp Factory::createC4801(std::string const &name)
{
    return uComp(new C4801(name, 24));
}

const char *Factory::Error::what() const noexcept
{
    return this->message.c_str();
}
