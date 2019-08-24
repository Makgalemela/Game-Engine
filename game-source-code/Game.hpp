#ifndef GAME_HPP
#define GAME_HPP
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Cannon.hpp"
class Game
{
public:
    Game();
    void start();
    void gameLoop();
    ~Game();

private:
    sf::RenderWindow _window;
    sf::Sprite _backgroundSprite;
    sf::Texture _backgroundTexture;
    
    Cannon _cannon;
    
    void input();
    void update(float dtAsSeconds);
    void draw();

};

#endif // GAME_HPP
