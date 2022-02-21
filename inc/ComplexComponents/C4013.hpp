/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** C4013
*/

#ifndef C4013_HPP_
#define C4013_HPP_

#include "FlipFlop.hpp"

class C4013 : public BaseComp {
    public:
        C4013(std::string const &name, std::size_t nbPin);
        ~C4013();

        void simulate(std::size_t tick);
        nts::Tristate compute(std::size_t pin);

    protected:
        std::vector<FlipFlop> _flipFlopComponents;
};

#endif /* !C4013_HPP_ */
