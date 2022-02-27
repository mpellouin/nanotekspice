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
    (void)tick;
}

nts::Tristate C4017::compute(std::size_t pin)
{

}
