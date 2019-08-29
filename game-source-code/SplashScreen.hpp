#ifndef SPLASHSCREEN_HPP
#define SPLASHSCREEN_HPP
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


//***************************************************************
//
//this class create  the splash screen and the instrucstion screen
//
//
//***************************************************************

class SplashScreen 
{
public:

//    ***********************************************************
//     splashscreem object is loaded using the construct 
//     
//     
//    ***********************************************************
    SplashScreen();
    ~SplashScreen();
    
//    **************************************
//    
//    this method return spalshscreen object
//    
//    \param return sprite
//    ***************************************
    sf::Sprite getSplash() const;
private:
     sf::Vector2f _position;
    sf::Texture _splashTexture;
    sf::Sprite _splashSprite;
};

#endif // SPLASHSCREEN_HPP
