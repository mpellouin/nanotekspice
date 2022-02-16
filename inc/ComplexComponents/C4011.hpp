/*
** EPITECH PROJECT, 2022
** nts
** File description:
** C4011
*/

#ifndef C4011_HPP_
#define C4011_HPP_

#include "Nand.hpp"

class C4011 : public BaseComp{
    public:
        C4011(std::string const &name, std::size_t nbPin);
        ~C4011();

        int getIndex(std::vector<int> v, int k);
        nts::Tristate compute(std::size_t pin);
    protected:
        std::vector<Nand> _nandComponents;
};

#endif /* !C4011_HPP_ */
