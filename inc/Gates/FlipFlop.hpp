/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** FlipFlop
*/

#ifndef FLIPFLOP_HPP_
#define FLIPFLOP_HPP_

#include "BaseComp.hpp"

class FlipFlop : public BaseComp{
    public:
        FlipFlop(const std::string &name, std::size_t nbPin);
        ~FlipFlop();

        bool isNegligeable(std::size_t pin);
        bool ManageSetters(void);
        void simulate(std::size_t tick);
        nts::Tristate compute(std::size_t pin);
};

#endif /* !FLIPFLOP_HPP_ */
