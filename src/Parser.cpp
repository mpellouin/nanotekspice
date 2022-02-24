/*
** EPITECH PROJECT, 2022
** nts
** File description:
** Parser
*/

#include "Parser.hpp"

parse::Parser::Parser()
{
    this->_line = std::stringstream(std::ios_base::in);
}

parse::Parser::~Parser()
{
}

void parse::Parser::openFile(const std::string &filepath)
{
    if (filepath.find(".nts") == std::string::npos || filepath.find(".nts") != filepath.length() - 4)
        throw parse::Parser::Error("File does not have .nts extension");
    this->_stream = std::ifstream(filepath);
    if (this->_stream.eof()) throw Error("Empty file.");
}

void parse::Parser::getNextLine(void)
{
    std::string tempLine("");
    while (tempLine == "") {
        if (this->_stream.fail() || this->_stream.bad() || this->_stream.eof())
            throw getParseState() == parse::State::links ? parse::Parser::Error("EOF") :
            parse::Parser::Error("Stream failed.");
        getline(_stream, tempLine);
        if (tempLine.find('#') != std::string::npos)
            tempLine = tempLine.substr(0, tempLine.find('#'));
        while (tempLine[0] <= 32 && tempLine != "") {
            tempLine = tempLine.length() > 1 ? tempLine.substr(1) : "";
        }
        _line = std::stringstream(tempLine);
        this->_argNumber = 0;
    }
    if (tempLine == ".chipsets:") this->_parseState = chipsets;
    if (tempLine == ".links:") this->_parseState = links;
}

std::string parse::Parser::parseLine()
{
    std::string nextArgument;
    _line >> nextArgument;
    if (nextArgument == "" && this->_argNumber > 0)
        throw parse::Parser::Error("Missing an argument");
    this->_argNumber++;
    return nextArgument;
}

bool parse::Parser::isNewSection()
{
    std::string sectionChecker;
    std::string holder(this->_line.str());
    this->_line >> sectionChecker;
    if (!sectionChecker.compare(".chipsets:") || !sectionChecker.compare(".links:")) {
        this->_parseState = !sectionChecker.compare(".chipsets:") ? chipsets : links;
        this->_line = std::stringstream(holder);
        return true;
    }
    this->_line = std::stringstream(holder);
    return false;
}

void parse::Parser::buildCircuit(Circuit &circuit)
{
    bool isThereAComponent = false;
    this->getNextLine();
    if (!this->isNewSection() || this->parseLine() != ".chipsets:")
        throw parse::Parser::Error("No Chipsets.");
    this->getNextLine();
    while (!this->isNewSection()) {
        isThereAComponent = true;
        std::string componentType = this->parseLine();
        std::string componentName = this->parseLine();
        circuit.AddComponent(componentType, componentName);
        this->getNextLine();
    }
    if (this->parseLine() == ".chipsets:") throw parse::Parser::Error("Multiple .chipsets definition.");
    if (!isThereAComponent) throw parse::Parser::Error("No components in file.");
    this->getNextLine();
    while (!this->isNewSection()) {
        std::string component = this->parseLine();
        std::string toLink = this->parseLine();
        if (component.find(':') != std::string::npos && toLink.find(':') != std::string::npos &&
            component.find(':') != 0 && component.find(':') != component.length() - 1 &&
            toLink.find(':') != 0 && toLink.find(':') != toLink.length() - 1) {
            circuit.setLink(
                static_cast<size_t>(std::atoi(component.substr(component.find(':') + 1).c_str())),
                component.substr(0, component.find(':')),
                static_cast<size_t>(std::atoi(toLink.substr(toLink.find(':') + 1).c_str())),
                toLink.substr(0, toLink.find(':')));
        } else throw Error("Wrong linking syntax.");
        this->getNextLine();
    }
}

const char *parse::Parser::Error::what() const noexcept
{
    return this->message->c_str();
}
