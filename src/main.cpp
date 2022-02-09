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

/**
 * @brief Prints the program usage to the standard output.
 * 
 */
void printUsage(void)
{
    std::cout << "Usage: ./nts [filepath.nts]" << std::endl
    << "filepath:\t Path to your config file. Must be written in the .nts format." << std::endl;
}

int main(int ac, char **av)
{
    Shell shell;

    if (ac != 2) {
        std::cout << "Invalid number of argument." << std::endl;
        return 84;
    }
    if (ac == 2 && !std::string(av[1]).compare("-h")) {
        printUsage();
        return 0;
    }
    //! Parse initial file in a try catcht
    while (!shell.isEofReached()) {
        std::cout << "> ";
        shell.getInputFromUser();
        try {
            shell.executeCommand();
        } catch (const std::exception &err) {
            std::cout << err.what() << std::endl;
            return 84;
        }
    }

    // Builder builder;
    // uComp temp1 = builder.createComponent("input", "enter1");
    // uComp temp2 = builder.createComponent("output", "end1");
    // uComp temp3 = builder.createComponent("clock", "timer1");

    // temp1.get()->dump();
    // temp2.get()->dump();
    // temp3.get()->dump();

    // Input *dyn_temp = dynamic_cast<Input *>(temp3.get());
    // dyn_temp->setValue(nts::TRUE);
    // temp3.get()->simulate(1);

    // temp1.get()->dump();
    // temp2.get()->dump();
    // temp3.get()->dump();
    return 0;
}
