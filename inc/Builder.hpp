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

class Builder;
using builderFunc = uComp (Builder::*)(std::string const &value);

class Builder {
    public:
        Builder();
        ~Builder();
        uComp createComponent(const std::string &type, const std::string &name);
    private:
        std::unordered_map<std::string, builderFunc> _builders;
        uComp createInput(std::string const &name);
        uComp createOutput(std::string const &name);
};

#endif /* !BUILDER_HPP_ */
