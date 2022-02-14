/*
** EPITECH PROJECT, 2022
** nts
** File description:
** Xor
*/

#include "Xor.hpp"

Xor::Xor(const std::string &name, std::size_t nbPin) : BaseComp(name, nbPin)
{
    _inPins = std::vector<int> {1, 2};
    _outPins = std::vector<int> {3};
}

Xor::~Xor()
{
}

void Xor::simulate(std::size_t tick)
{
    (void)tick;
    for (size_t i = 0; i < _inPins.size(); i++) {
        if (_links[_inPins.at(i)].component != nullptr) {
            _pins[_inPins.at(i)] = _links[_inPins.at(i)].component->compute(_links[_inPins.at(i)].pin);
        }
    }
    if (_pins[1] == nts::UNDEFINED || _pins[2] == nts::UNDEFINED)
        _pins[3] = nts::UNDEFINED;
    else if (_pins[1] == _pins[2])
        _pins[3] = nts::FALSE;
    else
        _pins[3] = nts::TRUE;
}

nts::Tristate Xor::compute(std::size_t pin)
{
    simulate(0);
    if (std::find(_outPins.begin(), _outPins.end(), pin) != _outPins.end()) {
        return _pins[pin];
    } else {
        throw BaseComp::Error("Pin not found");
    }
    return nts::UNDEFINED;
}

