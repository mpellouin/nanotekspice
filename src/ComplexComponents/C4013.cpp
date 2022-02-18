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
}

C4013::~C4013()
{
}

void C4013::simulate(std::size_t tick)
{
}

nts::Tristate C4013::compute(std::size_t pin)
{
    // if (std::find(_inPins.begin(), _inPins.end(), pin) != _inPins.end()) {
    //     if (_links[pin].component != nullptr) {
    //         _pins[pin] = _links[pin].component->compute(_links[pin].pin);
    //     }
    //     return _pins[pin];
    // } else if (std::find(_outPins.begin(), _outPins.end(), pin) != _outPins.end()) {

    // }
}
