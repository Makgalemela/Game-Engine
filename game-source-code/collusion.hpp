#ifndef COLLUSION_HPP
#define COLLUSION_HPP
#include <SFML/Graphics.hpp>
#include "DefenseBlocks.hpp"
#include "Aliens.hpp"
#include <vector>
#include <tuple>

class collusion
{
public:
    collusion();
    
    bool alienShotPlayerCannon(Aliens aliens);
    ~collusion();
private:
};

#endif // COLLUSION_HPP
