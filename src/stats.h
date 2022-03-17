#ifndef STATS_H_
#define STATS_H_

#include <stdlib.h>
#include <iostream>
#include <stdio.h>

class Stats{

public:
    Stats(int size, int score, long timePlayed); // constructor
    ~Stats(); // 1 : destructor
    Stats(const Stats &source); // 2 : copy constructor
    Stats &operator=(const Stats &source); // 3 : copy assignment operator
    Stats(Stats &&source); // 4 : move constructor
    Stats &operator=(Stats &&source); // 5 : move assignment operator

    void GenerateStatsFile();

private:
    int _size;
    int *_data;
    int _score;
    long _timePlayed;
};

#endif