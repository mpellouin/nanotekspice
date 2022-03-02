/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** Logger
*/

#ifndef LOGGER_HPP_
#define LOGGER_HPP_

#include "BaseComp.hpp"

class Logger : public BaseComp {
    public:
        Logger(const std::string&name, std::size_t nbPin);
        ~Logger();

        bool isNegligeable(std::size_t pin);
        bool checkUndefined(void);
        char getData(void);
        void LogData(const char value);
        void simulate(std::size_t tick);

};

#endif /* !LOGGER_HPP_ */
