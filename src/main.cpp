/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** main
*/

#include <string>
#include <stdexcept>
#include <iostream>
#include <memory>

#include "IComponent.hpp"

void printUsage(void)
{
    std::cout << "Usage: ./nts [filepath.nts]" << std::endl
    << "filepath:\t Path to your config file. Must be written in .nts format." << std::endl;
}

int main(int ac, char **av)
{
    if (ac != 2) throw std::invalid_argument("NTS needs a filepath to run properly. Use ./nts -h to get more infos.");
    if (ac == 2 && !std::string(av[1]).compare("-h")) {
        printUsage();
        return 0;
    }
    return 84;
}
