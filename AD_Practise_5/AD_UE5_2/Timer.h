#ifndef TIMER_H
#define TIMER_H
#include <time.h>

class Timer
{
    public:
        Timer() { time = 0.0; }
        void start(){ start_time = clock(); }
        void stop(){ time += clock() - start_time; }
        void clear() {time = 0.0; }
        double getTime(){ return time / CLOCKS_PER_SEC; }

    private:
        double start_time;
        double time;
};

#endif // TIMER_H
