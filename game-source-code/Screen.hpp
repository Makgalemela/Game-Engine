#ifndef SCREEN_HPP
#define SCREEN_HPP
#include <SFML/Graphics.hpp>
#include "StopWatch.h"
#include <sstream>
#include "Score.hpp"
class Screen : public StopWatch
{
public:
    Screen();
    ~Screen();
    void sampleText(sf::RenderWindow &_window);
    void elapsedTime(sf::RenderWindow &_window);
    void ScoreDraw(sf::RenderWindow &_window);
private:
 sf::Font font;
 Score _score;
};

#endif // SCREEN_HPP
