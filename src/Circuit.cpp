/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** Circuit
*/

#include "Circuit.hpp"

Circuit::Circuit()
{
}

Circuit::~Circuit()
{
}

nts::IComponent *Circuit::operator[](const std::string &name)
{
    if (_components.find(name) == _components.end()) {
        std::cout << "Unknown component " << name << std::endl;
        throw std::exception();
    }
    return _components[name].get();
}

void Circuit::AddComponent(const std::string &type, const std::string &name)
{
    if (_components.find(name) != _components.end()) {
        std::cout << "This component is already in this circuit" << std::endl;
        return;
    }
    uComp newComp = builder.createComponent(type, name);
    _components.emplace(name, std::move(newComp));
}

void Circuit::simulate(std::size_t tick)
{
    for (auto &comp : _components) {
        comp.second->simulate(1);
    }
    return;
}

nts::Tristate Circuit::compute(std::size_t pin)
{
    return nts::UNDEFINED;
}

void Circuit::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    return;
}

void Circuit::dump() const
{
    std::cout << "==== Circuit ====" << std::endl;
    std::cout << "= Size : " << _components.size() << std::endl;
    for (auto &comp : _components) {
        comp.second->dump();
    }
}

const char *Circuit::Error::what() const noexcept
{
    return this->message->c_str();
}
