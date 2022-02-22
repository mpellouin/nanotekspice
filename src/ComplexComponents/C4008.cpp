/*
** EPITECH PROJECT, 2022
** nts
** File description:
** C4008
*/

#include "C4008.hpp"

C4008::C4008(std::string const &name, std::size_t nbPin = 16) : BaseComp(name, nbPin)
{
    _inPins = std::vector<int> {1, 2, 3, 4, 5, 6, 7, 9, 15};
    _outPins = std::vector<int> {10, 11, 12, 13, 14};
}

C4008::~C4008()
{
}

void C4008::setAllPins(nts::Tristate state)
{
    for (auto pin : _outPins) {
        _pins[pin] = state;
    }
}

void C4008::simulate(std::size_t tick)
{
    (void)tick;
    if (_links[9].component != nullptr) {
        if (_links[9].component->compute(_links[9].pin) == nts::UNDEFINED) {
            setAllPins(nts::UNDEFINED);
            return;
        }
    }
    addInputs();
}

void C4008::addInputs()
{
    std::vector<int> inputOrder = {84, 7, 6, 9, 5, 4, 84, 3, 2, 84, 1, 15, 84};
    std::vector<int> outputOrder = {10, 11, 12, 13};
    for (int opNumber = 0; opNumber < 4; opNumber++) {
        if (_links[inputOrder[opNumber * 3 + 1]].component != nullptr && _links[inputOrder[opNumber * 3 + 2]].component != nullptr &&
        (opNumber != 0 || _links[inputOrder[opNumber * 3 + 3]].component != nullptr)) {
            auto Ai = _links[inputOrder[opNumber * 3 + 1]].component->compute(_links[inputOrder[opNumber * 3 + 1]].pin),
            Bi = _links[inputOrder[opNumber * 3 + 2]].component->compute(_links[inputOrder[opNumber * 3 + 2]].pin);
            if (Ai == nts::UNDEFINED || Bi == nts::UNDEFINED || (opNumber == 0 &&
            _links[inputOrder[opNumber * 3 + 3]].component->compute(_links[inputOrder[opNumber * 3 + 3]].pin) == nts::UNDEFINED)) {
                _pins[outputOrder[opNumber]] = nts::UNDEFINED;
                if (opNumber == 4) _pins[14] = nts::UNDEFINED;
                else outputOrder[(opNumber + 1) * 3 + 3] = 84;
            } else {
                _pins[outputOrder[opNumber]] = getAddedValue(Ai, Bi,
                    (opNumber == 0 ?
                        _links[inputOrder[opNumber * 3 + 3]].component->compute(_links[inputOrder[opNumber * 3 + 3]].pin)
                        : outputOrder[opNumber * 3 + 3]));
                if (opNumber == 4) _pins[14] = getCarryOut(Ai, Bi, outputOrder[opNumber * 3 + 3]);
                else outputOrder[(opNumber + 1) * 3 + 3] = getCarryOut(Ai, Bi, opNumber != 0 ? outputOrder[opNumber * 3 + 3] :
                _links[inputOrder[opNumber * 3 + 3]].component->compute(_links[inputOrder[opNumber * 3 + 3]].pin));
            }
        }
    }
}

nts::Tristate C4008::getAddedValue(nts::Tristate A, nts::Tristate B, nts::Tristate C)
{
    if (A == nts::UNDEFINED || B == nts::UNDEFINED || C == nts::UNDEFINED)
        return nts::UNDEFINED;
    std::vector<nts::Tristate> truthMap =
        {nts::FALSE, nts::TRUE, nts::TRUE, nts::FALSE, nts::TRUE, nts::FALSE, nts::FALSE, nts::TRUE};
    int selector = 0 + (A == nts::TRUE ? 1 : 0)
        + (B == nts::TRUE ? 2 : 0)
        + (C == nts::TRUE ? 4 : 0);
    return truthMap[selector]; 
}

nts::Tristate C4008::getAddedValue(nts::Tristate A, nts::Tristate B, int C)
{
    switch (C) {
        case 0: return getAddedValue(A, B, nts::FALSE);
        case 1: return getAddedValue(A, B, nts::TRUE);
        case 84: return nts::UNDEFINED;
        default: throw Error("Unknown state");
    }
    return nts::UNDEFINED;
}

nts::Tristate C4008::getCarryOut(nts::Tristate A, nts::Tristate B, nts::Tristate C)
{
    if (A == nts::UNDEFINED || B == nts::UNDEFINED || C == nts::UNDEFINED)
        return nts::UNDEFINED;
    std::vector<nts::Tristate> truthMap =
        {nts::FALSE, nts::FALSE, nts::FALSE, nts::TRUE, nts::FALSE, nts::TRUE, nts::TRUE, nts::TRUE};
    int selector = 0 + (A == nts::TRUE ? 1 : 0)
        + (B == nts::TRUE ? 2 : 0)
        + (C == nts::TRUE ? 4 : 0);
    return truthMap[selector];
}

nts::Tristate C4008::getCarryOut(nts::Tristate A, nts::Tristate B, int C)
{
    switch (C) {
        case 0: return getCarryOut(A, B, nts::FALSE);
        case 1: return getCarryOut(A, B, nts::TRUE);
        case 84: return nts::UNDEFINED;
        default: throw Error("Unknown state");
    }
    return nts::UNDEFINED;
}

nts::Tristate C4008::compute(std::size_t pin)
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
        throw BaseComp::Error("C4008: Pin not found");
    }
    return nts::UNDEFINED;
}

