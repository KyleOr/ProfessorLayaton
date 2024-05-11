#ifndef GAME_H
#define GAME_H

#include <chrono>
#include <thread>
#include <vector>
#include "locations.h"

class Game 
{
public:
    Game();
    static void print_with_delay(const std::string& text, int delay = 50);
    void start();
    void show_introduction();
    


    // Other member functions


};

#endif
