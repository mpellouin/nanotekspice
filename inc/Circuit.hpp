/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** Circuit
*/

#ifndef CIRCUIT_HPP_
#define CIRCUIT_HPP_

#include "Builder.hpp"

class Circuit : public BaseComp {
    public:
        Circuit();
        Circuit(std::string const &name, std::size_t nbPin);
        ~Circuit();

        nts::IComponent *operator[](const std::string &name);
        void AddComponent(const std::string &type, const std::string &name);

        void simulate(std::size_t tick);
        nts::Tristate compute(std::size_t pin);
        void setLink(std::size_t pin1, const std::string &comp1, std::size_t pin2, const std::string &comp2);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        void dump() const;

        static class Error : public std::exception {
            public:
                Error(const std::string &message) {this->message = new std::string(message);};
                ~Error() {delete this->message;};
                const char *what() const noexcept override;
            private:
                std::string *message;
        } err;
        bool isExiting = false;
    private:
        std::map<std::string, uComp> _components;
        Builder builder;
};

#endif /* !CIRCUIT_HPP_ */
