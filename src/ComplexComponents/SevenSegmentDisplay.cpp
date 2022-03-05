/*
** EPITECH PROJECT, 2022
** nts
** File description:
** SevenSegmentDisplay
*/

#include "SevenSegmentDisplay.hpp"


SevenSegmentDisplay::SevenSegmentDisplay(std::string const &name, std::size_t nbPin = 16) : BaseComp(name, nbPin), _window {sf::VideoMode(200, 200), name}
{
    _type = "SevenSegmentDisplay";
    _inPins = std::vector<int> {1, 2, 3, 4};
    _outPins = std::vector<int> {6};
    _rects = std::vector<sf::RectangleShape> {7, sf::RectangleShape()};
    for (int i = 0; i < 7; i++) {
        _rects[i].setSize(sf::Vector2f(60.0, 12.0));
        _rects[i].setFillColor(sf::Color(91, 91, 91));
    }
    _rects[0].setPosition(sf::Vector2f(30.0, 10.0));
    _rects[1].setPosition(sf::Vector2f(115.0, 25.0));
    _rects[2].setPosition(sf::Vector2f(115.0, 115.0));
    _rects[3].setPosition(sf::Vector2f(30.0, 180.0));
    _rects[4].setPosition(sf::Vector2f(20.0, 115.0));
    _rects[5].setPosition(sf::Vector2f(20.0, 25.0));
    _rects[6].setPosition(sf::Vector2f(30.0, 90.0));
    _rects[1].setRotation(90.0);
    _rects[2].setRotation(90.0);
    _rects[4].setRotation(90.0);
    _rects[5].setRotation(90.0);
    for (int i = 0; i < 7; i++) {
        _window.draw(_rects[i]);
    }
    _window.display();

}

SevenSegmentDisplay::~SevenSegmentDisplay()
{
    _window.close();
}

void SevenSegmentDisplay::simulate(std::size_t tick)
{
    (void)tick;
    int selector = 0;
    std::vector<int> pattern;
    if (_links[1].component != nullptr && _links[2].component != nullptr && _links[3].component != nullptr && _links[4].component != nullptr) {
        if (_links[1].component->compute(_links[1].pin) == nts::UNDEFINED || _links[2].component->compute(_links[2].pin) == nts::UNDEFINED
        || _links[3].component->compute(_links[3].pin) == nts::UNDEFINED || _links[4].component->compute(_links[4].pin) == nts::UNDEFINED) {
            return ;
        }
        selector += (_links[1].component->compute(_links[1].pin) == nts::TRUE ? 1 : 0)
                + (_links[2].component->compute(_links[2].pin) == nts::TRUE ? 2 : 0)
                + (_links[3].component->compute(_links[3].pin) == nts::TRUE ? 4 : 0)
                + (_links[4].component->compute(_links[4].pin) == nts::TRUE ? 8 : 0);
    }
    for (int i = 0; i < 7; i++) {
        _rects[i].setFillColor(sf::Color(91, 91, 91));
    }
    switch (selector) {
        case 0: pattern = std::vector<int> {0, 1, 2, 3, 4, 5};
            break;
        case 1: pattern = std::vector<int> {1, 2};
            break;
        case 2: pattern = std::vector<int> {0, 1, 3, 4, 6};
            break;
        case 3: pattern = std::vector<int> {0, 1, 2, 3, 6};
            break;
        case 4: pattern = std::vector<int> {1, 2, 5, 6};
            break;
        case 5: pattern = std::vector<int> {0, 2, 3, 5, 6};
            break;
        case 6: pattern = std::vector<int> {0, 2, 3, 4, 5, 6};
            break;
        case 7: pattern = std::vector<int> {0, 1, 2};
            break;
        case 8: pattern = std::vector<int> {0, 1, 2, 3, 4, 5, 6};
            break;
        case 9: pattern = std::vector<int> {0, 1, 2, 3, 5, 6};
            break;
        case 10: pattern = std::vector<int> {0, 1, 2, 4, 5, 6};
            break;
        case 11: pattern = std::vector<int> {2, 3, 4, 5, 6};
            break;
        case 12: pattern = std::vector<int> {0, 3, 4, 5};
            break;
        case 13: pattern = std::vector<int> {1, 2, 3, 4, 6};
            break;
        case 14: pattern = std::vector<int> {0, 3, 4, 5, 6};
            break;
        case 15: pattern = std::vector<int> {0, 4, 5, 6};
            break;
        default: break;
    };
    for (int j : pattern)
        _rects[j].setFillColor(sf::Color::Red);
    _window.clear();
    for (int i = 0; i < 7; i++)
        _window.draw(_rects[i]);
    _window.display();
}

nts::Tristate SevenSegmentDisplay::compute(std::size_t pin)
{
    if (std::find(_outPins.begin(), _outPins.end(), pin) != _outPins.end()) {
        simulate(0);
        return _pins[pin];
    } else if (std::find(_inPins.begin(), _inPins.end(), pin) != _inPins.end()) {
        if (_links[pin].component != nullptr) {
            _pins[pin] = _links[pin].component->compute(_links[pin].pin);
            return _pins[pin];
        }
    } else {
        throw BaseComp::Error("SevenSegmentDisplay: Pin not found");
    }
    return nts::UNDEFINED;
}
