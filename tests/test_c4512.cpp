/*
** EPITECH PROJECT, 2022
** nts
** File description:
** test_c4512
*/

#include "criterion/criterion.h"
#include "Circuit.hpp"

Test(Circuit, Circuit_4512_Gate)
{
    Circuit grid;
    grid.AddComponent("input", "A");
    grid.AddComponent("input", "B");
    grid.AddComponent("input", "C");
    grid.AddComponent("input", "1");
    grid.AddComponent("input", "2");
    grid.AddComponent("input", "3");
    grid.AddComponent("input", "4");
    grid.AddComponent("input", "5");
    grid.AddComponent("input", "6");
    grid.AddComponent("input", "7");
    grid.AddComponent("input", "8");
    grid.AddComponent("input", "OE");
    grid.AddComponent("input", "inh");
    grid.AddComponent("4512", "sel");
    grid.AddComponent("output", "out");

    grid.setLink(1, "1", 1, "sel");
    grid.setLink(1, "2", 2, "sel");
    grid.setLink(1, "3", 3, "sel");
    grid.setLink(1, "4", 4, "sel");
    grid.setLink(1, "5", 5, "sel");
    grid.setLink(1, "6", 6, "sel");
    grid.setLink(1, "7", 7, "sel");
    grid.setLink(1, "8", 9, "sel");
    grid.setLink(1, "inh", 10, "sel");
    grid.setLink(1, "OE", 15, "sel");
    grid.setLink(1, "A", 11, "sel");
    grid.setLink(1, "B", 12, "sel");
    grid.setLink(1, "C", 13, "sel");
    grid.setLink(1, "out", 14, "sel");

    dynamic_cast<Input *>(grid["OE"])->setValue(nts::TRUE);
    dynamic_cast<Input *>(grid["inh"])->setValue(nts::TRUE);
    dynamic_cast<Input *>(grid["1"])->setValue(nts::FALSE);
    dynamic_cast<Input *>(grid["2"])->setValue(nts::FALSE);
    dynamic_cast<Input *>(grid["3"])->setValue(nts::FALSE);
    dynamic_cast<Input *>(grid["4"])->setValue(nts::FALSE);
    dynamic_cast<Input *>(grid["5"])->setValue(nts::FALSE);
    dynamic_cast<Input *>(grid["6"])->setValue(nts::FALSE);
    dynamic_cast<Input *>(grid["7"])->setValue(nts::FALSE);
    dynamic_cast<Input *>(grid["8"])->setValue(nts::FALSE);
    dynamic_cast<Input *>(grid["A"])->setValue(nts::FALSE);
    dynamic_cast<Input *>(grid["B"])->setValue(nts::FALSE);
    dynamic_cast<Input *>(grid["C"])->setValue(nts::FALSE);
    grid.simulate(1);
    cr_assert_eq(grid["out"]->compute(1), nts::UNDEFINED);

    dynamic_cast<Input *>(grid["OE"])->setValue(nts::FALSE);
    grid.simulate(1);
    cr_assert_eq(grid["out"]->compute(1), nts::FALSE);

    dynamic_cast<Input *>(grid["inh"])->setValue(nts::FALSE);
    grid.simulate(1);
    cr_assert_eq(grid["out"]->compute(1), nts::FALSE);

    dynamic_cast<Input *>(grid["inh"])->setValue(nts::UNDEFINED);
    grid.simulate(1);
    cr_assert_eq(grid["out"]->compute(1), nts::UNDEFINED);

    dynamic_cast<Input *>(grid["inh"])->setValue(nts::FALSE);
    grid.simulate(1);
    cr_assert_eq(grid["out"]->compute(1), nts::FALSE);

    dynamic_cast<Input *>(grid["1"])->setValue(nts::FALSE);
    dynamic_cast<Input *>(grid["2"])->setValue(nts::TRUE);
    dynamic_cast<Input *>(grid["3"])->setValue(nts::UNDEFINED);
    dynamic_cast<Input *>(grid["4"])->setValue(nts::FALSE);
    dynamic_cast<Input *>(grid["5"])->setValue(nts::TRUE);
    dynamic_cast<Input *>(grid["6"])->setValue(nts::UNDEFINED);
    dynamic_cast<Input *>(grid["7"])->setValue(nts::FALSE);
    dynamic_cast<Input *>(grid["8"])->setValue(nts::TRUE);
    grid.simulate(1);
    cr_assert_eq(grid["out"]->compute(1), nts::FALSE);

    dynamic_cast<Input *>(grid["A"])->setValue(nts::TRUE);
    grid.simulate(1);
    cr_assert_eq(grid["out"]->compute(1), nts::TRUE);

    dynamic_cast<Input *>(grid["A"])->setValue(nts::FALSE);
    dynamic_cast<Input *>(grid["B"])->setValue(nts::TRUE);
    grid.simulate(1);
    cr_assert_eq(grid["out"]->compute(1), nts::UNDEFINED);
    try {
        grid["C"]->compute(18);
    } catch(const std::exception& e) {
        cr_assert_str_eq(e.what(), "BaseComp: Pin not found");
    }
}
