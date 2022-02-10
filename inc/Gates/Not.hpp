/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** Not
*/

#ifndef NOT_HPP_
#define NOT_HPP_

#include "IComponent.hpp"

class Not : public nts::IComponent {
    public:
        Not(const std::string &name);
        ~Not();

        void simulate(std::size_t tick);
        nts::Tristate compute(std::size_t pin);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        void dump() const;

    protected:
        std::string _name;
        std::map<std::size_t, nts::Tristate> _pins;
        std::map<std::size_t, nts::Link> _link;
};

#endif /* !NOT_HPP_ */
