#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>


class Character {
private:
    // Other member variables

public:
    // Constructor
    Character();

    // Other member variables
    static bool memory_flask_dialogue_played;

    static bool enigma_key_dialogue_played;


    // Function to interact with the conductor
    static void display_conductor(); 
    
    static void display_drunkard();

    static void display_priest();


};


#endif
