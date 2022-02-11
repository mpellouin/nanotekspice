/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** Output
*/

#ifndef OUTPUT_HPP_
#define OUTPUT_HPP_

#include "BaseComp.hpp"

class Output : public BaseComp {
    public:
        Output(std::string const &name, std::size_t nbPin);
        ~Output();

        void simulate(std::size_t tick);
};

#endif /* !OUTPUT_HPP_ */
