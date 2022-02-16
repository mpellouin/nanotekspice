/*
** EPITECH PROJECT, 2022
** nts
** File description:
** C4001
*/

#include "C4001.hpp"

C4001::C4001(std::string const &name, std::size_t nbPin = 14) : BaseComp(name, nbPin)
{
    _inPins = std::vector<int> {1, 2, 5, 6, 8, 9, 12, 13};
    _outPins = std::vector<int> {3, 4, 10, 11};
    for (int i =0; i < 4; i++) {
        _norComponents.push_back(Nor("Nor" + std::to_string(i), 3));
    }
    _norComponents[0].setLink(1, *this, 1);
    _norComponents[0].setLink(2, *this, 2);
    this->setLink(3, _norComponents[0], 3);

    _norComponents[1].setLink(1, *this, 5);
    _norComponents[1].setLink(2, *this, 6);
    this->setLink(4, _norComponents[1], 3);

    _norComponents[2].setLink(1, *this, 8);
    _norComponents[2].setLink(2, *this, 9);
    this->setLink(10, _norComponents[2], 3);

    _norComponents[3].setLink(1, *this, 12);
    _norComponents[3].setLink(2, *this, 13);
    this->setLink(11, _norComponents[3], 3);
}

C4001::~C4001()
{
}

int C4001::getIndex(std::vector<int> v, int k)
{
    for (size_t i = 0; i < v.size(); i++) {
        if (v.at(i) == k)
            return i;
    }
    throw BaseComp::Error("Pin out of bounds");
}

nts::Tristate C4001::compute(std::size_t pin)
{
    if (std::find(_outPins.begin(), _outPins.end(), pin) != _outPins.end()) {
        _pins[pin] = _norComponents[getIndex(_outPins, pin)].compute(3);
        return _pins[pin];
    } else if (std::find(_inPins.begin(), _inPins.end(), pin) != _inPins.end()) {
        if (_links[pin].component != nullptr) {
            _pins[pin] = _links[pin].component->compute(_links[pin].pin);
            return _pins[pin];
        }
    } else {
        throw BaseComp::Error("C4001: Pin not found");
    }
    return nts::UNDEFINED;
}
