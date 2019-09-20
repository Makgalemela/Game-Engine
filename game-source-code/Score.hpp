#ifndef SCORE_HPP
#define SCORE_HPP

#include <iostream>
#include <fstream>

enum class Scores{
    Ten,
    Twenty, 
    ThirtyFive
};
class Score
{
public:
    Score();
    ~Score();
    void writehighscore();
    int readhighscore();
    int getCurrentScore() const;
    void setScore(Scores _score);
    
private:
    std::ifstream in;
    std::ofstream out;
    int _highscore;
};

#endif // SCORE_HPP
