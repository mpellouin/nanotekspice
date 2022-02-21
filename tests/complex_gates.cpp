/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** complex_gates
*/

#include "criterion/criterion.h"
#include "Circuit.hpp"

Test(Circuit, Circuit_4081_Gate)
{
    Circuit grid;
    grid.AddComponent("input", "A");
    grid.AddComponent("input", "B");
    grid.AddComponent("4081", "C");
    grid.AddComponent("output", "D");
    grid.AddComponent("output", "E");
    grid.AddComponent("output", "F");
    grid.AddComponent("output", "G");

    grid.setLink(1, "A", 1, "C");
    grid.setLink(1, "A", 5, "C");
    grid.setLink(1, "A", 8, "C");
    grid.setLink(1, "A", 12, "C");
    grid.setLink(1, "B", 2, "C");
    grid.setLink(1, "B", 6, "C");
    grid.setLink(1, "B", 9, "C");
    grid.setLink(1, "B", 13, "C");
    grid.setLink(3, "C", 1, "D");
    grid.setLink(3, "C", 1, "E");
    grid.setLink(3, "C", 1, "F");
    grid.setLink(3, "C", 1, "G");

    dynamic_cast<Input *>(grid["A"])->setValue(nts::TRUE);
    dynamic_cast<Input *>(grid["B"])->setValue(nts::TRUE);
    grid.simulate(1);
    cr_assert_eq(grid["D"]->compute(1), nts::TRUE);

    dynamic_cast<Input *>(grid["A"])->setValue(nts::FALSE);
    dynamic_cast<Input *>(grid["B"])->setValue(nts::TRUE);
    grid.simulate(1);
    cr_assert_eq(grid["E"]->compute(1), nts::FALSE);

    dynamic_cast<Input *>(grid["A"])->setValue(nts::UNDEFINED);
    dynamic_cast<Input *>(grid["B"])->setValue(nts::TRUE);
    grid.simulate(1);
    cr_assert_eq(grid["F"]->compute(1), nts::UNDEFINED);

    dynamic_cast<Input *>(grid["A"])->setValue(nts::FALSE);
    dynamic_cast<Input *>(grid["B"])->setValue(nts::UNDEFINED);
    grid.simulate(1);
    cr_assert_eq(grid["G"]->compute(1), nts::FALSE);

    try {
        grid["G"]->compute(18);
    } catch(const std::exception& e) {
        cr_assert_str_eq(e.what(), "BaseComp: Pin not found");
    }
}

Test(Circuit, Circuit_4071_Gate)
{
    Circuit grid;
    grid.AddComponent("input", "A");
    grid.AddComponent("input", "B");
    grid.AddComponent("4071", "C");
    grid.AddComponent("output", "D");
    grid.AddComponent("output", "E");
    grid.AddComponent("output", "F");
    grid.AddComponent("output", "G");

    grid.setLink(1, "A", 1, "C");
    grid.setLink(1, "A", 5, "C");
    grid.setLink(1, "A", 8, "C");
    grid.setLink(1, "A", 12, "C");
    grid.setLink(1, "B", 2, "C");
    grid.setLink(1, "B", 6, "C");
    grid.setLink(1, "B", 9, "C");
    grid.setLink(1, "B", 13, "C");
    grid.setLink(3, "C", 1, "D");
    grid.setLink(3, "C", 1, "E");
    grid.setLink(3, "C", 1, "F");
    grid.setLink(3, "C", 1, "G");

    dynamic_cast<Input *>(grid["A"])->setValue(nts::TRUE);
    dynamic_cast<Input *>(grid["B"])->setValue(nts::TRUE);
    grid.simulate(1);
    cr_assert_eq(grid["D"]->compute(1), nts::TRUE);

    dynamic_cast<Input *>(grid["A"])->setValue(nts::FALSE);
    dynamic_cast<Input *>(grid["B"])->setValue(nts::TRUE);
    grid.simulate(1);
    cr_assert_eq(grid["E"]->compute(1), nts::TRUE);

    dynamic_cast<Input *>(grid["A"])->setValue(nts::UNDEFINED);
    dynamic_cast<Input *>(grid["B"])->setValue(nts::TRUE);
    grid.simulate(1);
    cr_assert_eq(grid["F"]->compute(1), nts::TRUE);

    dynamic_cast<Input *>(grid["A"])->setValue(nts::FALSE);
    dynamic_cast<Input *>(grid["B"])->setValue(nts::UNDEFINED);
    grid.simulate(1);
    cr_assert_eq(grid["G"]->compute(1), nts::UNDEFINED);

    try {
        grid["G"]->compute(18);
    } catch(const std::exception& e) {
        cr_assert_str_eq(e.what(), "BaseComp: Pin not found");
    }
}

Test(Circuit, Circuit_4069_Gate)
{
    Circuit grid;
    grid.AddComponent("input", "A");
    grid.AddComponent("input", "B");
    grid.AddComponent("4069", "C");
    grid.AddComponent("output", "D");
    grid.AddComponent("output", "E");
    grid.AddComponent("output", "F");
    grid.AddComponent("output", "G");
    grid.AddComponent("output", "H");
    grid.AddComponent("output", "I");

    grid.setLink(1, "A", 1, "C");
    grid.setLink(1, "A", 3, "C");
    grid.setLink(1, "A", 5, "C");
    grid.setLink(1, "B", 9, "C");
    grid.setLink(1, "B", 11, "C");
    grid.setLink(1, "B", 13, "C");
    grid.setLink(2, "C", 1, "D");
    grid.setLink(4, "C", 1, "E");
    grid.setLink(6, "C", 1, "F");
    grid.setLink(8, "C", 1, "G");
    grid.setLink(10, "C", 1, "H");
    grid.setLink(12, "C", 1, "I");

    dynamic_cast<Input *>(grid["A"])->setValue(nts::TRUE);
    dynamic_cast<Input *>(grid["B"])->setValue(nts::FALSE);
    grid.simulate(1);
    cr_assert_eq(grid["D"]->compute(1), nts::FALSE);
    cr_assert_eq(grid["E"]->compute(1), nts::FALSE);
    cr_assert_eq(grid["F"]->compute(1), nts::FALSE);
    cr_assert_eq(grid["G"]->compute(1), nts::TRUE);
    cr_assert_eq(grid["H"]->compute(1), nts::TRUE);
    cr_assert_eq(grid["I"]->compute(1), nts::TRUE);

    try {
        grid["C"]->compute(18);
    } catch(const std::exception& e) {
        cr_assert_str_eq(e.what(), "C4069: Pin not found");
    }
}

Test(Circuit, Circuit_4030_Gate)
{
    Circuit grid;
    grid.AddComponent("input", "A");
    grid.AddComponent("input", "B");
    grid.AddComponent("4030", "C");
    grid.AddComponent("output", "D");
    grid.AddComponent("output", "E");
    grid.AddComponent("output", "F");
    grid.AddComponent("output", "G");

    grid.setLink(1, "A", 1, "C");
    grid.setLink(1, "A", 5, "C");
    grid.setLink(1, "A", 8, "C");
    grid.setLink(1, "A", 12, "C");
    grid.setLink(1, "B", 2, "C");
    grid.setLink(1, "B", 6, "C");
    grid.setLink(1, "B", 9, "C");
    grid.setLink(1, "B", 13, "C");
    grid.setLink(3, "C", 1, "D");
    grid.setLink(3, "C", 1, "E");
    grid.setLink(3, "C", 1, "F");
    grid.setLink(3, "C", 1, "G");

    dynamic_cast<Input *>(grid["A"])->setValue(nts::TRUE);
    dynamic_cast<Input *>(grid["B"])->setValue(nts::TRUE);
    grid.simulate(1);
    cr_assert_eq(grid["D"]->compute(1), nts::FALSE);

    dynamic_cast<Input *>(grid["A"])->setValue(nts::FALSE);
    dynamic_cast<Input *>(grid["B"])->setValue(nts::FALSE);
    grid.simulate(1);
    cr_assert_eq(grid["E"]->compute(1), nts::FALSE);

    dynamic_cast<Input *>(grid["A"])->setValue(nts::FALSE);
    dynamic_cast<Input *>(grid["B"])->setValue(nts::TRUE);
    grid.simulate(1);
    cr_assert_eq(grid["E"]->compute(1), nts::TRUE);

    dynamic_cast<Input *>(grid["A"])->setValue(nts::UNDEFINED);
    dynamic_cast<Input *>(grid["B"])->setValue(nts::TRUE);
    grid.simulate(1);
    cr_assert_eq(grid["F"]->compute(1), nts::UNDEFINED);

    dynamic_cast<Input *>(grid["A"])->setValue(nts::FALSE);
    dynamic_cast<Input *>(grid["B"])->setValue(nts::UNDEFINED);
    grid.simulate(1);
    cr_assert_eq(grid["G"]->compute(1), nts::UNDEFINED);

    try {
        grid["C"]->compute(18);
    } catch(const std::exception& e) {
        cr_assert_str_eq(e.what(), "C4030: Pin not found");
    }
}

Test(Circuit, Circuit_4001_Gate)
{
    Circuit grid;
    grid.AddComponent("input", "A");
    grid.AddComponent("input", "B");
    grid.AddComponent("4001", "C");
    grid.AddComponent("output", "D");
    grid.AddComponent("output", "E");
    grid.AddComponent("output", "F");
    grid.AddComponent("output", "G");

    grid.setLink(1, "A", 1, "C");
    grid.setLink(1, "A", 5, "C");
    grid.setLink(1, "A", 8, "C");
    grid.setLink(1, "A", 12, "C");
    grid.setLink(1, "B", 2, "C");
    grid.setLink(1, "B", 6, "C");
    grid.setLink(1, "B", 9, "C");
    grid.setLink(1, "B", 13, "C");
    grid.setLink(3, "C", 1, "D");
    grid.setLink(3, "C", 1, "E");
    grid.setLink(3, "C", 1, "F");
    grid.setLink(3, "C", 1, "G");

    dynamic_cast<Input *>(grid["A"])->setValue(nts::TRUE);
    dynamic_cast<Input *>(grid["B"])->setValue(nts::TRUE);
    grid.simulate(1);
    cr_assert_eq(grid["D"]->compute(1), nts::FALSE);

    dynamic_cast<Input *>(grid["A"])->setValue(nts::FALSE);
    dynamic_cast<Input *>(grid["B"])->setValue(nts::FALSE);
    grid.simulate(1);
    cr_assert_eq(grid["E"]->compute(1), nts::TRUE);

    dynamic_cast<Input *>(grid["A"])->setValue(nts::FALSE);
    dynamic_cast<Input *>(grid["B"])->setValue(nts::TRUE);
    grid.simulate(1);
    cr_assert_eq(grid["E"]->compute(1), nts::FALSE);

    dynamic_cast<Input *>(grid["A"])->setValue(nts::UNDEFINED);
    dynamic_cast<Input *>(grid["B"])->setValue(nts::TRUE);
    grid.simulate(1);
    cr_assert_eq(grid["F"]->compute(1), nts::FALSE);

    dynamic_cast<Input *>(grid["A"])->setValue(nts::FALSE);
    dynamic_cast<Input *>(grid["B"])->setValue(nts::UNDEFINED);
    grid.simulate(1);
    cr_assert_eq(grid["G"]->compute(1), nts::UNDEFINED);

    try {
        grid["C"]->compute(18);
    } catch(const std::exception& e) {
        cr_assert_str_eq(e.what(), "C4001: Pin not found");
    }
}

Test(Circuit, Circuit_4011_Gate)
{
    Circuit grid;
    grid.AddComponent("input", "A");
    grid.AddComponent("input", "B");
    grid.AddComponent("4011", "C");
    grid.AddComponent("output", "D");
    grid.AddComponent("output", "E");
    grid.AddComponent("output", "F");
    grid.AddComponent("output", "G");

    grid.setLink(1, "A", 1, "C");
    grid.setLink(1, "A", 5, "C");
    grid.setLink(1, "A", 8, "C");
    grid.setLink(1, "A", 12, "C");
    grid.setLink(1, "B", 2, "C");
    grid.setLink(1, "B", 6, "C");
    grid.setLink(1, "B", 9, "C");
    grid.setLink(1, "B", 13, "C");
    grid.setLink(3, "C", 1, "D");
    grid.setLink(3, "C", 1, "E");
    grid.setLink(3, "C", 1, "F");
    grid.setLink(3, "C", 1, "G");

    dynamic_cast<Input *>(grid["A"])->setValue(nts::TRUE);
    dynamic_cast<Input *>(grid["B"])->setValue(nts::TRUE);
    grid.simulate(1);
    cr_assert_eq(grid["D"]->compute(1), nts::FALSE);

    dynamic_cast<Input *>(grid["A"])->setValue(nts::FALSE);
    dynamic_cast<Input *>(grid["B"])->setValue(nts::FALSE);
    grid.simulate(1);
    cr_assert_eq(grid["E"]->compute(1), nts::TRUE);

    dynamic_cast<Input *>(grid["A"])->setValue(nts::FALSE);
    dynamic_cast<Input *>(grid["B"])->setValue(nts::TRUE);
    grid.simulate(1);
    cr_assert_eq(grid["E"]->compute(1), nts::TRUE);

    dynamic_cast<Input *>(grid["A"])->setValue(nts::UNDEFINED);
    dynamic_cast<Input *>(grid["B"])->setValue(nts::TRUE);
    grid.simulate(1);
    cr_assert_eq(grid["F"]->compute(1), nts::UNDEFINED);

    dynamic_cast<Input *>(grid["A"])->setValue(nts::FALSE);
    dynamic_cast<Input *>(grid["B"])->setValue(nts::UNDEFINED);
    grid.simulate(1);
    cr_assert_eq(grid["G"]->compute(1), nts::TRUE);

    try {
        grid["C"]->compute(18);
    } catch(const std::exception& e) {
        cr_assert_str_eq(e.what(), "C4011: Pin not found");
    }
}
