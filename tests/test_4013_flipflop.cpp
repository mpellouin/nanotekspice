/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** test_4040_counter
*/

#include <criterion/criterion.h>
#include "Circuit.hpp"

Test(Circuit, C4013_component)
{
    Circuit grid;
    grid.AddComponent("input", "reset");
    grid.AddComponent("input", "data");
    grid.AddComponent("input", "set");
    grid.AddComponent("clock", "cl");
    grid.AddComponent("output", "out1");
    grid.AddComponent("output", "out2");
    grid.AddComponent("4013", "door");

    grid.setLink(1, "cl", 3, "door");
    grid.setLink(1, "reset", 4, "door");
    grid.setLink(1, "data", 5, "door");
    grid.setLink(1, "set", 6, "door");
    grid.setLink(1, "out1", 1, "door");
    grid.setLink(1, "out2", 2, "door");

    grid.simulate(1);
    cr_assert_eq(grid["out1"]->compute(1), nts::UNDEFINED);


    // dynamic_cast<Input *>(grid["cl"])->setValue(nts::TRUE);
    // grid.simulate(1);
    // cr_assert_eq(grid["out1"]->compute(1), nts::FALSE);
    // cr_assert_eq(grid["out2"]->compute(1), nts::TRUE);
    // grid["door"]->compute(1);
    // grid["door"]->compute(2);
    // grid["door"]->compute(13);
    // grid["door"]->compute(12);

    // grid.simulate(1);
    // grid.simulate(1);
    // cr_assert_eq(grid["out1"]->compute(1), nts::FALSE);
    // cr_assert_eq(grid["out2"]->compute(1), nts::TRUE);

    // dynamic_cast<Input *>(grid["data"])->setValue(nts::TRUE);
    // grid.simulate(1);
    // grid.simulate(1);
    // cr_assert_eq(grid["out1"]->compute(1), nts::TRUE);
    // cr_assert_eq(grid["out2"]->compute(1), nts::FALSE);

    // dynamic_cast<Input *>(grid["data"])->setValue(nts::FALSE);
    // dynamic_cast<Input *>(grid["reset"])->setValue(nts::TRUE);
    // grid.simulate(1);
    // grid.simulate(1);
    // cr_assert_eq(grid["out1"]->compute(1), nts::FALSE);
    // cr_assert_eq(grid["out2"]->compute(1), nts::TRUE);

    // dynamic_cast<Input *>(grid["set"])->setValue(nts::TRUE);
    // grid.simulate(1);
    // grid.simulate(1);
    // cr_assert_eq(grid["out1"]->compute(1), nts::TRUE);
    // cr_assert_eq(grid["out2"]->compute(1), nts::TRUE);

    // dynamic_cast<Input *>(grid["reset"])->setValue(nts::FALSE);
    // grid.simulate(1);
    // grid.simulate(1);
    // cr_assert_eq(grid["out1"]->compute(1), nts::TRUE);
    // cr_assert_eq(grid["out2"]->compute(1), nts::FALSE);

    try {
        grid["door"]->compute(19);
    } catch(const std::exception& e) {
        cr_assert_str_eq(e.what(), "C4013: Pin not found");
    }
}
