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

#include "Circuit.hpp"

void printUsage(void)
{
    std::cout << "Usage: ./nts [filepath.nts]" << std::endl;
    std::cout << "filepath:\t Path to your config file. Must be written in the .nts format." << std::endl;
}

int main(int ac, char **av)
{
    // if (ac != 2) {
    //     std::cout << "Invalid number of argument." << std::endl;
    //     return 84;
    // }
    // if (ac == 2 && !std::string(av[1]).compare("-h")) {
    //     printUsage();
    //     return 0;
    // }

    // Builder builder;
    // uComp temp1 = builder.createComponent("input", "enter1");
    // uComp temp2 = builder.createComponent("clock", "timer1");
    // uComp temp3 = builder.createComponent("output", "ENTER 1");
    // uComp temp4 = builder.createComponent("output", "TIMER 1");

    // temp1.get()->dump();
    // temp2.get()->dump();
    // temp3.get()->dump();
    // temp4.get()->dump();

    // temp3.get()->setLink(1, *temp1.get(), 1);
    // temp4.get()->setLink(1, *temp2.get(), 1);
    // Input *dyn_temp = dynamic_cast<Input *>(temp1.get());
    // dyn_temp->setValue(nts::TRUE);
    // Input *dyn_temp2 = dynamic_cast<Input *>(temp2.get());
    // dyn_temp2->setValue(nts::FALSE);

    // for (int i = 0; i < 8; i++) {
    //     std::cout << "-------------------" << std::endl;
    //     temp1.get()->simulate(i);
    //     temp2.get()->simulate(i);
    //     temp3.get()->simulate(i);
    //     temp4.get()->simulate(i);
    //     temp1.get()->dump();
    //     temp2.get()->dump();
    //     temp3.get()->dump();
    //     temp4.get()->dump();
    // }
    Circuit *grid = new Circuit();

    grid->AddComponent("input", "in1");
    grid->AddComponent("clock", "cl1");
    grid->AddComponent("output", "out1");
    grid->AddComponent("and", "andDoor");

    nts::IComponent *in1 = grid->operator[]("in1");
    nts::IComponent *cl1 = grid->operator[]("cl1");
    nts::IComponent *out1 = grid->operator[]("out1");
    nts::IComponent *andDoor = grid->operator[]("andDoor");

    Input *dyn_in1 = dynamic_cast<Input *>(in1);
    dyn_in1->setValue(nts::TRUE);
    Input *dyn_cl1 = dynamic_cast<Input *>(cl1);
    dyn_cl1->setValue(nts::FALSE);

    out1->setLink(1, *grid->operator[]("andDoor"), 3);
    andDoor->setLink(1, *grid->operator[]("in1"), 1);
    andDoor->setLink(2, *grid->operator[]("cl1"), 1);

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
