/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** BaseComp
*/

#include "BaseComp.hpp"

BaseComp::BaseComp(const std::string &name, std::size_t nbPin) : _name(name), _nbPin(nbPin)
{
    for (size_t i = 1; i <= _nbPin; i++) {
        _pins[i] = nts::UNDEFINED;
    }
}

BaseComp::~BaseComp()
{
}

const char *BaseComp::Error::what() const noexcept
{
    return this->message.c_str();
}


void BaseComp::simulate(std::size_t tick)
{
    return (void)tick;
}

nts::Tristate BaseComp::compute(std::size_t pin)
{
    if (std::find(_outPins.begin(), _outPins.end(), pin) != _outPins.end()) {
        return _pins[pin];
    } else if (std::find(_inPins.begin(), _inPins.end(), pin) != _inPins.end()) {
        if (_links[pin].component != nullptr) {
            return _links[pin].component->compute(_links[pin].pin);
        }
    } else {
        throw BaseComp::Error("BaseComp: Pin not found");
    }
    return nts::UNDEFINED;
}

void BaseComp::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (std::find(_inPins.begin(), _inPins.end(), pin) != _inPins.end()) {
        _links[pin].component = &other;
        _links[pin].pin = otherPin;
    } else if (_type == "4801") {
        _links[pin].component = &other;
        _links[pin].pin = otherPin;
    } else {
        return;
    }

}

void BaseComp::dump() const
{
    std::cout << "=== " << _name << " ===" << std::endl;
    for (size_t i = 0; i < _inPins.size(); i++) {
        std::cout << "| Input " << _inPins.at(i) << ": " << _pins.at(_inPins.at(i)) << std::endl;
    }
    for (size_t i = 0; i < _outPins.size(); i++) {
        std::cout << "| Output " << _outPins.at(i) << ": " << _pins.at(_outPins.at(i)) << std::endl;
    }

}
