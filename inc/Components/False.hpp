/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** False
*/

#ifndef FALSE_HPP_
#define FALSE_HPP_

#include "BaseComp.hpp"

class False : public BaseComp {
    public:
        False(std::string const &name, std::size_t nbPin);
        ~False();
};

#endif /* !FALSE_HPP_ */
