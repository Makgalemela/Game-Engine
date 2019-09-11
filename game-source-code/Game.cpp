#include "Game.hpp"
#include <iostream>
Game::Game()
{
    _resolution.x = 1000.f;
    _resolution.y = 600.f;
    shotFired = false;
  
    _window.create(sf::VideoMode(_resolution.x, _resolution.y), "Duel Invader", sf::Style::Default);
   if(! _backgroundTexture.loadFromFile("../executables/resources/background.png")){
     std::cerr<<"Could not load the background image"<<std::endl;
   }
    _backgroundSprite.setTexture(_backgroundTexture);
    
}

void Game::start(){
   aliens.loadAliens();
   _defense.loadBlocks();
   _cannon.setInitPosOfCannon(_resolution);
   _window.setKeyRepeatEnabled(false);
    sf::Clock _clock;
    auto gamePlaying = false;
    while(_window.isOpen()){
        sf::Time datestamp = _clock.restart();
        float dtAsSeconds = datestamp.asSeconds();
        sf::Event event;
        while (_window.pollEvent(event))
        {
       // Request for closing the window
            if (event.type == sf::Event::Closed)
            _window.close();
            if(!gamePlaying){
            _window.draw(_splash.getSplash());
             _window.display();
                if((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Space)){
                    gamePlaying = true;
            }
        }
        if((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::F) && gamePlaying)
                    _cannon.startFiring();
        }
        
        if(gamePlaying){
            input();
            update(dtAsSeconds);
            draw();
            ///_cannon.collusion(aliens.aliensSpriteAlone());
            
        }
        
    }
}



void Game::input(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        _window.close();
        
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        _cannon.moveLeft();
    else 
        _cannon.StopLeft();
        
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        _cannon.moveRight();
    else 
        _cannon.stopRight();
        
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))
        if(!_collide.lowerCannonBlocks(_defense, _cannon))
            _cannon.moveUp();
        else
            _cannon.stopUp();
    else 
        _cannon.stopUp();
        
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        _cannon.moveDown();
    else 
        _cannon.stopDown();
            
}

void Game::update(float dtAsSeconds){
    _cannon.update(dtAsSeconds);
}

void Game::draw(){
    
    _window.clear(sf::Color::White);
    _window.draw(_backgroundSprite);
    _window.draw(_cannon.getSprite());
    _window.draw(_cannon.getSprite2());
    _cannon.fireBullet(_window, _cannon.getCannonCenterFirePosion());
    auto[_aliens, _aliensu, _alienPosition, _alienPositionu]  = aliens.aliensSprite();
    aliens.AlienMovement();
    auto[_blocks, _blockPosition] = _defense.Blocks();
    
    for(auto it =  0u; it != _aliens.size(); ++it){
        if(it == 18 || it == 36){
                _alienPosition.x -=540.f;
                _alienPosition.y +=35.f;
        }
            
            _aliens.at(it).setPosition(_alienPosition);
            _window.draw(_aliens.at(it));
            _alienPosition.x +=30.f;

            if(_aliens.size() != 0 && _cannon.collusion(_aliens.at(it).getPosition().x ,_aliens.at(it).getPosition().y )){
               aliens.deleteCollidedAlien(it);
            }
    }
       for(auto it =  0u; it != _aliensu.size(); ++it){
        if(it == 18 || it == 36){

                _alienPositionu.x -=540.f;
                _alienPositionu.y +=35.f;
        }
            
            _aliensu.at(it).setPosition(_alienPositionu);
            _window.draw(_aliensu.at(it));
            _alienPositionu.x +=30.f;

    }
    for(auto it =  0u; it != _blocks.size(); ++it){
        if(it == 4 ){
            _blockPosition.y = 540.f;
            _blockPosition.x -= 520.f;
        }
       _blocks.at(it).setPosition(_blockPosition);
       _window.draw(_blocks.at(it));
       _blockPosition.x +=130;
    }
    
    sampleText(_window);
   _window.display();
}
Game::~Game()
{
}

