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
    // std::cout << "C4017::reset" << std::endl;
    _counter = 0;
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

void C4017::updatePins()
{
    _pins[3] = _counter == 0 ? nts::TRUE : nts::FALSE;
    _pins[2] = _counter == 1 ? nts::TRUE : nts::FALSE;
    _pins[4] = _counter == 2 ? nts::TRUE : nts::FALSE;
    _pins[7] = _counter == 3 ? nts::TRUE : nts::FALSE;
    _pins[10] = _counter == 4 ? nts::TRUE : nts::FALSE;
    _pins[1] = _counter == 5 ? nts::TRUE : nts::FALSE;
    _pins[5] = _counter == 6 ? nts::TRUE : nts::FALSE;
    _pins[6] = _counter == 7 ? nts::TRUE : nts::FALSE;
    _pins[9] = _counter == 8 ? nts::TRUE : nts::FALSE;
    _pins[11] = _counter == 9 ? nts::TRUE : nts::FALSE;
    _pins[12] = _counter >= 5 && _counter <= 9 ? nts::FALSE : nts::TRUE;
}

void C4017::simulate(std::size_t tick)
{
    (void)tick;
    // std::cout << "C4017 reset value -> " << _pins[15] << std::endl;

    nts::Tristate newPin15 = _links[15].component->compute(_links[15].pin);
    nts::Tristate newPin14 = _links[14].component->compute(_links[14].pin);
    nts::Tristate newPin13 = _links[13].component->compute(_links[13].pin);

    if (newPin15 == nts::TRUE) {
        reset();
        return;
    }
    if ((_pins[14] == nts::FALSE || _pins[14] == nts::UNDEFINED) && newPin14 == nts::TRUE && ((_pins[13] == nts::FALSE || _pins[13] == nts::UNDEFINED))) {
        // std::cout << "Johnson ++" << std::endl;
        _counter += _counter < 9 ? 1 : -9;
    } else if (_pins[13] == nts::TRUE && newPin13 == nts::FALSE && _pins[14] == nts::TRUE) {
        // std::cout << "Johnson alt ++" << std::endl;
        _counter += _counter < 9 ? 1 : -9;
    }
    std::cout << "C4017::simulate (" << _counter << ")" << std::endl;
    updatePins();
    _pins[13] = newPin13;
    _pins[14] = newPin14;
}

nts::Tristate C4017::compute(std::size_t pin)
{
    // std::cout << "C4017::compute " << pin << std::endl;
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
