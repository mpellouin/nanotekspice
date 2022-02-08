/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** Clock
*/

#ifndef CLOCK_HPP_
#define CLOCK_HPP_

#include "Input.hpp"

class Clock : public Input {
    public:
        Clock(std::string const &name);
        ~Clock();

        void simulate(std::size_t tick);
};

#endif /* !CLOCK_HPP_ */
