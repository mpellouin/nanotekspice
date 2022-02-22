/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** C2716
*/

#include "C2716.hpp"
#include <bitset>

C2716::C2716(std::string const &name, std::size_t nbPin = 24) : BaseComp(name, nbPin)
{
    _inPins = std::vector<int> {1, 2, 3, 4, 5, 6, 7, 8, 18, 19, 20, 22, 23};
    _outPins = std::vector<int> {9, 10, 11, 13, 14, 15, 16, 17};
    fillMemory();
    // dumpMemory();
}

C2716::~C2716()
{
}

void C2716::fillMemory(void)
{
    std::ifstream rom;
    rom.open("./rom.bin", std::ios::in | std::ios::binary | std::ios::ate);
    if (rom.is_open()) {
        std::size_t size = rom.tellg();
        rom.seekg(0, std::ios::beg);
        std::vector<char> buffer(size);
        rom.read(buffer.data(), size);
        for (std::size_t i = 0; i < size; i++) {
            _memory[i] = std::bitset<8>(buffer[i]);
        }
        rom.close();
    }
}

void C2716::dumpMemory(void)
{
    for (std::size_t i = 0; i < _memory.size(); i++) {
        std::cout << "Memory[" << i << "] = " << _memory[i] << " = " << static_cast<char>(_memory[i].to_ulong()) << std::endl;
    }
}

void C2716::simulate(std::size_t tick)
{
    (void)tick;
    for (std::size_t i = 0; i < _inPins.size(); i++) {
        if (_links[_inPins.at(i)].component != nullptr) {
            _pins[_inPins.at(i)] = _links[_inPins.at(i)].component->compute(_links[_inPins.at(i)].pin);
        } else {
            _pins[_inPins.at(i)] = nts::FALSE;
        }
    }
    std::bitset<11> address;
    address[0] = _pins[8];
    address[1] = _pins[7];
    address[2] = _pins[6];
    address[3] = _pins[5];
    address[4] = _pins[4];
    address[5] = _pins[3];
    address[6] = _pins[2];
    address[7] = _pins[1];
    address[8] = _pins[23];
    address[9] = _pins[22];
    address[10] = _pins[19];
    _pins[9] = _memory[address.to_ulong()][0] ? nts::TRUE : nts::FALSE;
    _pins[10] = _memory[address.to_ulong()][1] ? nts::TRUE : nts::FALSE;
    _pins[11] = _memory[address.to_ulong()][2] ? nts::TRUE : nts::FALSE;
    _pins[13] = _memory[address.to_ulong()][3] ? nts::TRUE : nts::FALSE;
    _pins[14] = _memory[address.to_ulong()][4] ? nts::TRUE : nts::FALSE;
    _pins[15] = _memory[address.to_ulong()][5] ? nts::TRUE : nts::FALSE;
    _pins[16] = _memory[address.to_ulong()][6] ? nts::TRUE : nts::FALSE;
    _pins[17] = _memory[address.to_ulong()][7] ? nts::TRUE : nts::FALSE;
}

nts::Tristate C2716::compute(std::size_t pin)
{
    if (std::find(_inPins.begin(), _inPins.end(), pin) != _inPins.end()) {
        if (_links[pin].component != nullptr) {
            _pins[pin] = _links[pin].component->compute(_links[pin].pin);
            return _pins[pin];
        }
    } else if (std::find(_outPins.begin(), _outPins.end(), pin) != _outPins.end()) {
        if (compute(18) == nts::FALSE && compute(20) == nts::FALSE) {
            // _isUpdated = true;
            simulate(0);
            return _pins[pin];
        }
        return _pins[pin];
    } else {
        throw Error("C2716: Pin not found");
    }
    return nts::UNDEFINED;
}
