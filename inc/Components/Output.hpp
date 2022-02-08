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
        Output(std::string const &name);
        ~Output();

        void simulate(std::size_t tick);
        bool setValue(nts::Tristate value);
        void dump() const;
    private:
        std::string _name;
        std::map<std::size_t, nts::Tristate> _pins;
};

#endif /* !OUTPUT_HPP_ */
