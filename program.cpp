#include "splashkit.h"
#include "game.h"
#include <windows.h>


int main()
{
    SetConsoleOutputCP(CP_UTF8); // Set console output to UTF-8 encoding

    Game game;
    game.start();

    return 0;
}


