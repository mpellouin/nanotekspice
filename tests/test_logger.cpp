/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** test_logger
*/

#include <criterion/criterion.h>
#include "Circuit.hpp"

Test(Circuit, test_logger_and_rom_simultaneously)
{
    Circuit grid;

    grid.AddComponent("input", "reset");
    grid.AddComponent("false", "enable");
    grid.AddComponent("false", "read");
    grid.AddComponent("input", "inhibit");
    grid.AddComponent("clock", "cl");
    grid.AddComponent("4040", "counter");
    grid.AddComponent("2716", "rom");
    grid.AddComponent("logger", "logger");

    grid.setLink(1, "reset", 11, "counter");
    grid.setLink(1, "cl", 10, "counter");
    grid.setLink(1, "enable", 18, "rom");
    grid.setLink(1, "read", 20, "rom");
    grid.setLink(1, "cl", 9, "logger");
    grid.setLink(1, "inhibit", 10, "logger");
    grid.setLink(9, "counter", 8, "rom");
    grid.setLink(7, "counter", 7, "rom");
    grid.setLink(6, "counter", 6, "rom");
    grid.setLink(5, "counter", 5, "rom");
    grid.setLink(3, "counter", 4, "rom");
    grid.setLink(2, "counter", 3, "rom");
    grid.setLink(4, "counter", 2, "rom");
    grid.setLink(13, "counter", 1, "rom");
    grid.setLink(12, "counter", 23, "rom");
    grid.setLink(14, "counter", 22, "rom");

    grid.setLink(9, "rom", 1, "logger");
    grid.setLink(10, "rom", 2, "logger");
    grid.setLink(11, "rom", 3, "logger");
    grid.setLink(13, "rom", 4, "logger");
    grid.setLink(14, "rom", 5, "logger");
    grid.setLink(15, "rom", 6, "logger");
    grid.setLink(16, "rom", 7, "logger");
    grid.setLink(17, "rom", 8, "logger");


    dynamic_cast<Input *>(grid["cl"])->setValue(nts::TRUE);
    dynamic_cast<Input *>(grid["reset"])->setValue(nts::TRUE);
    grid.simulate(1);
    dynamic_cast<Input *>(grid["reset"])->setValue(nts::FALSE);
    grid.simulate(1);

    for (int i = 0; i < 27; i++) {
        grid.simulate(1);

    }

    try {
        grid["rom"]->compute(29);
    } catch(const std::exception& e) {
        cr_assert_str_eq(e.what(), "C2716: Pin not found");
    }

}
