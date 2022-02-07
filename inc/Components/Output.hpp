/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** Output
*/

#ifndef OUTPUT_HPP_
#define OUTPUT_HPP_

#include "IComponent.hpp"

class Output : public nts::IComponent {
    public:
        Output();
        ~Output();
    private:
        std::string _name;
        nts::Tristate _value;
};

#endif /* !OUTPUT_HPP_ */
