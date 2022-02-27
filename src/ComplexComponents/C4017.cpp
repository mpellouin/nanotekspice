/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** C4017
*/

#include "C4017.hpp"

C4017::C4017(std::string const &name, std::size_t nbPin = 14) : BaseComp(name , nbPin)
{
    _type = "4017";
    _inPins = std::vector<int> {13, 14, 15};
    _outPins = std::vector<int> {1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12};
}

C4017::~C4017()
{
}

void C4017::simulate(std::size_t tick)
{
    std::cout << "C4017::simulate" << std::endl;
    (void)tick;
}

nts::Tristate C4017::compute(std::size_t pin)
{
    if (std::find(_inPins.begin(), _inPins.end(), pin) != _inPins.end()) {
        if (_links[pin].component != nullptr) {
            _pins[pin] = _links[pin].component->compute(_links[pin].pin);
        }
        return _pins[pin];
    } else if (std::find(_outPins.begin(), _outPins.end(), pin) != _outPins.end()) {
        if (!_isUpdated) {
            _isUpdated = true;
            simulate(0);
        }
        return _pins[pin];
    } else {
        throw BaseComp::Error("C4017: Pin not found");
    }
}
