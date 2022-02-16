/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** 4081
*/

#ifndef C4071_HPP_
#define C4071_HPP_

#include "Or.hpp"

class C4071 : public BaseComp{
    public:
        C4071(std::string const &name, std::size_t nbPin);
        ~C4071();

        int getIndex(std::vector<int> v, int k);
        nts::Tristate compute(std::size_t pin);
    protected:
        std::vector<Or> _orComponents;
};

#endif /* !4081_HPP_ */
