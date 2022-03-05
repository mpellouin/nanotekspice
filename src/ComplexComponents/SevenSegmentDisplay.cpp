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
    _inPins = std::vector<int> {1, 2, 4, 5, 6, 8, 9, 10};
    _outPins = std::vector<int> {11};
    _states = {8, nts::UNDEFINED};
    _rects = std::vector<sf::RectangleShape> {8, sf::RectangleShape()};
    for (int i = 0; i < 8; i++) {
        _rects[i].setSize(sf::Vector2f(60.0, 12.0));
        _rects[i].setFillColor(sf::Color(91, 91, 91));
    }
    _rects[7].setSize(sf::Vector2f(15.0, 15.0));
    _rects[0].setPosition(sf::Vector2f(30.0, 10.0));
    _rects[1].setPosition(sf::Vector2f(115.0, 25.0));
    _rects[2].setPosition(sf::Vector2f(115.0, 115.0));
    _rects[3].setPosition(sf::Vector2f(30.0, 180.0));
    _rects[4].setPosition(sf::Vector2f(20.0, 115.0));
    _rects[5].setPosition(sf::Vector2f(20.0, 25.0));
    _rects[6].setPosition(sf::Vector2f(30.0, 90.0));
    _rects[7].setPosition(sf::Vector2f(140.0, 180.0));
    _rects[1].setRotation(90.0);
    _rects[2].setRotation(90.0);
    _rects[4].setRotation(90.0);
    _rects[5].setRotation(90.0);
    for (int i = 0; i < 8; i++) {
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
    _window.clear();
    _states[0] = _links[1].component != nullptr && _links[1].component->compute(_links[1].pin) == nts::TRUE ? nts::TRUE : nts::FALSE;
    _states[1] = _links[10].component != nullptr && _links[10].component->compute(_links[10].pin) == nts::TRUE ? nts::TRUE : nts::FALSE;
    _states[2] = _links[8].component != nullptr && _links[8].component->compute(_links[8].pin) == nts::TRUE ? nts::TRUE : nts::FALSE;
    _states[3] = _links[6].component != nullptr && _links[6].component->compute(_links[6].pin) == nts::TRUE ? nts::TRUE : nts::FALSE;
    _states[4] = _links[5].component != nullptr && _links[5].component->compute(_links[5].pin) == nts::TRUE ? nts::TRUE : nts::FALSE;
    _states[5] = _links[2].component != nullptr && _links[2].component->compute(_links[2].pin) == nts::TRUE ? nts::TRUE : nts::FALSE;
    _states[6] = _links[9].component != nullptr && _links[9].component->compute(_links[9].pin) == nts::TRUE ? nts::TRUE : nts::FALSE;
    _states[7] = _links[4].component != nullptr && _links[4].component->compute(_links[4].pin) == nts::TRUE ? nts::TRUE : nts::FALSE;
    for (int i = 0; i < 8; i++) {
        if (_states[i] == nts::TRUE) {
            _rects[i].setFillColor(sf::Color::Red);
        } else {
            _rects[i].setFillColor(sf::Color(91, 91, 91));
        }
        _window.draw(_rects[i]);
    }
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
