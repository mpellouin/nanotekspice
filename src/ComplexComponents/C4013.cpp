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

    _flipFlopComponents.push_back(FlipFlop("FF1", 5));
    _flipFlopComponents.push_back(FlipFlop("FF2", 5));

    this->setLink(1, _flipFlopComponents[0], 1);
    this->setLink(2, _flipFlopComponents[0], 2);
    _flipFlopComponents[0].setLink(3, *this, 3);
    _flipFlopComponents[0].setLink(4, *this, 4);
    _flipFlopComponents[0].setLink(5, *this, 5);
    _flipFlopComponents[0].setLink(6, *this, 6);
}

C4013::~C4013()
{
}

int C4013::getIndex(std::vector<int> v, int k)
{
    for (size_t i = 0; i < v.size(); i++) {
        if (v.at(i) == k)
            return i;
    }
    throw BaseComp::Error("Pin out of bounds");
}

void C4013::simulate(std::size_t tick)
{
    (void)tick;
}

nts::Tristate C4013::compute(std::size_t pin)
{
    if (std::find(_outPins.begin(), _outPins.end(), pin) != _outPins.end()) {
        std::cout << "Need to compute pin n*" << pin << std::endl;
        _pins[pin] = _flipFlopComponents[0].compute(2);
        return _pins[pin];
    }



    return nts::UNDEFINED;
}
