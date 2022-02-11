/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** newAnd
*/

#ifndef NEWAND_HPP_
#define NEWAND_HPP_

#include "BaseComp.hpp"

class newAnd : public BaseComp{
    public:
        newAnd(const std::string &name, std::size_t nbPin);
        ~newAnd();

        void simulate(std::size_t tick);
};




#endif /* !NEWAND_HPP_ */
