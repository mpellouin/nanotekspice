/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** And
*/

#ifndef AND_HPP_
#define AND_HPP_

#include "IComponent.hpp"

class And : public nts::IComponent {
    public:
        And(const std::string &name);
        ~And();
        void dump() const;
        void simulate(std::size_t tick);
        nts::Tristate compute(std::size_t pin);

    protected:
        std::string _name;
        std::map<std::size_t, nts::Tristate> _pins;
};

#endif /* !AND_HPP_ */
