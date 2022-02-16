/*
** EPITECH PROJECT, 2022
** nts
** File description:
** C4001
*/

#ifndef C4001_HPP_
#define C4001_HPP_

#include "Nor.hpp"

class C4001 : public BaseComp{
    public:
        C4001(std::string const &name, std::size_t nbPin);
        ~C4001();

        int getIndex(std::vector<int> v, int k);
        nts::Tristate compute(std::size_t pin);
    protected:
        std::vector<Nor> _norComponents;
};

#endif /* !C4001_HPP_ */
