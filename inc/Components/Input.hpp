/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** Input
*/

#ifndef INPUT_HPP_
#define INPUT_HPP_

#include "BaseComp.hpp"

class Input : public BaseComp {
    public:
        Input(std::string const &name, std::size_t nbPin);
        ~Input();

        void simulate(std::size_t tick);
        bool setValue(nts::Tristate value);
};

#endif /* !INPUT_HPP_ */
