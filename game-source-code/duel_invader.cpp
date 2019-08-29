#include <iostream>
#include <ctype.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Game.hpp"
#include "Aliens.hpp"

int main(){
    
//    constexpr unsigned _height = 1000;
//    constexpr unsigned _width = 800;
    
     auto aliens = Aliens{};
     auto game = Game{};
   
    
    game.start();
 
    return 0;
}