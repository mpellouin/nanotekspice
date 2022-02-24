/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** C4069
*/

#include "C4069.hpp"

C4069::C4069(std::string const &name, std::size_t nbPin = 14) : BaseComp(name, nbPin)
{
    _type = "4069";
    _inPins = std::vector<int> {1, 3, 5, 9, 11, 13};
    _outPins = std::vector<int> {2, 4, 6, 8, 10, 12};
    for (int i =0; i < 6; i++) {
        _notComponents.push_back(Not("Not" + std::to_string(i), 3));
    }
    _notComponents[0].setLink(1, *this, 1);
    this->setLink(2, _notComponents[0], 2);

    _notComponents[1].setLink(1, *this, 3);
    this->setLink(4, _notComponents[1], 2);

    _notComponents[2].setLink(1, *this, 5);
    this->setLink(6, _notComponents[1], 2);

    _notComponents[3].setLink(1, *this, 9);
    this->setLink(8, _notComponents[1], 2);

    _notComponents[4].setLink(1, *this, 11);
    this->setLink(10, _notComponents[1], 2);

    _notComponents[5].setLink(1, *this, 13);
    this->setLink(12, _notComponents[1], 2);
}

C4069::~C4069()
{
}

int C4069::getIndex(std::vector<int> v, int k)
{
    for (size_t i = 0; i < v.size(); i++) {
        if (v.at(i) == k)
            return i;
    }
    throw BaseComp::Error("Pin out of bounds");
}

nts::Tristate C4069::compute(std::size_t pin)
{
    if (std::find(_outPins.begin(), _outPins.end(), pin) != _outPins.end()) {
        _pins[pin] = _notComponents[getIndex(_outPins, pin)].compute(2);
        return _pins[pin];
    } else if (std::find(_inPins.begin(), _inPins.end(), pin) != _inPins.end()) {
        if (_links[pin].component != nullptr) {
            _pins[pin] = _links[pin].component->compute(_links[pin].pin);
            return _pins[pin];
        }
    } else {
        throw BaseComp::Error("C4069: Pin not found");
    }
    return nts::UNDEFINED;
}
