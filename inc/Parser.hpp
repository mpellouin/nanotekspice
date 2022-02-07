/*
** EPITECH PROJECT, 2022
** nts
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <string>
#include <sstream>
#include <fstream>
#include <stdexcept>

class Parser {
    public:
        Parser(const std::string &filepath);
        ~Parser();

        void getNextLine();
        std::string parseLine();
        bool isNewSection();

    protected:
    private:
        std::ifstream _stream;
        std::stringstream *_line;
};

#endif /* !PARSER_HPP_ */
