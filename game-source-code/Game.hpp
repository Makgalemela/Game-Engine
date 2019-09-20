#ifndef GAME_HPP
#define GAME_HPP
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Cannon.hpp"
#include "SplashScreen.hpp"
#include "Aliens.hpp"
#include "Bullet.hpp"
//#include "DefenseBlocks.hpp"
#include "collusion.hpp"
#include "Screen.hpp"

// *****************************************************************
// 
// 
// the class is the main enginer it contain the game loop and
// draws game game window
// 
// *****************************************************************
class Game : public Screen {
public:
    Game();
    
//    **********************************************************************************
//    the method contain the main game loop and calls all other objects and their method;
//    
//    
//    \param return
//    
//    ********************************************************************************
    void start();
    void gameLoop();
    
    
    
    ~Game();

private:
    
    sf::RenderWindow _window;
    sf::Sprite _backgroundSprite;
    sf::Texture _backgroundTexture;
    SplashScreen _splash;
    Cannon _cannon;
    Aliens aliens;
    Bullet bullet;
    collusion _collide;
    DefenseBlocks _defense;
    sf::Vector2f _resolution;
    bool shotFired;
    sf::Sprite _GameOverSprite;
    sf::Texture _GameOverTexture;
//    **************************************************************************************
//    
//    this private methods is responsible for capturing the user imputs
//    
//    \param return 
//    
//    ****************************************************************************************
    
//    ****************************************************************************************
  
     void input();
//    
//    this method update the game time and position of the sprites on the Screen
//    
//    \param return
//    
//    
//    *****************************************************************************************
    void update(float dtAsSeconds);
    
    
//    
//    ******************************************************************************************
//    
//    this method draw objects of the windows
//    
//    
//    \param return 
//    
//
//    ******************************************************************************************
    
    
    void draw();
    ///void draw(const Aliens& aliens);


    FiringDirection fd;
    
    
    bool gameOver;
};

#endif // GAME_HPP
