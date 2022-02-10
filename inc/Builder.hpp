/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** Builder
*/

#ifndef BUILDER_HPP_
#define BUILDER_HPP_

#include "IComponent.hpp"
#include "Input.hpp"
#include "Output.hpp"
#include "Clock.hpp"
#include "And.hpp"
#include "Or.hpp"
#include "Not.hpp"
#include "Nand.hpp"

class Builder;
using builderFunc = uComp (Builder::*)(std::string const &value);

class Builder {
    public:
        Builder();
        ~Builder();
        uComp createComponent(const std::string &type, const std::string &name);
        static class Error : public std::exception {
            public:
                Error(const std::string &message) {this->message = new std::string(message);};
                ~Error() {delete this->message;};
                const char *what() const noexcept override;
            private:
                std::string *message;
        } err;
    private:
        std::unordered_map<std::string, builderFunc> _builders;
        uComp createInput(std::string const &name);
        uComp createOutput(std::string const &name);
        uComp createClock(std::string const &name);
        uComp createAnd(std::string const &name);
        uComp createOr(std::string const &name);
        uComp createNot(std::string const &name);
        uComp createNand(std::string const &name);
};

#endif /* !BUILDER_HPP_ */
