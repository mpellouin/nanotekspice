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
    Circuit *grid = new Circuit();

    grid->AddComponent("input", "in1");

    cr_assert_eq(grid->compute(1), nts::UNDEFINED);
}

// Test(Circuit, Circuit_AddComponent)
// {
//     nts::Circuit circuit("circuit");
//     nts::IComponent *component = new nts::Input("input");
//     std::size_t id = circuit.addComponent(component);

//     cr_assert(id == 0);
//     cr_assert(circuit.getNbComponents() == 1);
//     cr_assert(circuit.getComponent(id) == component);
// }

// Test(Circuit, Circuit_AddLink)
// {
//     nts::Circuit circuit("circuit");
//     nts::IComponent *component1 = new nts::Input("input");
//     nts::IComponent *component2 = new nts::Output("output");
//     circuit.addComponent(component1);
//     circuit.addComponent(component2);
//     circuit.link(0, 1);

//     cr_assert(circuit.getNbLinks() == 1);
//     cr_assert(circuit.getLink(0) == (nts::Link{0, 1, component2}));
// }

// Test(Circuit, Circuit_Simulate)
// {
//     nts::Circuit circuit("circuit");
//     nts::IComponent *component1 = new nts::Input("input");
//     nts::IComponent *component2 = new nts::Output("output");
//     circuit.addComponent(component1);
//     circuit.addComponent(component2);
//     circuit.link(0, 1);
//     circuit.simulate(1);

//     cr_assert(component2->compute(1) == nts::UNDEFINED);
// }

// Test(Circuit, Circuit_SetLink)
// {
//     nts::Circuit circuit("circuit");
//     nts::IComponent *component1 = new n
// }
