/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** Not
*/

#ifndef NOT_HPP_
#define NOT_HPP_

#include "BaseComp.hpp"

class Not : public BaseComp {
    public:
        Not(const std::string &name, std::size_t nbPin);
        ~Not();

        void simulate(std::size_t tick);
        nts::Tristate compute(std::size_t pin);
};

#endif /* !NOT_HPP_ */
