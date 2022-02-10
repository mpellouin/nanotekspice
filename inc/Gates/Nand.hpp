/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** Nand
*/

#ifndef NAND_HPP_
#define NAND_HPP_

#include "IComponent.hpp"

class Nand : public nts::IComponent {
    public:
        Nand(const std::string &name);
        ~Nand();

        void simulate(std::size_t tick);
        nts::Tristate compute(std::size_t pin);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        void dump() const;
    protected:
        std::string _name;
        std::map<std::size_t, nts::Tristate> _pins;
        std::map<std::size_t, nts::Link> _link;
};

#endif /* !NAND_HPP_ */
