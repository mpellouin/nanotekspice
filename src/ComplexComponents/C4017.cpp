/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** C4017
*/

#include "C4017.hpp"

C4017::C4017(std::string const &name, std::size_t nbPin = 15) : BaseComp(name , nbPin)
{
    _type = "4017";
    _inPins = std::vector<int> {13, 14, 15};
    _outPins = std::vector<int> {1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12};
    _counter = -1;
}

C4017::~C4017()
{
}

void C4017::reset()
{
    std::cout << "C4017::reset" << std::endl;
    _pins[3] = nts::TRUE; // Q0
    _pins[2] = nts::FALSE; // Q1
    _pins[4] = nts::FALSE; // Q2
    _pins[7] = nts::FALSE; // Q3
    _pins[10] = nts::FALSE; // Q4
    _pins[1] = nts::FALSE; // Q5
    _pins[5] = nts::FALSE; // Q6
    _pins[6] = nts::FALSE; // Q7
    _pins[9] = nts::FALSE; // Q8
    _pins[11] = nts::FALSE; // Q9
    _pins[12] = nts::TRUE; // Q5.Q9
}

void C4017::simulate(std::size_t tick)
{
    std::cout << "C4017::simulate" << std::endl;
    std::cout << "C4017 reset value -> " << _pins[15] << std::endl;
    if (_pins[15] == nts::TRUE && _links[15].component->compute(_links[15].pin) == nts::FALSE) {
        reset();
        return;
    }
    if ((_pins[14] == nts::FALSE || _pins[14] == nts::UNDEFINED) && _links[14].component->compute(_links[14].pin) == nts::TRUE)
        std::cout << "Front montant" << std::endl;
    (void)tick;
}

nts::Tristate C4017::compute(std::size_t pin)
{
    // std::cout << "C4017::compute " << pin << std::endl;
    if (std::find(_inPins.begin(), _inPins.end(), pin) != _inPins.end()) {
        std::cout << "Computed pin n*" << pin << std::endl;
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
