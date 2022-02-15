/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** True
*/

#ifndef TRUE_HPP_
#define TRUE_HPP_

#include "BaseComp.hpp"

class True : public BaseComp {
    public:
        True(std::string const &name, std::size_t nbPin);
        ~True();
};

#endif /* !TRUE_HPP_ */
