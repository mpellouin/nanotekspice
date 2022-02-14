/*
** EPITECH PROJECT, 2022
** nts
** File description:
** Nor
*/

#ifndef NOR_HPP_
#define NOR_HPP_

#include "BaseComp.hpp"

class Nor : public BaseComp {
    public:
        Nor(const std::string &name, std::size_t nbPin);
        ~Nor();

        void simulate(std::size_t tick);
        nts::Tristate compute(std::size_t pin);

    protected:
    private:
};

#endif /* !NOR_HPP_ */
