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
        bool setValue(nts::Tristate value);
        void dump() const;
    protected:
        std::string _name;
        std::map<std::size_t, nts::Tristate> _pins;
};

#endif /* !INPUT_HPP_ */
