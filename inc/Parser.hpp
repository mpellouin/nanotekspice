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

        /**
         * @brief Get the Next Line object and stores it in parser class.
         * 
         */
        void getNextLine();

        /**
         * @brief Parse the next line from input.
         * 
         * In case of error, throws an exception
         * @return Next parsable element as an std::string
         */
        std::string parseLine();

        /**
         * @brief Indicates if next line is the beggining of a new
         * section.
         * 
         * @return true if new section, false otherwise
         */
        bool isNewSection();

    protected:
    private:
        std::ifstream _stream;
        std::stringstream *_line;
        int _argNumber = 0;
};

#endif /* !PARSER_HPP_ */
