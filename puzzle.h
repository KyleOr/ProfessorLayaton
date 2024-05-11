#ifndef PUZZLE_H
#define PUZZLE_H

#include <string>
#include "character.h"
#include "locations.h"

class Puzzle 
{

public:
    void start_train_puzzle();
    
    static bool train_puzzle_completed; // Boolean variable to track the completion status 

    void start_drunk_imitation();

    static bool drunk_puzzle_completed;

    void start_priest_blackjack();

    static bool priest_puzzle_completed;



};




#endif
