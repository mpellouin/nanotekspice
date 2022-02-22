/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** C4801
*/

#include "C4801.hpp"

C4801::C4801(std::string const &name, std::size_t nbPin) : BaseComp(name, nbPin)
{
    _inPins = std::vector<int> {1, 2, 3, 4, 5, 6, 7, 8, 18, 20, 21, 22, 23};
    _outPins = std::vector<int> {9, 10, 11, 13, 14, 15, 16, 17};
}

C4801::~C4801()
{
}

void C4801::fillMemory()
{
}

void C4801::dumpMemory()
{
}

void C4801::simulate(std::size_t tick)
{

}

nts::Tristate C4801::compute(std::size_t pin)
{
    if (std::find(_inPins.begin(), _inPins.end(), pin) != _inPins.end()) {
        if (_links[pin].component != nullptr) {
            _pins[pin] = _links[pin].component->compute(_links[pin].pin);
            return _pins[pin];
        }
    } else if (std::find(_outPins.begin(), _outPins.end(), pin) != _outPins.end()) {
        if (!_isUpdated) {
            _isUpdated = true;
            simulate(0);
            return _pins[pin];
        }
        return _pins[pin];
    } else {
        throw Error("C4801: Pin not found");
    }
    return nts::UNDEFINED;
}
