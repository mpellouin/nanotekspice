/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** Circuit
*/

#include "Circuit.hpp"

Circuit::Circuit() : BaseComp("Global Circuit", 0)
{
}

Circuit::Circuit(const std::string &name, const std::size_t nbPin) : BaseComp(name, nbPin)
{
}

Circuit::~Circuit()
{
}

nts::IComponent *Circuit::operator[](const std::string &name)
{
    if (_components.find(name) == _components.end()) {
        throw Circuit::Error("Component not found");
    }
    return _components[name].get();
}

void Circuit::AddComponent(const std::string &type, const std::string &name)
{
    if (_components.find(name) != _components.end()) {
        throw Circuit::Error("This component already exists in this circuit");
    }
    uComp newComp = builder.createComponent(type, name);
    _components.emplace(name, std::move(newComp));
    if (type == "input" || type == "clock") {
        _inpComponents.emplace(name, std::move(newComp));
    } else if (type == "output" || type == "logger") {
        _outComponents.emplace(name, std::move(newComp));
    }
}


void Circuit::simulate(std::size_t tick)
{
    std::cout << "Inp : " << _inpComponents.size() << std::endl;

    std::for_each(_inpComponents.begin(), _inpComponents.end(), [](const std::pair<std::string, uComp> pair) {
        // pair.second->simulate(tick);
    });
    // for (auto &comp : _inpComponents) {
    //     comp.second.get()->simulate(1);
    // }
    // std::cout << "Input simulation done" << std::endl;
    // for (auto &comp : _outComponents) {
    //     comp.second.get()->simulate(1);
    // }
    std::cout << "Output simulation done" << std::endl;
    (void)tick;
    // for (auto &comp : _inPins) {
    //     if (_links[comp].component != nullptr) {
    //         std::cout << "Simulated pin " << comp << " of " << _name << " : " << _links[comp].component->compute(_links[comp].pin) << std::endl;
    //         _pins[comp] = _links[comp].component->compute(_links[comp].pin);
    //     }
    // }
    // for (auto &comp : _outPins) {
    //     if (_links[comp].component != nullptr) {
    //         std::cout << "Simulated pin " << comp << " of " << _name << " : " << _links[comp].component->compute(_links[comp].pin) << std::endl;
    //         _pins[comp] = _links[comp].component->compute(_links[comp].pin);
    //     }
    // }
    return;
}

nts::Tristate Circuit::compute(std::size_t pin)
{
    (void)pin;
    return nts::UNDEFINED;
}

void Circuit::setLink(std::size_t pin1, const std::string &comp1, std::size_t pin2, const std::string &comp2)
{
    if (_components.find(comp1) == _components.end()) {
        throw Circuit::Error("This component isn't in the circuit \"" + comp1 + "\"");
    }
    if (_components.find(comp2) == _components.end()) {
        throw Circuit::Error("This component isn't in the circuit \"" + comp2 + "\"");
    }
    _components[comp1]->setLink(pin1, *_components[comp2], pin2);
    _components[comp2]->setLink(pin2, *_components[comp1], pin1);
    return;
}

void Circuit::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    (void)pin;
    (void)other;
    (void)otherPin;
    return;
}

void Circuit::dump() const
{
    std::cout << "Dump of the circuit " << _name << std::endl;
    for (auto &comp : _components) {
        comp.second->dump();
    }
    return;
}

const char *Circuit::Error::what() const noexcept
{
    return this->message->c_str();
}
