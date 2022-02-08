/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** Clock
*/

#ifndef CLOCK_HPP_
#define CLOCK_HPP_

#include "IComponent.hpp"

class Clock : public nts::IComponent{
    public:
        Clock(std::string const &name);
        ~Clock();

        void simulate(std::size_t tick);
        void dump() const;
    private:
        std::string _name;
        nts::Tristate _value;
};

#endif /* !CLOCK_HPP_ */
