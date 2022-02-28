/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** C4040
*/

#include "C4040.hpp"

C4040::C4040(std::string const &name, std::size_t nbPin = 16) : BaseComp(name, nbPin)
{
    _type = "4040";
    _inPins = std::vector<int> {10, 11};
    _outPins = std::vector<int> {1, 2, 3, 4, 5, 6, 7, 9, 12, 13, 14, 15};
    _counter = -1;
}

C4040::~C4040()
{
}

void C4040::resetCounter(void)
{
    _counter = 0;
    for (std::size_t i = 0; i < _outPins.size(); i++) {
        _pins[_outPins.at(i)] = nts::FALSE;
    }
}

void C4040::updateOutputPins(void)
{
    if (_counter == 0) {
        resetCounter();
        return;
    }
    std::bitset<12> bits(_counter);
    _pins[9] = bits[0] == 1 ? nts::TRUE : nts::FALSE;   // Q1
    _pins[7] = bits[1] == 1 ? nts::TRUE : nts::FALSE;   // Q2
    _pins[6] = bits[2] == 1 ? nts::TRUE : nts::FALSE;   // Q3
    _pins[5] = bits[3] == 1 ? nts::TRUE : nts::FALSE;   // Q4
    _pins[3] = bits[4] == 1 ? nts::TRUE : nts::FALSE;   // Q5
    _pins[2] = bits[5] == 1 ? nts::TRUE : nts::FALSE;   // Q6
    _pins[4] = bits[6] == 1 ? nts::TRUE : nts::FALSE;   // Q7
    _pins[13] = bits[7] == 1 ? nts::TRUE : nts::FALSE;  // Q8
    _pins[12] = bits[8] == 1 ? nts::TRUE : nts::FALSE;  // Q9
    _pins[14] = bits[9] == 1 ? nts::TRUE : nts::FALSE;  // Q10
    _pins[15] = bits[10] == 1 ? nts::TRUE : nts::FALSE; // Q11
    _pins[1] = bits[11] == 1 ? nts::TRUE : nts::FALSE;  // Q12
}

void C4040::simulate(std::size_t tick)
{
    (void)tick;
    if (_links[11].component != nullptr && compute(11) == nts::TRUE) {
        this->resetCounter();
        _pins[10] = compute(10);
        return;
    }
    if (_links[10].component != nullptr && _counter != -1) {
        if (_pins[10] == nts::TRUE && _links[10].component->compute(_links[10].pin) == nts::FALSE) {
            _counter++;
        }
        this->updateOutputPins();
        _pins[10] = compute(10);
        return;
    }
}

nts::Tristate C4040::compute(std::size_t pin)
{
    if (std::find(_outPins.begin(), _outPins.end(), pin) != _outPins.end()) {
        simulate(0);
        if (_counter == -1) {
            return nts::UNDEFINED;
        } else {
            return _pins[pin];
        }
    } else if (std::find(_inPins.begin(), _inPins.end(), pin) != _inPins.end()) {
        if (_links[pin].component != nullptr) {
            _pins[pin] = _links[pin].component->compute(_links[pin].pin);
        }
        return _pins[pin];
    } else {
        throw BaseComp::Error("C4040: Pin not found");
    }
    return nts::UNDEFINED;
}
