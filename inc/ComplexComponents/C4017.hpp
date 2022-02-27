/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** C4017
*/

#ifndef C4017_HPP_
#define C4017_HPP_

#include "BaseComp.hpp"

class C4017 : public BaseComp {
    public:
        C4017(std::string const &name, std::size_t nbPin);
        ~C4017();

        void simulate(std::size_t tick);
        nts::Tristate compute(std::size_t pin);
    protected:
    private:
};

#endif /* !C4017_HPP_ */
