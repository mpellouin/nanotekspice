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
        nts::Tristate compute(std::size_t pin);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        void dump() const;

    private:
        std::string _name;
        std::map<std::size_t, nts::Tristate> _pins;
        std::map<std::size_t, nts::Link> _link;
};

#endif /* !OUTPUT_HPP_ */
