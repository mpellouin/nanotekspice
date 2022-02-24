/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** test_4040_counter
*/

#include <criterion/criterion.h>
#include "Circuit.hpp"

Test(Circuit, C4040_component)
{
    Circuit grid;
    grid.AddComponent("4040", "counter");
    grid.AddComponent("input", "in1");
    grid.AddComponent("clock", "cl");
    grid.AddComponent("output", "out1");
    grid.AddComponent("output", "out2");
    grid.AddComponent("output", "out3");
    grid.AddComponent("output", "out4");

    grid.setLink(10, "counter", 1, "cl");
    grid.setLink(11, "counter", 1, "in1");
    grid.setLink(9, "counter", 1, "out1");
    grid.setLink(7, "counter", 1, "out2");
    grid.setLink(6, "counter", 1, "out3");
    grid.setLink(5, "counter", 1, "out4");

    dynamic_cast<Input *>(grid["cl"])->setValue(nts::TRUE);
    grid.simulate(1);
    cr_assert_eq(grid["out1"]->compute(1), nts::UNDEFINED);

    grid.simulate(1);
    cr_assert_eq(grid["out1"]->compute(1), nts::UNDEFINED);

    dynamic_cast<Input *>(grid["in1"])->setValue(nts::TRUE);
    grid.simulate(1);
    cr_assert_eq(grid["counter"]->compute(1), nts::FALSE);

    dynamic_cast<Input *>(grid["in1"])->setValue(nts::FALSE);
    grid.simulate(1);
    grid.simulate(1);
    grid.simulate(1);
    cr_assert_eq(grid["out1"]->compute(1), nts::TRUE);

    try {
        grid["counter"]->compute(19);
    } catch(const std::exception& e) {
        cr_assert_str_eq(e.what(), "C4040: Pin not found");
    }
}
