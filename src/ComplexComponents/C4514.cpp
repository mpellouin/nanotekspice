/*
** EPITECH PROJECT, 2022
** nts
** File description:
** C4514
*/

#include "C4514.hpp"

C4514::C4514(std::string const &name, std::size_t nbPin = 16) : BaseComp(name, nbPin)
{
    _type = "4514";
    _inPins = std::vector<int> {1, 2, 3, 21, 22, 23};
    _outPins = std::vector<int> {4, 5, 6, 7, 8, 9, 10, 11, 13, 14, 15, 16, 17, 18, 19, 20};
    _prevStates = {nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED};
    _inputStates = {nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED};
}

C4514::~C4514()
{
}

void C4514::setAllPins(nts::Tristate state)
{
    for (auto pin : _outPins) {
        _pins[pin] = state;
    }
}

void C4514::simulate(std::size_t tick)
{
    (void)tick;
    if (_links[1].component != nullptr) {
        if (_links[1].component->compute(_links[1].pin) == nts::UNDEFINED) return;
        else if (_links[1].component->compute(_links[1].pin) == nts::TRUE) {
            _prevStates = _inputStates;
            _inputStates[0] = _links[2].component != nullptr ? _links[2].component->compute(_links[2].pin) : nts::UNDEFINED;
            _inputStates[1] = _links[3].component != nullptr ? _links[3].component->compute(_links[3].pin) : nts::UNDEFINED;
            _inputStates[2] = _links[21].component != nullptr ? _links[21].component->compute(_links[21].pin) : nts::UNDEFINED;
            _inputStates[3] = _links[22].component != nullptr ? _links[22].component->compute(_links[22].pin) : nts::UNDEFINED;
            return ;
        }
    }
    if (_links[23].component != nullptr) {
        if (_links[23].component->compute(_links[23].pin) == nts::UNDEFINED) {
            setAllPins(nts::UNDEFINED);
            return;
        }
        if (_links[23].component->compute(_links[23].pin) == nts::TRUE) {
            setAllPins(nts::FALSE);
            return;
        }
    }
    selectInput();
}

void C4514::selectInput()
{
    int selector = 0;
    std::vector<int> outputLocations = {11, 9, 10, 8, 7, 6, 5, 4, 18, 17, 20, 19, 14, 13, 16, 15};
    if (_links[2].component != nullptr && _links[3].component != nullptr &&
    _links[21].component != nullptr && _links[22].component != nullptr) {
        if (_prevStates[0] == nts::UNDEFINED || _prevStates[1] == nts::UNDEFINED ||
            _prevStates[2] == nts::UNDEFINED || _prevStates[3] == nts::UNDEFINED) {
                setAllPins(nts::UNDEFINED);
                return;
            }
        selector += (_prevStates[0] == nts::TRUE ? 1 : 0) + (_prevStates[1] == nts::TRUE ? 2 : 0) +
                (_prevStates[2] == nts::TRUE ? 4 : 0) + (_prevStates[3] == nts::TRUE ? 8 : 0);
        setAllPins(nts::FALSE);
        _pins[outputLocations.at(selector)] = nts::TRUE;
        }
}

nts::Tristate C4514::compute(std::size_t pin)
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
        throw BaseComp::Error("C4514: Pin not found");
    }
    return nts::UNDEFINED;
}
