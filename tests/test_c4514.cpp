/*
** EPITECH PROJECT, 2022
** nts
** File description:
** test_c4512
*/

#include "criterion/criterion.h"
#include "Circuit.hpp"


//! Test the C4514 class
// Test(Circuit, Circuit_4514_Gate)
// {
//     Circuit grid;
//     grid.AddComponent("input", "A");
//     grid.AddComponent("input", "B");
//     grid.AddComponent("input", "C");
//     grid.AddComponent("input", "D");
//     grid.AddComponent("input", "prob");
//     grid.AddComponent("input", "inh");
//     grid.AddComponent("4514", "dec");
//     grid.AddComponent("output", "0");
//     grid.AddComponent("output", "1");
//     grid.AddComponent("output", "2");
//     grid.AddComponent("output", "3");
//     grid.AddComponent("output", "4");
//     grid.AddComponent("output", "5");
//     grid.AddComponent("output", "6");
//     grid.AddComponent("output", "7");
//     grid.AddComponent("output", "8");
//     grid.AddComponent("output", "9");
//     grid.AddComponent("output", "10");
//     grid.AddComponent("output", "11");
//     grid.AddComponent("output", "12");
//     grid.AddComponent("output", "13");
//     grid.AddComponent("output", "14");
//     grid.AddComponent("output", "15");

//     grid.setLink(1, "0", 11, "dec");
//     grid.setLink(1, "1", 9, "dec");
//     grid.setLink(1, "2", 10, "dec");
//     grid.setLink(1, "3", 8, "dec");
//     grid.setLink(1, "4", 7, "dec");
//     grid.setLink(1, "5", 6, "dec");
//     grid.setLink(1, "6", 5, "dec");
//     grid.setLink(1, "7", 4, "dec");
//     grid.setLink(1, "8", 18, "dec");
//     grid.setLink(1, "9", 17, "dec");
//     grid.setLink(1, "10", 20, "dec");
//     grid.setLink(1, "11", 19, "dec");
//     grid.setLink(1, "12", 14, "dec");
//     grid.setLink(1, "13", 13, "dec");
//     grid.setLink(1, "14", 16, "dec");
//     grid.setLink(1, "15", 15, "dec");
//     grid.setLink(1, "inh", 23, "dec");
//     grid.setLink(1, "prob", 1, "dec");
//     grid.setLink(1, "A", 2, "dec");
//     grid.setLink(1, "B", 3, "dec");
//     grid.setLink(1, "C", 21, "dec");
//     grid.setLink(1, "D", 22, "dec");

//     // std::cerr << "line 61" << std::endl;

//     dynamic_cast<Input *>(grid["prob"])->setValue(nts::FALSE);
//     dynamic_cast<Input *>(grid["inh"])->setValue(nts::TRUE);
//     dynamic_cast<Input *>(grid["A"])->setValue(nts::FALSE);
//     dynamic_cast<Input *>(grid["B"])->setValue(nts::FALSE);
//     dynamic_cast<Input *>(grid["C"])->setValue(nts::FALSE);
//     dynamic_cast<Input *>(grid["D"])->setValue(nts::FALSE);
//     grid.simulate(1);
//     cr_assert_eq(grid["7"]->compute(1), nts::UNDEFINED);
//     cr_assert_eq(grid["3"]->compute(1), nts::UNDEFINED);
//     cr_assert_eq(grid["2"]->compute(1), nts::UNDEFINED);
//     cr_assert_eq(grid["14"]->compute(1), nts::UNDEFINED);
//     cr_assert_eq(grid["10"]->compute(1), nts::UNDEFINED);

//     // std::cerr << "line 76" << std::endl;

//     dynamic_cast<Input *>(grid["prob"])->setValue(nts::TRUE);
//     grid.simulate(1);
//     cr_assert_eq(grid["7"]->compute(1), nts::UNDEFINED);
//     cr_assert_eq(grid["3"]->compute(1), nts::UNDEFINED);
//     cr_assert_eq(grid["2"]->compute(1), nts::UNDEFINED);
//     cr_assert_eq(grid["14"]->compute(1), nts::UNDEFINED);
//     cr_assert_eq(grid["10"]->compute(1), nts::UNDEFINED);

//     // std::cerr << "line 86" << std::endl;

//     dynamic_cast<Input *>(grid["inh"])->setValue(nts::FALSE);
//     grid.simulate(1);
//     std::cerr << "line 90" << std::endl;
//     cr_assert_eq(grid["0"]->compute(1), nts::TRUE);
//     cr_assert_eq(grid["1"]->compute(1), nts::FALSE);

//     // std::cerr << "line 91" << std::endl;

//     dynamic_cast<Input *>(grid["inh"])->setValue(nts::UNDEFINED);
//     grid.simulate(1);
//     cr_assert_eq(grid["0"]->compute(1), nts::UNDEFINED);
//     cr_assert_eq(grid["1"]->compute(1), nts::UNDEFINED);
//     cr_assert_eq(grid["2"]->compute(1), nts::UNDEFINED);

//     // std::cerr << "line 99" << std::endl;

//     dynamic_cast<Input *>(grid["inh"])->setValue(nts::FALSE);
//     grid.simulate(1);
//     cr_assert_eq(grid["0"]->compute(1), nts::TRUE);
//     cr_assert_eq(grid["1"]->compute(1), nts::FALSE);

//     // std::cerr << "line 106" << std::endl;

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
