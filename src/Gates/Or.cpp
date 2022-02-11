/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** And
*/

#include "Or.hpp"

Or::Or(const std::string &name, std::size_t nbPin) : BaseComp(name, nbPin)
{
    _inPins = std::vector<int> {1, 2};
    _outPins = std::vector<int> {3};
}

Or::~Or()
{
}

void Or::simulate(std::size_t tick)
{
    (void)tick;
    for (size_t i = 0; i < _inPins.size(); i++) {
        if (_links[_inPins.at(i)].component != nullptr) {
            _pins[_inPins.at(i)] = _links[_inPins.at(i)].component->compute(_links[_inPins.at(i)].pin);
        }
    }
    if (_pins[1] == nts::TRUE || _pins[2] == nts::TRUE)
        _pins[3] = nts::TRUE;
    else if (_pins[1] == nts::FALSE && _pins[2] == nts::FALSE)
        _pins[3] = nts::FALSE;
    else
        _pins[3] = nts::UNDEFINED;
}

nts::Tristate Or::compute(std::size_t pin)
{
    std::cout << "Or computed pin n*" << pin << std::endl;
    simulate(0);
    if (std::find(_outPins.begin(), _outPins.end(), pin) != _outPins.end()) {
        return _pins[pin];
    } else {
        throw BaseComp::Error("Pin not found");
    }
    return nts::UNDEFINED;
}
