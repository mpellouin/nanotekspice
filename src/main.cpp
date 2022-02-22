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
#include <sstream>

#include "Builder.hpp"
#include "Shell.hpp"
#include "Parser.hpp"
#include "Circuit.hpp"

/**
 * @brief Prints the program usage to the standard output.
 *
 */
void printUsage(void)
{
    std::cout << "Usage: ./nts [filepath.nts]" << std::endl;
    std::cout << "filepath:\t Path to your config file. Must be written in the .nts format." << std::endl;
    exit(0);
}

int main(int ac, char **av)
{
    Shell shell;
    parse::Parser parser;
    Circuit circuit;

    if (ac != 2) {
        std::cout << "Invalid number of argument." << std::endl;
        return 84;
    }
    if (ac == 2 && !std::string(av[1]).compare("-h")) printUsage();
    try {
        parser.openFile(av[1]);
        parser.buildCircuit(circuit);
    } catch (const std::exception &except) {
        if (except.what() != std::string("EOF")) {
            std::cerr << except.what() << std::endl;
            return 84;
        }
    };
    try {
        shell.run(circuit);
    } catch (const std::exception &exception) {
        if (exception.what() == std::string("EOF")) return 0;
        std::cerr << exception.what() << std::endl;
        return 84;
    }

    return 0;
}
