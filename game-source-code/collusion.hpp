#ifndef COLLUSION_HPP
#define COLLUSION_HPP
#include <SFML/Graphics.hpp>
#include "Cannon.hpp"
#include "DefenseBlocks.hpp"
#include <vector>
#include <tuple>

class collusion
{
public:
    collusion();
    
    bool lowerCannonBlocks(const DefenseBlocks& def , const Cannon & _cannon);
    ~collusion();
private:
};

#endif // COLLUSION_HPP
