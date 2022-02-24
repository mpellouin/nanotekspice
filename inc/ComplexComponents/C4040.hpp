/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** 4040
*/

#ifndef C4040_HPP_
#define C4040_HPP_

#include "BaseComp.hpp"

class C4040 : public BaseComp{
    public:
        C4040(std::string const &name, std::size_t nbPin);
        ~C4040();

        void resetCounter(void);
        void updateOutputPins(void);
        void simulate(std::size_t tick);
        nts::Tristate compute(std::size_t pin);
    private:
        int _counter;
};

#endif /* !4040_HPP_ */
