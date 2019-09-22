#include "Game.hpp"
#include <iostream>
Game::Game()
{
    _resolution.x = 1000.f;
    _resolution.y = 600.f;
    shotFired = false;
    gameOver = false;
    _window.create(sf::VideoMode(_resolution.x, _resolution.y), "Duel Invader", sf::Style::Default);
   if(! _backgroundTexture.loadFromFile("../executables/resources/background.png") ||
    ! _GameOverTexture.loadFromFile("../executables/resources/GameOver.png")){
     std::cerr<<"Could not load the background image"<<std::endl;
   }
    _backgroundSprite.setTexture(_backgroundTexture);
    _GameOverSprite.setTexture(_GameOverTexture);
    
    ResourceManager _rm;
    loadCannon(_rm);
}

void Game::start(){
   aliens.loadAliens();
   _defense.loadBlocks();
   _cannon.setInitPosOfCannon(_resolution);
   _window.setKeyRepeatEnabled(false);
    aliens.setAlienPosition();
    sf::Clock _clock;
    auto gamePlaying = false;
    while(_window.isOpen()){
        sf::Time datestamp = _clock.restart();
        float dtAsSeconds = datestamp.asSeconds();
        sf::Event event;
        while (_window.pollEvent(event))
        { 
            
            
            if (event.type == sf::Event::Closed)
            _window.close();
            if(gameOver){
                if((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
                    _window.close();
            }
            else if(!gamePlaying){
            _window.draw(_splash.getSplash());
                if((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Space)){
                    gamePlaying = true;
            }

        }
         _window.display();
            if((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Up) && gamePlaying)
                       _cannon.startFiring(FiringDirection::down, _cannon.getCannon2CenterFirePosition());
                       
            if((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::F) && gamePlaying)
                      _cannon.startFiring(FiringDirection::up ,_cannon.getCannonCenterFirePosition());
        }

        if(_gamestate.GameOver(_cannon, aliens)){
                gamePlaying =false;
                gameOver = true;
                _window.draw(_GameOverSprite);
                _window.display();
            }
        else if(gamePlaying){
            input();
            update(dtAsSeconds);
            draw();
            _cannon.cannonIsShot();
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
            _cannon.moveUp();
    else 
        _cannon.stopUp();
        
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        _cannon.moveDown();
    else 
        _cannon.stopDown();
        
    
    
    ///Top cannon
    

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        _cannon.moveLeftTop();
    else 
        _cannon.StopLeftTop();
        
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        _cannon.moveRightTop();
    else 
        _cannon.stopRightTop();
            
}

void Game::update(float dtAsSeconds){
    _cannon.update(dtAsSeconds);
}


///This need to be factored out
void Game::draw(){
     
    _window.clear(sf::Color::White);
    _window.draw(_backgroundSprite);
    _window.draw(_cannon.getSprite());
        //_cannon.DrawCannon(_window);
    _window.draw(_cannon.getSprite2());
    
    _cannon.fireBullet(_window);    
    _cannon.BulletOutOfScreen();
    auto[_aliens, _aliensu]  = aliens.aliensSprite();  
    for(auto it = 0u;  it != _aliens.size(); ++it){
          if(aliens.IsAlienAlive(it, AliensDirection::DownFace)){
              if( _cannon.alienShoot(_aliens.at(it), AliensDirection::DownFace)) 
                  aliens.alienIsShot(it,AliensDirection::DownFace);
                _window.draw(_aliens.at(it));
          }
        
    }
    for(auto it = 0u;  it != _aliensu.size(); ++it){
        if(aliens.IsAlienAlive(it, AliensDirection::UpFace)){
             if(_cannon.alienShoot(_aliensu.at(it), AliensDirection::UpFace)) 
            aliens.alienIsShot(it,AliensDirection::UpFace);
            _window.draw(_aliensu.at(it));
        }
    }

    _cannon.BulletsCollusion(_window);

    CannonLives(_window,_cannon);
    elapsedTime(_window);
    ScoreDraw(_window);
    aliens.alienIsMoving(_window);
   _window.display();
}




  void Game::loadCannon(ResourceManager _rm){
      _rm.loadResources(ResourceID::LowerCannon, "../executables/resources/Laser_Cannon.png");
      _cannon.setCannons(_rm.get(ResourceID::LowerCannon));
  }
  
  
Game::~Game()
{
}






































//    for(auto it =  0u; it != _blocks.size(); ++it){
//        if(it == 4 ){
//            _blockPosition.y = 540.f;
//            _blockPosition.x -= 520.f;
//        }
//       _blocks.at(it).setPosition(_blockPosition);
//       _window.draw(_blocks.at(it));
//       _blockPosition.x +=130;
//    }
    


//    auto[_blocks, _blockPosition] = _defense.Blocks();
    
//    for(auto it =  0u; it != _aliens.size(); ++it){
//        if(it == 18 || it == 36){
//                _alienPosition.x -=540.f;
//                _alienPosition.y +=35.f;
//        }
//            _aliens.at(it).setPosition(_alienPosition);
//            _window.draw(_aliens.at(it));
//            _alienPosition.x +=30.f;
//
//            if(_aliens.size() != 0 && _cannon.collusion(_aliens.at(it).getPosition().x ,_aliens.at(it).getPosition().y )){
//               aliens.deleteCollidedAlien(it);
//                }
////            else if(_aliens.size() != 0 && _cannon.collusion2(_aliens.at(it).getPosition().x ,_aliens.at(it).getPosition().y )){
////               aliens.deleteCollidedAlien(it,AliensDirection::UpFace);
////            }
//    }
//    
//    
//       for(auto it =  0u; it != _aliensu.size(); ++it){
//            if(it == 18 || it == 36){
//                _alienPositionu.x -=540.f;
//                _alienPositionu.y +=35.f;
//            }
//            
//            _aliensu.at(it).setPosition(_alienPositionu);
//            _window.draw(_aliensu.at(it));
//            _alienPositionu.x +=30.f;
//            
////              if(_aliensu.size() != 0 && _cannon.collusion(_aliensu.at(it).getPosition().x ,_aliensu.at(it).getPosition().y )){
////               aliens.deleteCollidedAlien(it);
////                }
//             if(_aliensu.size() != 0 && _cannon.collusion2(_aliensu.at(it).getPosition().x ,_aliensu.at(it).getPosition().y )){
//               aliens.deleteCollidedAlien(it, AliensDirection::UpFace);
//            }
//
//    }