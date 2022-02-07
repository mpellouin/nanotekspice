/*
** EPITECH PROJECT, 2022
** nts
** File description:
** Parser
*/

#include "Parser.hpp"

Parser::Parser(const std::string &filepath)
{
    this->_stream = std::ifstream(filepath);
    this->_line = new std::stringstream("");
}

Parser::~Parser()
{
}

void Parser::getNextLine(void)
{
    std::string tempLine;
    if (this->_stream.fail() || this->_stream.bad() || this->_stream.eof())
        throw std::out_of_range("Can't read no more line");
    getline(_stream, tempLine);
    this->_line = new std::stringstream(tempLine);
}

std::string Parser::parseLine()
{
    std::string nextArgument;
    *this->_line >> nextArgument;
    return nextArgument;
}

bool Parser::isNewSection()
{
    if (!this->_line->str().compare(".chipsets:") || !this->_line->str().compare(".links:"))
        return true;
    return false;
}
