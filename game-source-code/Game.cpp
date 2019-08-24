#include "Game.hpp"

Game::Game()
{
    sf::Vector2f _resolution;
    _resolution.x = 800;
    _resolution.y = 720;
    _window.create(sf::VideoMode(_resolution.x, _resolution.y), "Duel Invader", sf::Style::Default);
    _backgroundTexture.loadFromFile("../executables/resources/background.png");
    _backgroundSprite.setTexture(_backgroundTexture);
    
}

void Game::start(){
    
    
    sf::Clock _clock;
    
    while(_window.isOpen()){
        sf::Time datestamp = _clock.restart();
        float dtAsSeconds = datestamp.asSeconds();
        
        sf::Event event;
        while (_window.pollEvent(event))
        {
       // Request for closing the window
            if (event.type == sf::Event::Closed)
           _window.close();
        }
        
        input();
        update(dtAsSeconds);
        draw();

    }
}

void Game::input(){
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        _window.close();
        
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        _cannon.moveLeft();
    else 
        _cannon.StopLeft();
        
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        _cannon.moveRight();
    else 
        _cannon.stopRight();
}

void Game::update(float dtAsSeconds){
    _cannon.update(dtAsSeconds);
}

void Game::draw(){
    
    _window.clear(sf::Color::White);
    _window.draw(_backgroundSprite);
    _window.draw(_cannon.getSprite());
   _window.display();
}
Game::~Game()
{
}

