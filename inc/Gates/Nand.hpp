/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** Nand
*/

#ifndef NAND_HPP_
#define NAND_HPP_

#include "BaseComp.hpp"

class Nand : public BaseComp {
    public:
        Nand(const std::string &name, std::size_t nbPin);
        ~Nand();

        void simulate(std::size_t tick);
        nts::Tristate compute(std::size_t pin);
};

#endif /* !NAND_HPP_ */
