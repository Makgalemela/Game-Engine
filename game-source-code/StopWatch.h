#ifndef STOPWATCH_H
#define STOPWATCH_H



class StopWatch{
    
    
private:
    double ellapsedtime;
    double alienFiringInt;
public:
    double getProcessTime();
    bool timerForMovement();
    bool alienFiringInterval();
    StopWatch();
};



#endif
