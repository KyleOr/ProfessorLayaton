#include "game.h"
#include "splashkit.h"
#include <string>
#include <chrono>
#include <thread>
#include "locations.h"
#include <cstdlib>
#include "utils.h"

using namespace std;

Game::Game()
{
    // Initialize game state
}


// Function to print text with a delay
void Game::print_with_delay(const string& text, int delay)
{
    for (char c : text)
    {
        write(c);
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
}

void Game::start()
{
    show_introduction();
    // Other game logic
}


void Game::show_introduction()
{
    string playerName;
    bool nameConfirmed = false;

    while (!nameConfirmed)
    {
        playerName = read_string("Please enter your name: ");
        write_line("Your name is: " + playerName);

        // Prompt for name confirmation
        string confirmation = read_string("Is this correct? (Y/N): ");
        if (confirmation == "Y" || confirmation == "y")
        {
            nameConfirmed = true;
        }
    }

    // Text to be displayed
    vector<string> introduction_text = {
        "Welcome, " + playerName + ", to 'The Enigma of Lost Memories'!",
        "In a quaint town known for its rich history and enigmatic secrets, a strange phenomenon has taken hold. The people of Oakmont are losing their memories, forgetting important events and even their own identities.",
        "As " + playerName + ", a brilliant archaeologist with a passion for puzzles and a deep curiosity about the unknown, you have arrived in this town to uncover the truth behind this mysterious memory loss.",
        "Your expertise in unraveling mysteries makes you the perfect person for the task at hand.",
        "As you explore the forgotten town, interact with its residents, and solve a series of intricate puzzles, you will gradually restore the lost memories and uncover the secrets that lie within.",
        "Prepare yourself for a journey filled with captivating puzzles, intriguing characters, and a hidden history waiting to be unraveled.",
        "Are you ready to embark on this adventure and restore the memories of Oakmont?",
        "Press [Enter] to continue"
        // Other introduction messages
    };

    // Display each line with a delay
    for (const string& line : introduction_text)
    {
        print_with_delay(line);
        write_line(); // Move to the next line
    }

    string userInput = read_line();
    if (userInput.empty())
    {
        // User pressed Enter, proceed with the game
        // Clear the terminal screen using system-specific commands
        #ifdef _WIN32 // For Windows
                system("cls");
        #else // For Unix-like systems (Linux, macOS)
                system("clear");
        #endif
        // Print the town square
        Location::display_town_square();
    }
    else
    {
        // User entered something other than Enter, handle accordingly (e.g., display a different message or exit the game)
    }
}
 

