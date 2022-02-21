/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** C4013
*/

#include "C4013.hpp"

C4013::C4013(std::string const &name, std::size_t nb = 14) : BaseComp(name, nb)
{
    _inPins = std::vector<int> {3, 4, 5, 6, 8, 9, 10, 11};
    _outPins = std::vector<int> {1, 2, 12, 13};

    _flipFlopComponents.push_back(FlipFlop("FF1", 5));
    _flipFlopComponents.push_back(FlipFlop("FF2", 5));

    this->setLink(1, _flipFlopComponents[0], 1);
    this->setLink(2, _flipFlopComponents[0], 2);
    _flipFlopComponents[0].setLink(3, *this, 3);
    _flipFlopComponents[0].setLink(4, *this, 4);
    _flipFlopComponents[0].setLink(5, *this, 5);
    _flipFlopComponents[0].setLink(6, *this, 6);

    this->setLink(12, _flipFlopComponents[1], 1);
    this->setLink(13, _flipFlopComponents[1], 2);
    _flipFlopComponents[1].setLink(3, *this, 11);
    _flipFlopComponents[1].setLink(4, *this, 10);
    _flipFlopComponents[1].setLink(5, *this, 9);
    _flipFlopComponents[1].setLink(6, *this, 8);
}

C4013::~C4013()
{
}

void C4013::simulate(std::size_t tick)
{
    (void)tick;
}

nts::Tristate C4013::compute(std::size_t pin)
{
    simulate(0);
    if (std::find(_outPins.begin(), _outPins.end(), pin) != _outPins.end()) {
        if (pin == 1 || pin == 2) {
            _pins[1] = _flipFlopComponents[0].compute(1);
            _pins[2] = _flipFlopComponents[0].compute(2);
        } else if (pin == 12 || pin == 13) {
            _pins[12] = _flipFlopComponents[1].compute(1);
            _pins[13] = _flipFlopComponents[1].compute(2);
        }
        return _pins[pin];
    } else if (std::find(_inPins.begin(), _inPins.end(), pin) != _inPins.end()) {
        if (_links[pin].component != nullptr)
            _pins[pin] = _links[pin].component->compute(_links[pin].pin);
        return _pins[pin];
    } else {
        throw BaseComp::Error("C4013: Pin not found");
    }



    return nts::UNDEFINED;
}
