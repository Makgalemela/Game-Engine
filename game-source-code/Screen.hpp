#ifndef SCREEN_HPP
#define SCREEN_HPP
#include <SFML/Graphics.hpp>
#include "StopWatch.h"
#include <sstream>
#include "Score.hpp"
#include "Cannon.hpp"


enum class ScreenType{
  Splashscreen = 0,   
  GameOverScreen,
  defaultScreen
};

class Screen : public StopWatch
{
public:
    Screen();
    ~Screen();
    void CannonLives(sf::RenderWindow &_window , const Cannon& _cannon);
    void elapsedTime(sf::RenderWindow &_window);
    void ScoreDraw(sf::RenderWindow &_window);
    void CannonLives(sf::RenderWindow &_window);
    virtual void setTexture(sf::Texture _texture){};
private:
 sf::Font font;
 Score _score;
};

#endif // SCREEN_HPP
