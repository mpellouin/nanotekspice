/*
** EPITECH PROJECT, 2022
** nts
** File description:
** Parser
*/

#include "Parser.hpp"

parse::Parser::Parser(const std::string &filepath)
{
    this->_stream = std::ifstream(filepath);
    this->_line = new std::stringstream("");
}

parse::Parser::~Parser()
{
}

void parse::Parser::getNextLine(void)
{
    std::string tempLine("");
    while (tempLine == "") {
        if (this->_stream.fail() || this->_stream.bad() || this->_stream.eof())
            throw parse::Parser::Error("Can't read no more line");
        getline(_stream, tempLine);
        if (tempLine.find('#') != std::string::npos)
            tempLine = tempLine.substr(0, tempLine.find('#'));
        this->_line = new std::stringstream(tempLine);
        this->_argNumber = 0;
    }
}

std::string parse::Parser::parseLine()
{
    std::string nextArgument;
    *this->_line >> nextArgument;
    if (nextArgument == "" && this->_argNumber > 0)
        throw parse::Parser::Error("Missing an argument");
    this->_argNumber++;
    return nextArgument;
}

bool parse::Parser::isNewSection()
{
    if (!this->_line->str().compare(".chipsets:") || !this->_line->str().compare(".links:")) {
        this->_parseState = !this->_line->str().compare(".chipsets:") ? chipsets : links;
        return true;
    }
    return false;
}

const char *parse::Parser::Error::what() const noexcept
{
    return this->message->c_str();
}
