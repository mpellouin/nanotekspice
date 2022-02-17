/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** basic_IO
*/

#include "criterion/criterion.h"
#include "Circuit.hpp"

Test(Circuit, Circuit_Basic)
{
    Circuit grid;

    cr_assert_eq(grid.compute(1), nts::UNDEFINED);
}

Test(Circuit, Circuit_AddComponent)
{
    Circuit grid;

    grid.AddComponent("input", "A");
    grid.AddComponent("output", "B");
    grid.AddComponent("clock", "C");
    grid.AddComponent("and", "D");
    grid.AddComponent("or", "E");
    grid.AddComponent("not", "F");
    grid.AddComponent("nand", "G");

    cr_assert_eq(0, 0);
}

Test(Circuit, Circuit_Simlation)
{
    Circuit grid;

    grid.AddComponent("input", "A");
    grid.AddComponent("output", "B");
    grid.AddComponent("clock", "C");
    grid.AddComponent("and", "D");
    grid.AddComponent("or", "E");
    grid.AddComponent("not", "F");
    grid.AddComponent("nand", "G");

    grid.simulate(1);
    cr_assert_eq(0, 0);
}

Test(Circuit, Circuit_Clock_Simlation)
{
    Circuit grid;

    grid.AddComponent("clock", "A");
    dynamic_cast<Clock *>(grid["A"])->setValue(nts::TRUE);
    grid["A"]->simulate(10);
    grid.simulate(1);
    cr_assert_eq(0, 0);
}

Test(Circuit, Circuit_AddLink)
{
    Circuit grid;

    grid.AddComponent("input", "A");
    grid.AddComponent("output", "B");
    grid.AddComponent("clock", "C");
    grid.AddComponent("and", "D");
    grid.AddComponent("or", "E");
    grid.AddComponent("not", "F");
    grid.AddComponent("nand", "G");
    grid.AddComponent("true", "H");
    grid.AddComponent("false", "I");

    grid.setLink(1, *grid["A"], 1);
    grid.setLink(1, "A", 1, "B");
    grid.setLink(1, "C", 1, "B");
    grid.setLink(3, "D", 1, "B");
    grid.setLink(3, "E", 1, "B");
    grid.setLink(2, "F", 1, "B");
    grid.setLink(3, "G", 1, "B");
    grid.setLink(3, "H", 1, "B");
    grid.setLink(3, "I", 1, "B");

    cr_assert_eq(0, 0);
}

Test(Circuit, Component_access)
{
    Circuit grid;

    grid.AddComponent("input", "A");
    grid.AddComponent("output", "B");
    grid["B"]->setLink(1, *grid["A"], 1);
    Input *input = dynamic_cast<Input *>(grid["A"]);
    input->setValue(nts::Tristate::TRUE);
    grid["A"]->simulate(1);
    grid["B"]->simulate(1);
    grid["B"]->compute(1);
    cr_assert_eq(grid["B"]->compute(1), nts::Tristate::TRUE);
}

Test(Circuit, Circuit_dump)
{
    Circuit grid;
    grid.AddComponent("input", "A");
    grid.AddComponent("output", "B");

    grid.dump();
}

Test(Circuit, Circuit_errors)
{
    Circuit grid;

    grid.AddComponent("input", "A");
    try {
        grid.AddComponent("vache", "B");
    } catch (std::exception &e) {
        cr_assert_str_eq(e.what(), "Builder error: Unknown chipset type");
    }
    try {
        grid.AddComponent("input", "A");
    } catch (std::exception &e) {
        cr_assert_str_eq(e.what(), "Circuit error: This component already exists in this circuit");
    }
    try {
        grid["B"];
    } catch (std::exception &e) {
        cr_assert_str_eq(e.what(), "Circuit error: Component not found");
    }
    try {
        grid.setLink(1, "F", 1, "A");
    } catch (std::exception &e) {
        cr_assert_str_eq(e.what(), "Linking error: This component isn't in the circuit \"F\"");
    }
    try {
        grid.setLink(1, "A", 1, "F");
    } catch (std::exception &e) {
        cr_assert_str_eq(e.what(), "Linking error: This component isn't in the circuit \"F\"");
    }
}

Test(Circuit, Circuit_Specific_Cases)
{
    Circuit grid;
    grid.AddComponent("input", "B");
    grid.AddComponent("input", "A");
    grid.AddComponent("output", "C");
    grid.display();
    dynamic_cast<BaseComp *>(grid["A"])->simulate(1);
    dynamic_cast<BaseComp *>(grid["C"])->simulate(1);
    grid.simulate(1);

}
