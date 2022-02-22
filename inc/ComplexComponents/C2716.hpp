/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** C2716
*/

#ifndef C2716_HPP_
#define C2716_HPP_

#include "BaseComp.hpp"

class C2716 : public BaseComp {
    public:
        C2716(std::string const &name, std::size_t nbPin);
        ~C2716();

        void fillMemory(void);
        void dumpMemory(void);
        void simulate(std::size_t tick);
        nts::Tristate compute(std::size_t pin);
    private:
        std::map<std::size_t, std::bitset<8>> _memory;
};

#endif /* !C2716_HPP_ */
