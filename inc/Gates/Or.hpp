/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** Or
*/

#ifndef OR_HPP_
#define OR_HPP_

#include "BaseComp.hpp"

class Or : public BaseComp {
    public:
        Or(const std::string &name, std::size_t nbPin);
        ~Or();

        void simulate(std::size_t tick);
        nts::Tristate compute(std::size_t pin);
};

#endif /* !OR_HPP_ */
