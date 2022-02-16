/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** 4081
*/

#ifndef C4081_HPP_
#define C4081_HPP_

#include "And.hpp"

class C4081 : public BaseComp{
    public:
        C4081(std::string const &name, std::size_t nbPin);
        ~C4081();

        nts::Tristate compute(std::size_t pin);
    protected:
        std::vector<And> _andComponents;
};

#endif /* !4081_HPP_ */
