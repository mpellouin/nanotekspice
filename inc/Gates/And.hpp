/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** And
*/

#ifndef AND_HPP_
#define AND_HPP_

#include "BaseComp.hpp"

class And : public BaseComp{
    public:
        And(const std::string &name, std::size_t nbPin);
        ~And();

        void simulate(std::size_t tick);
        nts::Tristate compute(std::size_t pin);
};

#endif /* !AND_HPP_ */
