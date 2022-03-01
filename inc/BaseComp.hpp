/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** BaseComp
*/

#ifndef BASECOMP_HPP_
#define BASECOMP_HPP_

#include "IComponent.hpp"

class BaseComp : public nts::IComponent {
    public:
        BaseComp(const std::string &name, std::size_t nbPin);
        ~BaseComp();

        void simulate(std::size_t tick);
        nts::Tristate compute(std::size_t pin);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        void dump() const;
        bool _isUpdated;
        std::unordered_map<int, bool> _computedOutPins;

    protected:
        std::string _name;
        std::string _type = "";
        std::size_t _nbPin;
        std::vector<int> _inPins;
        std::vector<int> _outPins;
        std::map<std::size_t, nts::Tristate> _pins;
        std::map<std::size_t, nts::Tristate> _newPins;
        std::map<std::size_t, nts::Link> _links;

    public:
        static class Error : public std::exception {
            public:
                Error(const std::string &message) {this->message = new std::string(message);};
                ~Error() {delete this->message;};
                const char *what() const noexcept override;
            private:
                std::string *message;
        } err;
};

#endif /* !BASECOMP_HPP_ */
