/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** complex_gates
*/

#include "criterion/criterion.h"
#include "Parser.hpp"

Test(Parser, parser)
{
    parse::Parser fals;
    parse::Parser parser;
    Circuit circuit;

    try {
        fals.openFile("rere");
    } catch (const std::exception &err) {
        std::cerr << err.what() << std::endl;
        cr_assert_eq(std::string(err.what()), std::string("File does not have .nts extension"));
    }
    parser.openFile("circuit/4069.nts");
    parser.getNextLine();
    cr_assert_eq(parser.parseLine(), ".chipsets:");
    parse::Parser neww;
    neww.openFile("circuit/4069.nts");
    try {
        neww.buildCircuit(circuit);
    } catch (const std::exception &except) {
        std::cerr << except.what() << std::endl;
        cr_assert_eq(std::string("EOF"), std::string(except.what()));
    };

    // cr_assert_eq(circuit["chip1"]->compute(1), nts::Tristate::UNDEFINED);

}
