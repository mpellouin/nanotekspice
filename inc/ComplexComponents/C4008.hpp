/*
** EPITECH PROJECT, 2022
** nts
** File description:
** C4008
*/

#ifndef C4008_HPP_
#define C4008_HPP_

#include "BaseComp.hpp"

class C4008 : public BaseComp{
    public:
        C4008(std::string const &name, std::size_t nbPin);
        ~C4008();

        void addInputs();
        nts::Tristate getAddedValue(nts::Tristate A, nts::Tristate B, nts::Tristate C);
        nts::Tristate getAddedValue(nts::Tristate A, nts::Tristate B, int C);
        nts::Tristate getCarryOut(nts::Tristate A, nts::Tristate B, nts::Tristate C);
        nts::Tristate getCarryOut(nts::Tristate A, nts::Tristate B, int C);
        void setAllPins(nts::Tristate state);
        void simulate(std::size_t tick);
        nts::Tristate compute(std::size_t pin);
    protected:
    private:
};

#endif /* !C4008_HPP_ */
