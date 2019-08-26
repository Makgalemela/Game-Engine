#include "SplashScreen.hpp"

SplashScreen::SplashScreen()
{
    _splashTexture.loadFromFile("../executables/resources/splash.png");
        ///throw "Invalid splashscreen ";
    _position.x = 0.f;
    _position.y = 0.f;
    _splashSprite.setTexture(_splashTexture);
    _splashSprite.setPosition(_position);
    _splashSprite.scale(sf::Vector2f(0.65f , 1.f));
}


 sf::Sprite SplashScreen::getSplash() const{
     return _splashSprite;
 }
 
 
SplashScreen::~SplashScreen()
{
}

