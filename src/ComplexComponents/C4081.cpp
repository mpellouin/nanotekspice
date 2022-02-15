/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** C4081
*/

#include "C4081.hpp"

C4081::C4081(std::string const &name, std::size_t nbPin) : BaseComp(name, nbPin)
{
    _inPins = std::vector<int> {1, 2, 5, 6, 8, 9, 12, 13};
    _outPins = std::vector<int> {3, 4, 10, 11};
    for (int i = 0; i < 4; i++) {
        _andComponents.push_back(And("And" + std::to_string(i), 3));
    }
    _andComponents[0].setLink(1, *this, 1);
    _andComponents[0].setLink(2, *this, 2);
    this->setLink(3, _andComponents[0], 3);

    _andComponents[1].setLink(1, *this, 5);
    _andComponents[1].setLink(2, *this, 6);
    this->setLink(4, _andComponents[1], 3);

    _andComponents[2].setLink(1, *this, 8);
    _andComponents[2].setLink(2, *this, 9);
    this->setLink(10, _andComponents[2], 3);

    _andComponents[3].setLink(1, *this, 12);
    _andComponents[3].setLink(2, *this, 13);
    this->setLink(11, _andComponents[3], 3);
}

C4081::~C4081()
{
}

void C4081::simulate(std::size_t tick)
{
    (void)tick;
    for (size_t i = 0; i < _inPins.size(); i++) {
        if (_links[_inPins.at(i)].component != nullptr) {
            _pins[_inPins.at(i)] = _links[_inPins.at(i)].component->compute(_links[_inPins.at(i)].pin);
        }
    }
    for (size_t i = 0; i < _outPins.size(); i++) {
        _pins[_outPins.at(i)] = _andComponents[i].compute(3);
    }
}

nts::Tristate C4081::compute(std::size_t pin)
{
    if (std::find(_inPins.begin(), _inPins.end(), pin) != _inPins.end()) {
        return _pins[pin];
    }
    else if (std::find(_outPins.begin(), _outPins.end(), pin) != _outPins.end()) {
        simulate(0);
        return _pins[pin];
    } else {
        throw BaseComp::Error("C4081 Pin not found");
    }
    return nts::UNDEFINED;
}
