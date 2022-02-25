/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** C4801
*/

#include "C4801.hpp"

C4801::C4801(std::string const &name, std::size_t nbPin = 24) : BaseComp(name, nbPin)
{
    _type = "4801";
    _inPins = std::vector<int> {1, 2, 3, 4, 5, 6, 7, 8, 18, 20, 21, 22, 23};
    _outPins = std::vector<int> {};
    _ioPins = std::vector<int> {9, 10, 11, 13, 14, 15, 16, 17};
    _readMode = false;
}

C4801::~C4801()
{
}

void C4801::clearPins(void)
{
    for (std::size_t i = 0; i < _ioPins.size(); i++) {
        _pins[_ioPins.at(i)] = nts::UNDEFINED;
    }
}

void C4801::fillMemory()
{
    simulate(0);
    for (std::size_t i = 0; i < _ioPins.size(); i++) {
        if (_links[_ioPins.at(i)].component != nullptr) {
            _pins[_ioPins.at(i)] = _links[_ioPins.at(i)].component->compute(_links[_ioPins.at(i)].pin);
        } else {
            _pins[_ioPins.at(i)] = nts::FALSE;
        }
    }
    std::bitset<10> address;
    address[0] = _pins[8] == nts::TRUE ? 1 : 0;
    address[1] = _pins[7] == nts::TRUE ? 1 : 0;
    address[2] = _pins[6] == nts::TRUE ? 1 : 0;
    address[3] = _pins[5] == nts::TRUE ? 1 : 0;
    address[4] = _pins[4] == nts::TRUE ? 1 : 0;
    address[5] = _pins[3] == nts::TRUE ? 1 : 0;
    address[6] = _pins[2] == nts::TRUE ? 1 : 0;
    address[7] = _pins[1] == nts::TRUE ? 1 : 0;
    address[8] = _pins[23] == nts::TRUE ? 1 : 0;
    address[9] = _pins[22] == nts::TRUE ? 1 : 0;
    std::bitset<8> data;
    data[0] = _pins[9] == nts::TRUE ? 1 : 0;
    data[1] = _pins[10] == nts::TRUE ? 1 : 0;
    data[2] = _pins[11] == nts::TRUE ? 1 : 0;
    data[3] = _pins[13] == nts::TRUE ? 1 : 0;
    data[4] = _pins[14] == nts::TRUE ? 1 : 0;
    data[5] = _pins[15] == nts::TRUE ? 1 : 0;
    data[6] = _pins[16] == nts::TRUE ? 1 : 0;
    data[7] = _pins[17] == nts::TRUE ? 1 : 0;
    _memory[address.to_ulong()] = data;
    std::cout << "C4801: W address = " << address << "\tData = " << data << std::endl;

}

void C4801::readMemory()
{
    simulate(0);
    std::bitset<10> address;
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
    std::bitset<8> data = _memory[address.to_ulong()];
    std::cout << "C4801: R address = " << address << "\tData = " << data << std::endl;
    _pins[9] = data[0] == 1 ? nts::TRUE : nts::FALSE;
    _pins[10] = data[1] == 1 ? nts::TRUE : nts::FALSE;
    _pins[12] = data[2] == 1 ? nts::TRUE : nts::FALSE;
    _pins[13] = data[3] == 1 ? nts::TRUE : nts::FALSE;
    _pins[14] = data[4] == 1 ? nts::TRUE : nts::FALSE;
    _pins[15] = data[5] == 1 ? nts::TRUE : nts::FALSE;
    _pins[16] = data[6] == 1 ? nts::TRUE : nts::FALSE;
    _pins[17] = data[7] == 1 ? nts::TRUE : nts::FALSE;
}

void C4801::simulate(std::size_t tick)
{
    (void)tick;
    for (std::size_t i = 0; i < _inPins.size(); i++) {
        if (_links[_inPins.at(i)].component != nullptr) {
            compute(_inPins.at(i));
        } else {
            _pins[_inPins.at(i)] = nts::FALSE;
        }
    }
}

nts::Tristate C4801::compute(std::size_t pin)
{

    if (std::find(_inPins.begin(), _inPins.end(), pin) != _inPins.end()) {
        if (_links[pin].component != nullptr) {
            _pins[pin] = _links[pin].component->compute(_links[pin].pin);
        }
        return _pins[pin];
    }
    if (compute(18) == nts::TRUE) {
        std::cout << "C4801: Component disabled" << std::endl;
        clearPins();
        return _pins[pin];
    } else if (!_isUpdated) {
        _isUpdated = true;
        std::cout << "C4801: Component enabled" << std::endl;
        if (compute(21) == nts::TRUE) {
            std::cout << "C4081: Component READ mode" << std::endl;
            _readMode = true;
            readMemory();
        } else {
            std::cout << "C4081: Component WRITE mode" << std::endl;
            _readMode = false;
            fillMemory();
        }
        return _pins[pin];
    }
    if (_readMode) {
        if (std::find(_ioPins.begin(), _ioPins.end(), pin) != _ioPins.end()) {
            return _pins[pin];
        }
    }
    return nts::UNDEFINED;
}
