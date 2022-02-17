/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** C4040
*/

#include "C4040.hpp"

C4040::C4040(std::string const &name, std::size_t nbPin = 16) : BaseComp(name, nbPin)
{
    _inPins = std::vector<int> {10, 11};
    _outPins = std::vector<int> {1, 2, 3, 4, 5, 6, 7, 9, 12, 13, 14, 15};

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
    _pins[9] = _counter % 2 ? nts::TRUE : nts::FALSE; // Q1
    _pins[7] = _counter % 4 ? nts::TRUE : nts::FALSE; // Q2
    _pins[6] = _counter % 8 ? nts::TRUE : nts::FALSE; // Q3
    _pins[5] = _counter % 16 ? nts::TRUE : nts::FALSE; // Q4
    _pins[3] = _counter % 32 ? nts::TRUE : nts::FALSE; // Q5
    _pins[2] = _counter % 64 ? nts::TRUE : nts::FALSE; // Q6
    _pins[4] = _counter % 128 ? nts::TRUE : nts::FALSE; // Q7
    _pins[13] = _counter % 512 ? nts::TRUE : nts::FALSE; // Q8
    _pins[12] = _counter % 1024 ? nts::TRUE : nts::FALSE; // Q9
    _pins[14] = _counter % 2048 ? nts::TRUE : nts::FALSE; // Q10
    _pins[15] = _counter % 4096 ? nts::TRUE : nts::FALSE; // Q11
    _pins[1] = _counter % 8192 ? nts::TRUE : nts::FALSE; // Q12
}

void C4040::simulate(std::size_t tick)
{
    std::cout << "Gonna simulate C4040" << std::endl;
    (void)tick;
    if (_links[10].component != nullptr) {
        if (_links[10].component->compute(_links[10].pin) == nts::TRUE) {
            this->resetCounter();
        }
        return;
    }
    if (_links[11].component != nullptr) {
        if (_links[11].component->compute(_links[11].pin) == nts::FALSE && _pins[11] == nts::TRUE) {
            _counter++;
            std::cout << "C4040: " << _name << ": " << _counter << std::endl;
            this->updateOutputPins();
        }
        return;
    }

}

nts::Tristate C4040::compute(std::size_t pin)
{
    if (std::find(_outPins.begin(), _outPins.end(), pin) != _outPins.end()) {
        simulate(0);
        return _pins[pin];
    } else if (std::find(_inPins.begin(), _inPins.end(), pin) != _inPins.end()) {
        if (_links[pin].component != nullptr) {
            _pins[pin] = _links[pin].component->compute(_links[pin].pin);
            return _pins[pin];
        }
    } else {
        throw BaseComp::Error("C4040: Pin not found");
    }
    return nts::UNDEFINED;
}
