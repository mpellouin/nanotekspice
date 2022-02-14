/*
** EPITECH PROJECT, 2022
** nts
** File description:
** Xor
*/

#ifndef XOR_HPP_
#define XOR_HPP_

#include "BaseComp.hpp"

class Xor : public BaseComp {
    public:
        Xor(const std::string &name, std::size_t nbPin);
        ~Xor();

        void simulate(std::size_t tick);
        nts::Tristate compute(std::size_t pin);

    protected:
    private:
};

#endif /* !XOR_HPP_ */
