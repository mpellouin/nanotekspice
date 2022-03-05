/*
** EPITECH PROJECT, 2022
** nts
** File description:
** SevenSegmentDisplay
*/

#ifndef SEVENSEGMENTDISPLAY_HPP_
#define SEVENSEGMENTDISPLAY_HPP_

#include "BaseComp.hpp"
#include <SFML/Graphics.hpp>

class SevenSegmentDisplay : public BaseComp {
    public:
        SevenSegmentDisplay(std::string const &name, std::size_t nbPin);
        ~SevenSegmentDisplay();

        void selectInput();
        void simulate(std::size_t tick);
        nts::Tristate compute(std::size_t pin);
    protected:
    private:
        std::vector<nts::Tristate> _states;
        sf::RenderWindow _window;
        std::vector<sf::RectangleShape> _rects;
        sf::CircleShape _circle;
};

#endif /* !SEVENSEGMENTDISPLAY_HPP_ */
