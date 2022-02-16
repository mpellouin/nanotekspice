/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** 4069
*/

#ifndef C4069_HPP_
#define C4069_HPP_

#include "Not.hpp"

class C4069 : public BaseComp{
    public:
        C4069(std::string const &name, std::size_t nbPin);
        ~C4069();

        int getIndex(std::vector<int> v, int k);
        nts::Tristate compute(std::size_t pin);
    protected:
        std::vector<Not> _notComponents;
};

#endif /* !4069_HPP_ */
