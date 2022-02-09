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
}

int main(int ac, char **av)
{
    Shell shell;
    Parser parser("test.lol");

    if (ac != 2) {
        std::cout << "Invalid number of argument." << std::endl;
        return 84;
    }
    if (ac == 2 && !std::string(av[1]).compare("-h")) {
        printUsage();
        return 0;
    }
    // try {
    //     while (true) {
    //         parser.getNextLine();
    //         std::cout << "ana" << std::endl;
    //         if (parser.isNewSection()) {
    //             std::cout << "nas" << std::endl;
    //             std::cout << parser.parseLine() << std::endl;
    //         } else
    //         std::cout << parser.parseLine() << " " << parser.parseLine() << std::endl;
    //     }
    // } catch (...) {}
    //! Parse initial file in a try catcht
    //! Same structure from above that probably returns a circuit instead of display
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

    Circuit *grid = new Circuit();

    grid->AddComponent("input", "in1");
    grid->AddComponent("clock", "cl1");
    grid->AddComponent("output", "out1");
    grid->AddComponent("and", "andDoor");

    nts::IComponent *in1 = grid->operator[]("in1");
    nts::IComponent *cl1 = grid->operator[]("cl1");
    nts::IComponent *out1 = grid->operator[]("out1");
    nts::IComponent *andDoor = grid->operator[]("andDoor");
    out1->setLink(1, *grid->operator[]("andDoor"), 3);
    andDoor->setLink(1, *grid->operator[]("in1"), 1);
    andDoor->setLink(2, *grid->operator[]("cl1"), 1);


    Input *dyn_in1 = dynamic_cast<Input *>(in1);
    dyn_in1->setValue(nts::TRUE);
    Input *dyn_cl1 = dynamic_cast<Input *>(cl1);
    dyn_cl1->setValue(nts::FALSE);

    grid->dump();

    in1->simulate(1);
    cl1->simulate(1);
    andDoor->simulate(1);
    out1->simulate(1);

    grid->dump();

    in1->simulate(1);
    cl1->simulate(1);
    andDoor->simulate(1);
    out1->simulate(1);

    grid->dump();

    in1->simulate(1);
    cl1->simulate(1);
    andDoor->simulate(1);
    out1->simulate(1);

    grid->dump();
    return 0;
}
