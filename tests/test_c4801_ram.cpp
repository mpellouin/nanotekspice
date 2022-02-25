/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** test_c4801_ram
*/

#include <criterion/criterion.h>
#include "Circuit.hpp"

Test(Circuit, basic_ram_test)
{
    Circuit grid;

    grid.AddComponent("4801", "ram");
    grid.AddComponent("output", "out1");
    grid.AddComponent("output", "out2");
    grid.AddComponent("input", "ram_read");
    grid.AddComponent("input", "ram_write");
    grid.AddComponent("input", "ram_enable");
    grid.AddComponent("input", "reset");
    grid.AddComponent("4040", "counter");
    grid.AddComponent("clock", "cl");

    grid.setLink(1, "ram_read", 20, "ram");
    grid.setLink(1, "ram_write", 21, "ram");
    grid.setLink(1, "ram_enable", 18, "ram");
    grid.setLink(9, "ram", 1, "out1");
    grid.setLink(10, "ram", 1, "out2");
    grid.setLink(1, "reset", 11, "counter");
    grid.setLink(1, "cl", 10, "counter");
    grid.setLink(9, "counter", 8, "ram");
    grid.setLink(7, "counter", 7, "ram");
    grid.setLink(6, "counter", 6, "ram");
    grid.setLink(5, "counter", 5, "ram");
    grid.setLink(3, "counter", 4, "ram");
    grid.setLink(2, "counter", 3, "ram");
    grid.setLink(9, "ram", 9, "counter");
    grid.setLink(10, "ram", 7, "counter");
    grid.setLink(11, "ram", 6, "counter");

    grid.simulate(1);
    dynamic_cast<Input *>(grid["reset"])->setValue(nts::TRUE);
    grid.simulate(1);
    dynamic_cast<Input *>(grid["reset"])->setValue(nts::FALSE);
    grid.simulate(1);
    // dynamic_cast<Input *>(grid["ram_enable"])->setValue(nts::TRUE);
    grid.simulate(1);
    grid.simulate(1);
    // dynamic_cast<Input *>(grid["ram_enable"])->setValue(nts::UNDEFINEDxx);
    grid.simulate(1);
    grid.simulate(1);
    dynamic_cast<Input *>(grid["cl"])->setValue(nts::TRUE);
    grid.simulate(1);
    dynamic_cast<Input *>(grid["reset"])->setValue(nts::TRUE);
    grid.simulate(1);
    dynamic_cast<Input *>(grid["reset"])->setValue(nts::FALSE);
    grid.simulate(1);
    dynamic_cast<Input *>(grid["ram_write"])->setValue(nts::TRUE);
    grid.simulate(1);
    grid["out1"]->compute(1);
}
