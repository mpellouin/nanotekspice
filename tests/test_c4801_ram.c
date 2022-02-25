/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** test_c4801_ram
*/

#include <criterion/criterion.h>
#include "Circuit.hpp"

Test(Circuit, basic_ram_test)
{
    Circuit grid;

    grid.addComponent("4801", "ram");
    grid.addComponent("output", "out1");
    grid.addComponent("output", "out2");
    grid.addComponent("input", "ram_read");
    grid.addComponent("input", "ram_write");
    grid.addComponent("input", "ram_enable");
    grid.addComponent("input", "reset");
    grid.addComponent("4040", "counter");
    grid.addComponent("clock", "cl");

    grid.setLink(1, "ram_read", 20, "ram");
    grid.setLink(1, "ram_write", 21, "ram");
    grid.setLink(1, "ram_enable", 18, "ram");
    grid.setLink(9, "ram", 1, "out1");
    grid.setLink(10, "ram", 1, "out2");
    grid.setLink(1, "reset", 11, "counter");
    grid.setLink(1, "cl", 10, "counter");
    grid.setLink(9, "counter", 8, "ram");
    grid.setLink(7, "counter", 7, "ram");
    grid.setLink(6, "counter", 6, "ram");
    grid.setLink(5, "counter", 5, "ram");
    grid.setLink(3, "counter", 4, "ram");
    grid.setLink(2, "counter", 3, "ram");
    grid.setLink(9, "ram", 9, "counter");
    grid.setLink(10, "ram", 7, "counter");
    grid.setLink(11, "ram", 6, "counter");


}
