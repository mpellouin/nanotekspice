/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** Builder
*/

#ifndef BUILDER_HPP_
#define BUILDER_HPP_

#include "IComponent.hpp"

class Builder;
using builderFunc = uComp (Builder::*)(std::string const &);

class Builder {
    public:
        Builder();
        ~Builder();
        uComp createComponent(const std::string &type);
    private:
        std::unordered_map<std::string, builderFunc> _builders;
        uComp createInput();
        uComp createOutput();
        uComp create4001();
};

#endif /* !BUILDER_HPP_ */
