/*
** EPITECH PROJECT, 2022
** nts
** File description:
** Shell
*/

#ifndef SHELL_HPP_
#define SHELL_HPP_

#include <string>
#include <map>
#include <functional>

class Shell {
    public:
        Shell();
        ~Shell();

        std::map<std::string, std::function<void()>> Commands;

        /**
         * @brief Get the Input From User object
         * 
         */
        void getInputFromUser();

        /**
         * @brief Checks if the eof has been reached
         * 
         * @return true if eof is reached, false instead
         */
        bool isEofReached();

        /**
         * @brief Get the User Input object
         * 
         * @return std::string 
         */
        std::string getUserInput() {return _userInput;};

        /**
         * @brief Execute the command stored in the class.
         * 
         * @exception exception-object Unknown command.
         * @exception exception-object Not enough arguments.
         * @exception exception-object Bad arguments.
         */
        void executeCommand();

        static class Error : public std::exception {
            public:
                Error(const std::string &message) {this->message = new std::string(message);};
                const char *what() const noexcept override;
            private:
                std::string *message;
        } err;

    protected:
    private:
        std::string _userInput;
};

#endif /* !SHELL_HPP_ */
