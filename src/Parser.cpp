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
    std::string tempLine("");
    while (tempLine == "") {
        if (this->_stream.fail() || this->_stream.bad() || this->_stream.eof())
            throw std::out_of_range("Can't read no more line");
        getline(_stream, tempLine);
        if (tempLine.find('#') != std::string::npos)
            tempLine = tempLine.substr(0, tempLine.find('#'));
        this->_line = new std::stringstream(tempLine);
        this->_argNumber = 0;
    }
}

std::string Parser::parseLine()
{
    std::string nextArgument;
    *this->_line >> nextArgument;
    if (nextArgument == "" && this->_argNumber > 0)
        throw std::out_of_range("Missing an argument");
    this->_argNumber++;
    return nextArgument;
}

bool Parser::isNewSection()
{
    if (!this->_line->str().compare(".chipsets:") || !this->_line->str().compare(".links:"))
        return true;
    return false;
}

const char *Parser::Error::what() const noexcept
{
    return this->message->c_str();
}
