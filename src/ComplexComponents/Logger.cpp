/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** Logger
*/

#include "Logger.hpp"

Logger::Logger(std::string const &name, std::size_t nbPin = 10) : BaseComp(name, nbPin)
{
    _type = "logger";
    _inPins = std::vector<int> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    _outPins = std::vector<int> {};
}

Logger::~Logger()
{
}

bool Logger::isNegligeable(std::size_t pin)
{
    if (_pins[pin] == nts::UNDEFINED || _pins[pin] == nts::FALSE)
        return true;
    return false;
}

char Logger::getData(void)
{
    std::bitset<8> bits;
    bits[0] = _pins[1] == nts::TRUE ? 1 : 0;
    bits[1] = _pins[2] == nts::TRUE ? 1 : 0;
    bits[2] = _pins[3] == nts::TRUE ? 1 : 0;
    bits[3] = _pins[4] == nts::TRUE ? 1 : 0;
    bits[4] = _pins[5] == nts::TRUE ? 1 : 0;
    bits[5] = _pins[6] == nts::TRUE ? 1 : 0;
    bits[6] = _pins[7] == nts::TRUE ? 1 : 0;
    bits[7] = _pins[8] == nts::TRUE ? 1 : 0;
    return static_cast<char>(bits.to_ulong());
}

void Logger::LogData(const char value)
{
    std::ofstream outfile;

    outfile.open("log.bin", std::ios_base::app);
    outfile << value;
    outfile.close();
    return;
}

void Logger::simulate(std::size_t tick)
{
    (void)tick;
    if (_links[10].component != nullptr) {
        if (_links[10].component->compute(_links[10].pin) == nts::TRUE) {
            return;
        }
    }
    for (std::size_t i = 1; i <= 8; i++) {
        if (_links[i].component != nullptr) {
            _pins[i] = _links[i].component->compute(_links[i].pin);
        }
    }
    if (_links[9].component != nullptr && _links[9].component->compute(_links[9].pin) == nts::TRUE && isNegligeable(9)) {
        LogData(getData());
    }
    _pins[9] = _links[9].component->compute(_links[9].pin);
}
