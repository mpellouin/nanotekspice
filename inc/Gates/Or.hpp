/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** Or
*/

#ifndef OR_HPP_
#define OR_HPP_

#include "IComponent.hpp"

class Or : public nts::IComponent {
    public:
        Or(const std::string &name);
        ~Or();

        void simulate(std::size_t tick);
        nts::Tristate compute(std::size_t pin);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        void dump() const;
    protected:
        std::string _name;
        std::map<std::size_t, nts::Tristate> _pins;
        std::map<std::size_t, nts::Link> _link;
};

#endif /* !OR_HPP_ */
