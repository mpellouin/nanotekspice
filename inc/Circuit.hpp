/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** Circuit
*/

#ifndef CIRCUIT_HPP_
#define CIRCUIT_HPP_

#include "IComponent.hpp"
#include "Builder.hpp"

class Circuit : public nts::IComponent{
    public:
        Circuit();
        ~Circuit();

        nts::IComponent *operator[](const std::string &name);
        void AddComponent(const std::string &type, const std::string &name);

        void simulate(std::size_t tick);
        nts::Tristate compute(std::size_t pin);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        void dump() const;
    private:
        std::map<std::string, uComp> _components;
        Builder builder;
};

#endif /* !CIRCUIT_HPP_ */
