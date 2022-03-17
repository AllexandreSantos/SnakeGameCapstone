#include <stdlib.h>
#include <iostream>
#include <fstream>  
#include <chrono>
#include <stdio.h>
#include <stats.h>

Stats::Stats(int size, int score, long timePlayed) // constructor
{   
    _size = size;
    _data = new int[_size];
    std::cout << "CREATING instance of StatsClass at " << this << " allocated with size = " << _size*sizeof(int)  << " bytes" << std::endl;

    _score = score;
    _timePlayed = timePlayed;
}

Stats::~Stats() // 1 : destructor
{
    std::cout << "DELETING instance of StatsClass at " << this << std::endl;
    delete[] _data;
}

Stats::Stats(const Stats &source) // 2 : copy constructor
{
 
    _size = source._size;
    _data = new int[_size];
    *_data = *source._data;
    std::cout << "COPYING content of instance " << &source << " to instance " << this << std::endl;

    _score = source._score;
    _timePlayed = source._timePlayed;
}

Stats &Stats::operator=(const Stats &source) // 3 : copy assignment operator
{
    std::cout << "ASSIGNING content of instance " << &source << " to instance " << this << std::endl;
    if (this == &source)
        return *this;
    delete[] _data;
    _data = new int[source._size];
    *_data = *source._data;
    _size = source._size;

    _score = source._score;
    _timePlayed = source._timePlayed;

    return *this;
}

Stats::Stats(Stats &&source) // 4 : move constructor
{
    std::cout << "MOVING (c’tor) instance " << &source << " to instance " << this << std::endl;
    _data = source._data;
    _size = source._size;
    source._data = nullptr;
    source._size = 0;


    _score = source._score;
    _timePlayed = source._timePlayed;
    source._score = 0;
    source._timePlayed = 0;
}

Stats &Stats::operator=(Stats &&source) // 5 : move assignment operator
{
    std::cout << "MOVING (assign) instance " << &source << " to instance " << this << std::endl;
    if (this == &source)
        return *this;

    delete[] _data;

    _data = source._data;
    _size = source._size;
    source._data = nullptr;
    source._size = 0;

    _score = source._score;
    _timePlayed = source._timePlayed;
    source._score = 0;
    source._timePlayed = 0;

    return *this;
}

void Stats::GenerateStatsFile()
{
    std::cout << "Game has terminated successfully!\n";
    std::cout << "Score: " << _score << "\n";
    std::cout << "Size: " << _size << "\n";

    std::ofstream outfile ("stats.txt");
    outfile << "Score: " << _score << std::endl;
    outfile << "Size: " << _size << std::endl;
    outfile << "Time played: " << _timePlayed << " seconds." << std::endl;
    outfile.close();
}
