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

        void dump() const;
    private:
        std::string _name;
        nts::Tristate _value;
};

#endif /* !INPUT_HPP_ */
