/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** Factory
*/

#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include "IComponent.hpp"
#include "Input.hpp"
#include "Output.hpp"
#include "Clock.hpp"
#include "And.hpp"
#include "Or.hpp"
#include "Not.hpp"
#include "Nand.hpp"
#include "Nor.hpp"
#include "Xor.hpp"
#include "True.hpp"
#include "False.hpp"
#include "FlipFlop.hpp"
#include "C4069.hpp"
#include "C4040.hpp"
#include "C4512.hpp"
#include "C4013.hpp"
#include "C4514.hpp"
#include "Logger.hpp"
#include "C2716.hpp"
#include "C4008.hpp"
#include "C4801.hpp"
#include "C4017.hpp"
#include "LogicalComponent.hpp"

class Factory;
using factoryFunc = uComp (Factory::*)(std::string const &value);

class Factory {
    public:
        Factory();
        ~Factory();
        uComp createComponent(const std::string &type, const std::string &name);
        static class Error : public std::exception {
            public:
                Error(const std::string &message) {this->message = std::string(message);};
                ~Error() {};
                const char *what() const noexcept override;
            private:
                std::string message;
        } err;
    private:
        std::unordered_map<std::string, factoryFunc> _factories;
        uComp createLogger(std::string const &name);
        uComp createInput(std::string const &name);
        uComp createOutput(std::string const &name);
        uComp createTrue(std::string const &name);
        uComp createFalse(std::string const &name);
        uComp createClock(std::string const &name);
        uComp createFlipFlop(std::string const &name);
        uComp createAnd(std::string const &name);
        uComp createC4081(std::string const &name);
        uComp createOr(std::string const &name);
        uComp createC4071(std::string const &name);
        uComp createNot(std::string const &name);
        uComp createC4069(std::string const &name);
        uComp createNand(std::string const &name);
        uComp createC4011(std::string const &name);
        uComp createNor(std::string const &name);
        uComp createC4001(std::string const &name);
        uComp createXor(std::string const &name);
        uComp createC4030(std::string const &name);
        uComp createC4040(std::string const &name);
        uComp createC4512(std::string const &name);
        uComp createC4013(std::string const &name);
        uComp createC4514(std::string const &name);
        uComp createC2716(std::string const &name);
        uComp createC4008(std::string const &name);
        uComp createC4801(std::string const &name);
        uComp createC4017(std::string const &name);
};

#endif /* !FACTORY_HPP_ */
