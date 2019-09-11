#ifndef SCREEN_HPP
#define SCREEN_HPP
#include <SFML/Graphics.hpp>
class Screen 
{
public:
    Screen();
    ~Screen();
    void sampleText(sf::RenderWindow &_window){
        sf::Text text("hello", font);
        text.setCharacterSize(30);
        text.setStyle(sf::Text::Bold);
        text.setFillColor(sf::Color::Red);
        text.setPosition(sf::Vector2f(150.f, 5.f));
        _window.draw(text);
    };
private:
 sf::Font font;
};

#endif // SCREEN_HPP
