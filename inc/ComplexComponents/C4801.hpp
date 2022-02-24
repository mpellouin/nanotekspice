/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** C4801
*/

#ifndef C4801_HPP_
#define C4801_HPP_

#include "BaseComp.hpp"

class C4801 : public BaseComp {
    public:
        C4801(std::string const &name, std::size_t nbPin);
        ~C4801();

        void clearPins(void);
        void fillMemory(void);
        void readMemory(void);
        void simulate(std::size_t tick);
        nts::Tristate compute(std::size_t pin);
    private:
        std::map<std::size_t, std::bitset<8>> _memory;
        std::vector<int> _ioPins;
        bool _readMode;
};

#endif /* !C4801_HPP_ */
