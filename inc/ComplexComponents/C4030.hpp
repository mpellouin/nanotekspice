/*
** EPITECH PROJECT, 2022
** nts
** File description:
** C4030
*/

#ifndef C4030_HPP_
#define C4030_HPP_

#include "Xor.hpp"

class C4030 : public BaseComp{
    public:
        C4030(std::string const &name, std::size_t nbPin);
        ~C4030();

        int getIndex(std::vector<int> v, int k);
        nts::Tristate compute(std::size_t pin);
    protected:
        std::vector<Xor> _xorComponents;
};

#endif /* !C4030_HPP_ */
