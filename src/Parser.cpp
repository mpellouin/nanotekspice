/*
** EPITECH PROJECT, 2022
** nts
** File description:
** Parser
*/

#include "Parser.hpp"

parse::Parser::Parser() : _line {new std::stringstream("")}
{
}

parse::Parser::~Parser()
{
    delete this->_line;
    delete this->_stream;
}

void parse::Parser::openFile(const std::string &filepath)
{
    if (filepath.find(".nts") == std::string::npos || filepath.find(".nts") != filepath.length() - 4)
        throw parse::Parser::Error("File does not have .nts extension");
    this->_stream = new std::ifstream(filepath);
}

void parse::Parser::getNextLine(void)
{
    std::string tempLine("");
    while (tempLine == "") {
        if (this->_stream->fail() || this->_stream->bad() || this->_stream->eof())
            throw parse::Parser::Error("EOF");
        getline(*_stream, tempLine);
        if (tempLine.find('#') != std::string::npos)
            tempLine = tempLine.substr(0, tempLine.find('#'));
        delete this->_line;
        this->_line = new std::stringstream(tempLine);
        this->_argNumber = 0;
    }
    if (tempLine == ".chipsets:") this->_parseState = chipsets;
    if (tempLine == ".links:") this->_parseState = links;
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

void parse::Parser::buildCircuit(Circuit &circuit)
{
    this->getNextLine();
    if (!this->isNewSection() || this->parseLine() != ".chipsets:")
        throw parse::Parser::Error("No Chipsets.");
    this->getNextLine();
    while (!this->isNewSection()) {
        circuit.AddComponent(this->parseLine(), this->parseLine());
        this->getNextLine();
    }
    if (this->parseLine() == ".chipsets:") throw parse::Parser::Error("Multiple .chipsets definition.");
    this->getNextLine();
    while (!this->isNewSection()) {
        std::string component = this->parseLine();
        std::string toLink = this->parseLine();
        if (component.find(':') != std::string::npos && toLink.find(':') != std::string::npos) {
            circuit.setLink(
                static_cast<size_t>(std::atoi(component.substr(component.find(':') + 1).c_str())),
                component.substr(0, component.find(':')),
                static_cast<size_t>(std::atoi(toLink.substr(toLink.find(':') + 1).c_str())),
                toLink.substr(0, toLink.find(':')));
        }
        this->getNextLine();
    }
}

const char *parse::Parser::Error::what() const noexcept
{
    return this->message->c_str();
}
