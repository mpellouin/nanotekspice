/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** Input
*/

#ifndef INPUT_HPP_
#define INPUT_HPP_

#include "IComponent.hpp"

class Input : public nts::IComponent {
    public:
        Input(std::string const &name);
        ~Input();

        void simulate(std::size_t tick);
        nts::Tristate compute(std::size_t pin);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        void dump() const;

        bool setValue(nts::Tristate value);
    protected:
        std::string _name;
        std::map<std::size_t, nts::Tristate> _pins;
        std::map<std::size_t, nts::Tristate> _newPins;
        std::map<std::size_t, nts::Link> _link;
};

#endif /* !INPUT_HPP_ */
