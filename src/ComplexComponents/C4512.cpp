/*
** EPITECH PROJECT, 2022
** nts
** File description:
** C4512
*/

#include "C4512.hpp"

C4512::C4512(std::string const &name, std::size_t nbPin = 16) : BaseComp(name, nbPin)
{
    _inPins = std::vector<int> {1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 15};
    _outPins = std::vector<int> {14};
}

C4512::~C4512()
{
}

void C4512::simulate(std::size_t tick)
{
    (void)tick;
    if (_links[15].component != nullptr) {
        if (_links[15].component->compute(_links[15].pin) == nts::UNDEFINED ||
            _links[15].component->compute(_links[15].pin) == nts::TRUE) {
            _pins[14] = nts::UNDEFINED;
            return;
        }
    }
    if (_links[10].component != nullptr) {
        if (_links[10].component->compute(_links[10].pin) == nts::UNDEFINED) {
            _pins[14] = nts::UNDEFINED;
            return;
        }
        if (_links[10].component->compute(_links[10].pin) == nts::TRUE) {
            _pins[14] = nts::FALSE;
            return;
        }
    }
    selectInput();
}

void C4512::selectInput()
{
    int selector = 0;
    if (_links[11].component != nullptr && _links[12].component != nullptr && _links[13].component != nullptr) {
        if (_links[11].component->compute(_links[11].pin) == nts::UNDEFINED ||
            _links[12].component->compute(_links[12].pin) == nts::UNDEFINED ||
            _links[13].component->compute(_links[13].pin) == nts::UNDEFINED) {
                _pins[14] = nts::UNDEFINED;
                return;
            }
        selector += (_links[11].component->compute(_links[11].pin) == nts::TRUE ? 1 : 0) +
                (_links[12].component->compute(_links[12].pin) == nts::TRUE ? 2 : 0) +
                (_links[13].component->compute(_links[13].pin) == nts::TRUE ? 4 : 0);
        if (selector == 7) {
            _pins[14] = _links[9].component->compute(_links[9].pin);
            return;
        }
        _pins[14] = _links[selector + 1].component->compute(_links[selector + 1].pin);
        return;
    }
    _pins[14] = nts::FALSE;
}

nts::Tristate C4512::compute(std::size_t pin)
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
        throw BaseComp::Error("C4512: Pin not found");
    }
    return nts::UNDEFINED;
}

