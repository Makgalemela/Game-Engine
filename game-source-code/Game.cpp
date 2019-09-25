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
            powerAliens();
        }
        
    }
}



void Game::input(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        _window.close();
        
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        _cannon.move(Direction::Left , EntityId::Cannon1);
    else 
        _cannon.stopMove(Direction::Left , EntityId::Cannon1);
        
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        _cannon.move(Direction::Right , EntityId::Cannon1);
    else 
        _cannon.stopMove(Direction::Right , EntityId::Cannon1);
        

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        _cannon.move(Direction::Left , EntityId::Cannon2);
    else 
        _cannon.stopMove(Direction::Left , EntityId::Cannon2);
        
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        _cannon.move(Direction::Right , EntityId::Cannon2);
    else 
        _cannon.stopMove(Direction::Right , EntityId::Cannon2);
    
    return;
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

void Game::powerAliens(){
    
    int firingTimes = 0;
    if(_watch.alienFiringInterval()){
        while(firingTimes < 2){
        for(auto itr  = 0u ; itr != 2; ++itr){
            auto[_pos , orientation] = aliens.getAlienFiringPosition(itr);
            _cannon.aliensFiring(_pos, orientation);
            }
                firingTimes++;
        }
    }
   return;  
}

  void Game::loadCannon(ResourceManager _rm){
      _rm.loadResources(ResourceID::LowerCannon, "../executables/resources/Laser_Cannon.png");
      _cannon.setTexture(_rm.get(ResourceID::LowerCannon), 0);
      
      _rm.loadResources(ResourceID::UpperCannon, "../executables/resources/Laser_Cannonc.png");
      _cannon.setTexture(_rm.get(ResourceID::UpperCannon), 1);
      
      _rm.loadResources( ResourceID::Bullets, "../executables/resources/bullet.png");
      _cannon.setTexture(_rm.get(ResourceID::Bullets), 3);
      
       _rm.loadResources( ResourceID::DownFacingAlienFirst , "../executables/resources/aliens.png");
       aliens.setTexture(_rm.get(ResourceID::DownFacingAlienFirst),2);
       
        _rm.loadResources( ResourceID::DownFacingAlienSecond , "../executables/resources/alien2.png");
         aliens.setTexture(_rm.get(ResourceID::DownFacingAlienSecond),1);
         
       _rm.loadResources( ResourceID::DownFacingAlienThird , "../executables/resources/alien3.png");
        aliens.setTexture(_rm.get(ResourceID::DownFacingAlienThird),0);
        
         _rm.loadResources( ResourceID::UpFacingAlienFirst , "../executables/resources/aliensc.png");
          aliens.setTexture(_rm.get(ResourceID::UpFacingAlienFirst),3);
          
        _rm.loadResources( ResourceID::UpFacingAlienSecond , "../executables/resources/alien2c.png");
         aliens.setTexture(_rm.get(ResourceID::UpFacingAlienSecond),4);
         
       _rm.loadResources( ResourceID::UpFacingAlienThird , "../executables/resources/alien3c.png");
        aliens.setTexture(_rm.get(ResourceID::UpFacingAlienThird),5);
        
        _rm.loadResources(ResourceID:: Splash, "../executables/resources/splash.png" );
        _splash.setTexture(_rm.get(ResourceID:: Splash));
  }
  
  
Game::~Game()
{
}

