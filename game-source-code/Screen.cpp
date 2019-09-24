#include "Screen.hpp"

Screen::Screen()
{
    font.loadFromFile( "../executables/resources/sansation.ttf");
}


 void Screen::CannonLives(sf::RenderWindow &_window , const Cannon& _cannon){
        std::ostringstream ss;  
        ss<<_cannon.getCannonLives();
        std::string numberOfLives_(ss.str());
        sf::Text text("Lives : "+ numberOfLives_ , font);
        text.setCharacterSize(15);
        text.setStyle(sf::Text::Bold);
        text.setFillColor(sf::Color::White);
        text.setPosition(sf::Vector2f(700.f, 5.f));
        _window.draw(text);
    };
void Screen::elapsedTime(sf::RenderWindow &_window){
        std::ostringstream ss;
        double _time =getProcessTime();
        ss << (int)_time;
        std::string timeStr(ss.str());
        sf::Text text("Time : "+timeStr, font);
        text.setCharacterSize(15);
        text.setStyle(sf::Text::Bold);
        text.setFillColor(sf::Color::White);
        text.setPosition(sf::Vector2f(500.f, 5.f));
        _window.draw(text);
    
}

 void Screen::ScoreDraw(sf::RenderWindow &_window){
       std::ostringstream ss;   
       ss<<_score.getCurrentScore();
        std::string score_(ss.str());
        sf::Text text("Score : "+score_, font);
        text.setCharacterSize(15);
        text.setStyle(sf::Text::Bold);
        text.setFillColor(sf::Color::White);
        text.setPosition(sf::Vector2f(150.f, 5.f));
        _window.draw(text);
 }
Screen::~Screen()
{
}

