/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** C4081
*/

#include "C4081.hpp"

C4081::C4081(std::string const &name, std::size_t nbPin = 14) : BaseComp(name, nbPin)
{
    _inPins = std::vector<int> {1, 2, 5, 6, 8, 9, 12, 13};
    _outPins = std::vector<int> {3, 4, 10, 11};
    for (int i =0; i < 4; i++) {
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

int getIndex(std::vector<int> v, int k)
{
    for (size_t i = 0; i < v.size(); i++) {
        if (v.at(i) == k)
            return i;
    }
    throw BaseComp::Error("Pin out of bounds");
}

nts::Tristate C4081::compute(std::size_t pin)
{
    if (std::find(_outPins.begin(), _outPins.end(), pin) != _outPins.end()) {
        _pins[pin] = _andComponents[getIndex(_outPins, pin)].compute(3);
        return _pins[pin];
    } else if (std::find(_inPins.begin(), _inPins.end(), pin) != _inPins.end()) {
        if (_links[pin].component != nullptr) {
            _pins[pin] = _links[pin].component->compute(_links[pin].pin);
            return _pins[pin];
        }
    } else {
        throw BaseComp::Error("C4081: Pin not found");
    }
    return nts::UNDEFINED;
}
