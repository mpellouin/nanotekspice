/*
** EPITECH PROJECT, 2022
** nts
** File description:
** C4512
*/

#ifndef C4512_HPP_
#define C4512_HPP_

#include "BaseComp.hpp"

class C4512 : public BaseComp{
    public:
        C4512(std::string const &name, std::size_t nbPin);
        ~C4512();

        void selectInput();
        void simulate(std::size_t tick);
        nts::Tristate compute(std::size_t pin);
    protected:
    private:
};

#endif /* !C4512_HPP_ */
