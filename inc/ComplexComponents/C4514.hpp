/*
** EPITECH PROJECT, 2022
** nts
** File description:
** C4514
*/

#ifndef C4514_HPP_
#define C4514_HPP_

#include "BaseComp.hpp"

class C4514 : public BaseComp{
    public:
        C4514(std::string const &name, std::size_t nbPin);
        ~C4514();

        void selectInput();
        void setAllPins(nts::Tristate state);
        void simulate(std::size_t tick);
        nts::Tristate compute(std::size_t pin);
    protected:
    private:
        std::vector<nts::Tristate> _inputStates;
        std::vector<nts::Tristate> _prevStates;
};

#endif /* !C4514_HPP_ */
