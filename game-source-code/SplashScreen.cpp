#include "SplashScreen.hpp"
#include <iostream>
SplashScreen::SplashScreen()
{}

 sf::Sprite SplashScreen::getSplash() const{
     return _splashSprite;
 }
 
 void SplashScreen::setTexture(sf::Texture _splashTexture ){
    this->_splashTexture = _splashTexture;
    _splashSprite.setTexture(this->_splashTexture);
    _splashSprite.scale(sf::Vector2f(0.85f , 1.f));
     return;
 }
 
 
SplashScreen::~SplashScreen()
{
}

