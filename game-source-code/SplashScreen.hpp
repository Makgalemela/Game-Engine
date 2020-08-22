#ifndef SPLASHSCREEN_HPP
#define SPLASHSCREEN_HPP
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Screen.hpp"
class SplashScreen : public Screen
{
public:

    SplashScreen();
    ~SplashScreen();
    void setTexture(sf::Texture) override;
    sf::Sprite getSplash() const;
private:
     sf::Vector2f _position;
    sf::Texture _splashTexture;
    sf::Sprite _splashSprite;
};

#endif // SPLASHSCREEN_HPP
