#include "Game.hpp"

Game::Game()
{
    sf::Vector2f _resolution;
    _resolution.x = 800.f;
    _resolution.y = 720.f;
    _window.create(sf::VideoMode(_resolution.x, _resolution.y), "Duel Invader", sf::Style::Default);
    _backgroundTexture.loadFromFile("../executables/resources/background.png");
    _backgroundSprite.setTexture(_backgroundTexture);
    
}

void Game::start(){
   aliens.loadAliens();
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
            ///_window.clear(sf::Color::White);
            _window.draw(_splash.getSplash());
             _window.display();
                if((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Space)){
                    gamePlaying = true;
            }
        }
        }
        
        if(gamePlaying){
            input();
            update(dtAsSeconds);
            draw();
            _cannon.collusion();
        }
        
    }
}



//void Game::draw()
//    auto[_aliens, _alienPosition]  = aliens.aliensSprite();
//    for(auto it =  _aliens.begin(); it != _aliens.end(); ++it){
//        //it.setPosition(_alienPosition);
//        sf::Sprite _currSprite = *it;
//         _currSprite.setPosition(_alienPosition);
//        _window.draw(_currSprite);
//        _alienPosition.x +=30.f;
//    }
//    
//}

void Game::gameLoop(){
    
    ///
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
        
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        _cannon.moveUp();
    else 
        _cannon.stopUp();
        
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        _cannon.moveDown();
    else 
        _cannon.stopDown();
        
     if(sf::Keyboard::isKeyPressed(sf::Keyboard::F))
        _cannon.startFiring();
}

void Game::update(float dtAsSeconds){
    _cannon.update(dtAsSeconds);
}

void Game::draw(){
    
    _window.clear(sf::Color::White);
    _window.draw(_backgroundSprite);
    _window.draw(_cannon.getSprite());
    _cannon.fireBullet(_window, _cannon.getCannonCenterFirePosion());
    auto[_aliens, _alienPosition]  = aliens.aliensSprite();
    for(auto it =  _aliens.begin(); it != _aliens.end(); ++it){
        sf::Sprite _currSprite = *it;
         _currSprite.setPosition(_alienPosition);
        _window.draw(_currSprite);
        _alienPosition.x +=30.f;
    }
    
    
   _window.display();
}
Game::~Game()
{
}

