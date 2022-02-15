/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** basic_gates
*/

#include "criterion/criterion.h"
#include "Circuit.hpp"

Test(Circuit, Circuit_direct_link)
{
    Circuit grid;

    grid.AddComponent("input", "A");
    grid.AddComponent("output", "B");
    grid.setLink(1, "A", 1, "B");
    dynamic_cast<Input *>(grid["A"])->setValue(nts::TRUE);
    grid.simulate(1);

    cr_assert_eq(grid["B"]->compute(1), nts::TRUE);
}

Test(Circuit, Circuit_And_Gate)
{
    Circuit grid;

    grid.AddComponent("input", "A");
    grid.AddComponent("input", "B");
    grid.AddComponent("and", "gate");
    grid.AddComponent("output", "C");
    grid.setLink(1, "A", 1, "gate");
    grid.setLink(1, "B", 2, "gate");
    grid.setLink(3, "gate", 1, "C");

    dynamic_cast<Input *>(grid["A"])->setValue(nts::TRUE);
    dynamic_cast<Input *>(grid["B"])->setValue(nts::TRUE);
    grid.simulate(1);
    cr_assert_eq(grid["C"]->compute(1), nts::TRUE);

    dynamic_cast<Input *>(grid["A"])->setValue(nts::FALSE);
    dynamic_cast<Input *>(grid["B"])->setValue(nts::TRUE);
    grid.simulate(1);
    cr_assert_eq(grid["C"]->compute(1), nts::FALSE);

    dynamic_cast<Input *>(grid["A"])->setValue(nts::TRUE);
    dynamic_cast<Input *>(grid["B"])->setValue(nts::UNDEFINED);
    grid.simulate(1);
    cr_assert_eq(grid["C"]->compute(1), nts::UNDEFINED);

    dynamic_cast<Input *>(grid["A"])->setValue(nts::FALSE);
    dynamic_cast<Input *>(grid["B"])->setValue(nts::UNDEFINED);
    grid.simulate(1);
    cr_assert_eq(grid["C"]->compute(1), nts::FALSE);
}

Test(Circuit, Circuit_Or_Gate)
{
    Circuit grid;

    grid.AddComponent("input", "A");
    grid.AddComponent("input", "B");
    grid.AddComponent("or", "gate");
    grid.AddComponent("output", "C");
    grid.setLink(1, "A", 1, "gate");
    grid.setLink(1, "B", 2, "gate");
    grid.setLink(3, "gate", 1, "C");

    dynamic_cast<Input *>(grid["A"])->setValue(nts::TRUE);
    dynamic_cast<Input *>(grid["B"])->setValue(nts::TRUE);
    grid.simulate(1);
    cr_assert_eq(grid["C"]->compute(1), nts::TRUE);

    dynamic_cast<Input *>(grid["A"])->setValue(nts::FALSE);
    dynamic_cast<Input *>(grid["B"])->setValue(nts::FALSE);
    grid.simulate(1);
    cr_assert_eq(grid["C"]->compute(1), nts::FALSE);

    dynamic_cast<Input *>(grid["A"])->setValue(nts::TRUE);
    dynamic_cast<Input *>(grid["B"])->setValue(nts::UNDEFINED);
    grid.simulate(1);
    cr_assert_eq(grid["C"]->compute(1), nts::TRUE);

    dynamic_cast<Input *>(grid["A"])->setValue(nts::FALSE);
    dynamic_cast<Input *>(grid["B"])->setValue(nts::UNDEFINED);
    grid.simulate(1);
    cr_assert_eq(grid["C"]->compute(1), nts::UNDEFINED);
}

Test(Circuit, Circuit_Nor_Gate)
{
    Circuit grid;

    grid.AddComponent("input", "A");
    grid.AddComponent("input", "B");
    grid.AddComponent("nor", "gate");
    grid.AddComponent("output", "C");
    grid.setLink(1, "A", 1, "gate");
    grid.setLink(1, "B", 2, "gate");
    grid.setLink(3, "gate", 1, "C");

    dynamic_cast<Input *>(grid["A"])->setValue(nts::TRUE);
    dynamic_cast<Input *>(grid["B"])->setValue(nts::TRUE);
    grid.simulate(1);
    cr_assert_eq(grid["C"]->compute(1), nts::FALSE);

    dynamic_cast<Input *>(grid["A"])->setValue(nts::FALSE);
    dynamic_cast<Input *>(grid["B"])->setValue(nts::FALSE);
    grid.simulate(1);
    cr_assert_eq(grid["C"]->compute(1), nts::TRUE);

    dynamic_cast<Input *>(grid["A"])->setValue(nts::TRUE);
    dynamic_cast<Input *>(grid["B"])->setValue(nts::UNDEFINED);
    grid.simulate(1);
    cr_assert_eq(grid["C"]->compute(1), nts::FALSE);

    dynamic_cast<Input *>(grid["A"])->setValue(nts::FALSE);
    dynamic_cast<Input *>(grid["B"])->setValue(nts::UNDEFINED);
    grid.simulate(1);
    cr_assert_eq(grid["C"]->compute(1), nts::UNDEFINED);
}

Test(Circuit, Circuit_Nand_Gate)
{
    Circuit grid;

    grid.AddComponent("input", "A");
    grid.AddComponent("input", "B");
    grid.AddComponent("nand", "gate");
    grid.AddComponent("output", "C");
    grid.setLink(1, "A", 1, "gate");
    grid.setLink(1, "B", 2, "gate");
    grid.setLink(3, "gate", 1, "C");

    dynamic_cast<Input *>(grid["A"])->setValue(nts::TRUE);
    dynamic_cast<Input *>(grid["B"])->setValue(nts::TRUE);
    grid.simulate(1);
    cr_assert_eq(grid["C"]->compute(1), nts::FALSE);

    dynamic_cast<Input *>(grid["A"])->setValue(nts::FALSE);
    dynamic_cast<Input *>(grid["B"])->setValue(nts::TRUE);
    grid.simulate(1);
    cr_assert_eq(grid["C"]->compute(1), nts::TRUE);

    dynamic_cast<Input *>(grid["A"])->setValue(nts::TRUE);
    dynamic_cast<Input *>(grid["B"])->setValue(nts::UNDEFINED);
    grid.simulate(1);
    cr_assert_eq(grid["C"]->compute(1), nts::UNDEFINED);

    dynamic_cast<Input *>(grid["A"])->setValue(nts::FALSE);
    dynamic_cast<Input *>(grid["B"])->setValue(nts::UNDEFINED);
    grid.simulate(1);
    cr_assert_eq(grid["C"]->compute(1), nts::TRUE);
}

Test(Circuit, Circuit_Not_gate)
{
    Circuit grid;

    grid.AddComponent("input", "A");
    grid.AddComponent("not", "B");
    grid.AddComponent("output", "C");
    grid.setLink(1, "A", 1, "B");
    grid.setLink(2, "B", 1, "C");

    dynamic_cast<Input *>(grid["A"])->setValue(nts::TRUE);
    grid.simulate(1);
    cr_assert_eq(grid["C"]->compute(1), nts::FALSE);

    dynamic_cast<Input *>(grid["A"])->setValue(nts::FALSE);
    grid.simulate(1);
    cr_assert_eq(grid["C"]->compute(1), nts::TRUE);

    dynamic_cast<Input *>(grid["A"])->setValue(nts::UNDEFINED);
    grid.simulate(1);
    cr_assert_eq(grid["C"]->compute(1), nts::UNDEFINED);

}
