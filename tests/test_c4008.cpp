/*
** EPITECH PROJECT, 2022
** nts
** File description:
** test_c4512
*/

#include "criterion/criterion.h"
#include "Circuit.hpp"

Test(Circuit, Circuit_4008_Gate)
{
    Circuit grid;
    grid.AddComponent("input", "A1");
    grid.AddComponent("input", "B1");
    grid.AddComponent("input", "A2");
    grid.AddComponent("input", "B2");
    grid.AddComponent("input", "A3");
    grid.AddComponent("input", "B3");
    grid.AddComponent("input", "A4");
    grid.AddComponent("input", "B4");
    grid.AddComponent("input", "C");
    grid.AddComponent("4008", "dec");
    grid.AddComponent("output", "S1");
    grid.AddComponent("output", "S2");
    grid.AddComponent("output", "S3");
    grid.AddComponent("output", "S4");
    grid.AddComponent("output", "CO");

    grid.setLink(1, "A1", 7, "dec");
    grid.setLink(1, "C", 9, "dec");
    grid.setLink(1, "B1", 6, "dec");
    grid.setLink(1, "A2", 5, "dec");
    grid.setLink(1, "B2", 4, "dec");
    grid.setLink(1, "A3", 3, "dec");
    grid.setLink(1, "B3", 2, "dec");
    grid.setLink(1, "A4", 1, "dec");
    grid.setLink(1, "B4", 15, "dec");
    grid.setLink(1, "S1", 10, "dec");
    grid.setLink(1, "S2", 11, "dec");
    grid.setLink(1, "S3", 12, "dec");
    grid.setLink(1, "S4", 13, "dec");
    grid.setLink(1, "CO", 14, "dec");

    dynamic_cast<Input *>(grid["C"])->setValue(nts::FALSE);
    dynamic_cast<Input *>(grid["A1"])->setValue(nts::TRUE);
    dynamic_cast<Input *>(grid["A2"])->setValue(nts::FALSE);
    dynamic_cast<Input *>(grid["A3"])->setValue(nts::FALSE);
    dynamic_cast<Input *>(grid["A4"])->setValue(nts::FALSE);
    grid.simulate(1);
    cr_assert_eq(grid["S1"]->compute(1), nts::UNDEFINED);
    cr_assert_eq(grid["S2"]->compute(1), nts::UNDEFINED);
    cr_assert_eq(grid["S3"]->compute(1), nts::UNDEFINED);
    cr_assert_eq(grid["S4"]->compute(1), nts::UNDEFINED);
    cr_assert_eq(grid["CO"]->compute(1), nts::UNDEFINED);

    dynamic_cast<Input *>(grid["B1"])->setValue(nts::TRUE);
    grid.simulate(1);
    cr_assert_eq(grid["S1"]->compute(1), nts::FALSE);
    cr_assert_eq(grid["S2"]->compute(1), nts::UNDEFINED);
    cr_assert_eq(grid["S3"]->compute(1), nts::UNDEFINED);
    cr_assert_eq(grid["S4"]->compute(1), nts::UNDEFINED);
    cr_assert_eq(grid["CO"]->compute(1), nts::UNDEFINED);

    dynamic_cast<Input *>(grid["B2"])->setValue(nts::FALSE);
    grid.simulate(1);
    cr_assert_eq(grid["S1"]->compute(1), nts::FALSE);
    cr_assert_eq(grid["S2"]->compute(1), nts::TRUE);
    cr_assert_eq(grid["S3"]->compute(1), nts::UNDEFINED);
    cr_assert_eq(grid["S4"]->compute(1), nts::UNDEFINED);
    cr_assert_eq(grid["CO"]->compute(1), nts::UNDEFINED);

    dynamic_cast<Input *>(grid["B3"])->setValue(nts::FALSE);
    grid.simulate(1);
    cr_assert_eq(grid["S1"]->compute(1), nts::FALSE);
    cr_assert_eq(grid["S2"]->compute(1), nts::TRUE);
    cr_assert_eq(grid["S3"]->compute(1), nts::FALSE);
    cr_assert_eq(grid["S4"]->compute(1), nts::UNDEFINED);
    cr_assert_eq(grid["CO"]->compute(1), nts::UNDEFINED);

    dynamic_cast<Input *>(grid["B4"])->setValue(nts::TRUE);
    grid.simulate(1);
    cr_assert_eq(grid["S1"]->compute(1), nts::FALSE);
    cr_assert_eq(grid["S2"]->compute(1), nts::TRUE);
    cr_assert_eq(grid["S3"]->compute(1), nts::FALSE);
    cr_assert_eq(grid["S4"]->compute(1), nts::TRUE);
    cr_assert_eq(grid["CO"]->compute(1), nts::FALSE);

    // std::cerr << "line 106" << std::endl;

//     dynamic_cast<Input *>(grid["B"])->setValue(nts::TRUE);
//     grid.simulate(1);
//     cr_assert_eq(grid["0"]->compute(1), nts::FALSE);
//     cr_assert_eq(grid["1"]->compute(1), nts::FALSE);
//     cr_assert_eq(grid["2"]->compute(1), nts::TRUE);

//     // std::cerr << "line 114" << std::endl;

//     dynamic_cast<Input *>(grid["A"])->setValue(nts::TRUE);
//     grid.simulate(1);
//     cr_assert_eq(grid["0"]->compute(1), nts::FALSE);
//     cr_assert_eq(grid["1"]->compute(1), nts::FALSE);
//     cr_assert_eq(grid["2"]->compute(1), nts::FALSE);
//     cr_assert_eq(grid["3"]->compute(1), nts::TRUE);
// }
}
