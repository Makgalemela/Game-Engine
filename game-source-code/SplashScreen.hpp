#ifndef SPLASHSCREEN_HPP
#define SPLASHSCREEN_HPP
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class SplashScreen 
{
public:
    SplashScreen();
    ~SplashScreen();
    
    sf::Sprite getSplash() const;
private:
     sf::Vector2f _position;
    sf::Texture _splashTexture;
    sf::Sprite _splashSprite;
};

#endif // SPLASHSCREEN_HPP
