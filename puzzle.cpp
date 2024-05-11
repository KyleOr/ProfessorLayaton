#include "puzzle.h"
#include "splashkit.h"
#include <string>
#include <vector>
#include <algorithm>
#include "game.h"
#include "utils.h"
#include "locations.h"
#include "character.h"

using namespace std;

// Definition of the static variable
bool Puzzle::train_puzzle_completed = false;


void Puzzle::start_train_puzzle()
{
    // Display puzzle instructions
    #ifdef _WIN32 // For Windows
        system("cls");
    #else // For Unix-like systems (Linux, macOS)
            system("clear");
    #endif
    Game::print_with_delay("Train Schedule Conundrum", 50);
    write_line(" ");
    write_line("                            o x o x o x o . . .                                                         ");
    write_line("                            o      _____            _______________ ___=====__T___                      ");
    write_line("                        .][__n_n_|DD[  ====_____  |    |.\/.|   | |   |_|     |_                        ");
    write_line("                        >(________|__|_[_________]_|____|_/\_|___|_|___________|_|                      ");
    write_line("                        _/oo OOOOO oo`  ooo   ooo   o^o       o^o   o^o     o^o                         ");
    write_line("                -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-         ");
    write_line(" ");
    std::this_thread::sleep_for(std::chrono::seconds(2));  // Delay for 2 seconds
    write_line("========================");
    write_line("The conductor at the train station has lost the train schedule");
    write_line("and you must help him determine the correct order of the train departures.");
    write_line("The trains are named A, B, C, D, and E.");
    write_line("You have gathered the following clues:");
    write_line("1. Train C departs after Train A but before Train E.");
    write_line("2. Train B leaves before Train D.");
    write_line("3. Train E leaves sometime after Train B.");
    write_line("Using this information, deduce the correct order of the train departures (from earliest to latest).");

    // Solve the puzzle
    vector<string> trains = { "A", "B", "C", "D", "E" };
    vector<string> solution = { "A", "C", "E", "B", "D" };

    // Prompt the user for their answer and continue until the correct solution is provided
    while (true)
    {
        string userAnswer = read_string("Enter the correct order of train departures (e.g., ABCDE):");
        transform(userAnswer.begin(), userAnswer.end(), userAnswer.begin(), ::tolower); // Convert user's answer to lowercase

        // Check if the user's answer matches the solution
        if (userAnswer == "acebd")
        {
            write_line("Congratulations! You have solved the puzzle!");


            // Set the completion status to true
            train_puzzle_completed = true;


            // Modify the dialogue interactions with the conductor
            Game::print_with_delay("Conductor: Well done! I knew you were smart!", 50);
            write_line(" ");
            Game::print_with_delay("Conductor: Actually, I have this memory amulet that I will entrust in your hands and your brain. ", 50);
            write_line(" ");
            Game::print_with_delay("Conductor: I've been holding on to it to help visitors communicate with the people of Oakmont.  ", 50);
            write_line(" ");
            Game::print_with_delay("Conductor: I have a feeling you will be able to save this town if you communicate with the other townsfolks", 50);
            write_line(" ");
            Game::print_with_delay("You waved goodbye to the conductor", 50);
            write_line(" ");
            Location::display_train();
            // Provide further dialogue interactions with the conductor
            // ...
        }
        else
        {
            write_line("Oops! Your answer is incorrect. Keep trying!");
            // Allow the user to retry or provide additional feedback
        }

    }
}

bool Puzzle::drunk_puzzle_completed = false;


void Puzzle::start_drunk_imitation()
{
    #ifdef _WIN32 // For Windows
        system("cls");
    #else // For Unix-like systems (Linux, macOS)
            system("clear");
    #endif
    write_line("You approach the stumbling drunkard, who unsurprisingly, appears drunker than you...");
    Game::print_with_delay("Drunkard: Hic! Who're you? Wha'ya want?", 50);
    write_line(" ");

    // Game loop
    int round = 1;
    int sequenceLength = 3;
    bool gameOver = false;

    while (!gameOver && round <= 8)
    {
        write_line("Round " + to_string(round) + " - Pay attention to the drunkard's actions:");

        // Generate random actions for the drunkard
        vector<string> actions;
        for (int i = 0; i < sequenceLength; i++)
        {
            // Define a list of possible actions for the drunkard
            vector<string> possibleActions = {
                "Hiccup",
                "Stumble",
                "Burp",
                "Slur",
                "Trip"
            };

            // Generate a random index to select a random action from the list
            int index = rand() % possibleActions.size();

            // Add the randomly selected action to the actions vector
            actions.push_back(possibleActions[index]);
        }

        // Display the drunkard's actions
        for (const string& action : actions)
        {
            Game::print_with_delay("Drunkard: *" + action + "*", 50);
            write_line(" ");
        }

        // Player's turn
        write_line("Your turn. Repeat the sequence by entering each action separated by spaces:");

        string userInput = read_line();
        vector<string> userActions = split(userInput, ' ');

        // Check if the player's actions match the drunkard's actions
        if (userActions.size() != actions.size())
        {
            write_line("Drunkard: Hic! Ya didn't even try!");
            gameOver = true;
        }
        else
        {
            bool correct = true;
            for (int i = 0; i < actions.size(); i++)
            {
                if (userActions[i] != actions[i])
                {
                    correct = false;
                    break;
                }
            }

            if (correct)
            {
                write_line("Drunkard: Hic! You're good at this!");
                round++;
                sequenceLength++;
                Puzzle::drunk_puzzle_completed = true;
            }
            else
            {
                write_line("Drunkard: Hic! You messed up!");
                gameOver = true;
                Puzzle::drunk_puzzle_completed = false;
            }
        }

        write_line(" ");
    }

    // Game over
    Game::print_with_delay("The drunkard stumbles away and falls asleep.", 50);
    write_line(" ");
    Game::print_with_delay("You also fall asleep...", 50);
    write_line(" ");
    Game::print_with_delay("You eventually wake up and approach the house once more...", 50);
    write_line(" ");
    Location::display_house();

}

// Priest Blackjack 
vector<string> createDeck() 
{
    vector<string> deck;
    const vector<string> suits = { "Hearts", "Diamonds", "Clubs", "Spades" };
    const vector<string> ranks = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" };

    for (const string& suit : suits) 
    {
        for (const string& rank : ranks) 
        {
            deck.push_back(rank + " of " + suit);
        }
    }

    return deck;
}

void shuffleDeck(vector<string>& deck) 
{
    srand(static_cast<unsigned int>(time(nullptr)));

    for (size_t i = 0; i < deck.size(); ++i) 
    {
        size_t j = rand() % deck.size();
        swap(deck[i], deck[j]);
    }
}

void dealCard(vector<string>& deck, vector<string>& hand) 
{
    hand.push_back(deck.back());
    deck.pop_back();
}

int calculateHandValue(const vector<string>& hand) 
{
    int value = 0;
    int numAces = 0;

    for (const string& card : hand) 
    {
        char rank = card[0];

        if (rank == '2' || rank == '3' || rank == '4' || rank == '5' || rank == '6' ||
            rank == '7' || rank == '8' || rank == '9') 
        {
            value += rank - '0';
        }
        else if (rank == '1' || rank == 'J' || rank == 'Q' || rank == 'K') 
        {
            value += 10;
        }
        else if (rank == 'A') 
        {
            value += 11;
            numAces++;
        }
    }

    while (value > 21 && numAces > 0) 
    {
        value -= 10;
        numAces--;
    }

    return value;
}

void playerTurn(vector<string>& deck, vector<string>& playerHand) 
{
    while (true) 
    {
        write_line("Do you want to hit or stand? (h/s)");

        string choice = read_line();

        if (choice == "h") 
        {
            dealCard(deck, playerHand);

            write_line("Your hand: ");
            for (const string& card : playerHand) 
            {
                write(card + " ");
            }
            write_line("");

            int handValue = calculateHandValue(playerHand);
            if (handValue > 21) 
            {
                write_line("Busted! You lose.");
                return;
            }
        }
        else if (choice == "s") 
        {
            break;
        }
        else
        {
            write_line("Invalid input. Please enter 'h' to hit or 's' to stand.");
            continue;
            
        }
    }
}


void dealerTurn(vector<string>& deck, vector<string>& dealerHand) 
{
    write_line("Dealer's turn:");

    write_line("Dealer's hand: ");
    for (const string& card : dealerHand) 
    {
        write(card + " ");
    }
    write_line("");

    while (calculateHandValue(dealerHand) < 17) 
    {
        dealCard(deck, dealerHand);

        write_line("Dealer hits.");

        write_line("Dealer's hand: ");
        for (const string& card : dealerHand) 
        {
            write(card + " ");
        }
        write_line("");
    }

    int dealerHandValue = calculateHandValue(dealerHand);
    if (dealerHandValue > 21) 
    {
        write_line("Dealer busted! You win.");
    }
}

bool Puzzle::priest_puzzle_completed = false;

void determineWinner(const vector<string>& playerHand, const vector<string>& dealerHand) 
{
    int playerValue = calculateHandValue(playerHand);
    int dealerValue = calculateHandValue(dealerHand);

    if (playerValue > 21) 
    {
        Game::print_with_delay("Busted! You lose.", 50);
    }
    else if (dealerValue > 21) 
    {
        Game::print_with_delay("Dealer busted! You win.", 50);
        Puzzle::priest_puzzle_completed = true;
        write_line(" ");
        Game::print_with_delay("Priest: Ugh, get out of here!");
        write_line(" ");
        Location::display_church();
    } 
    else if (playerValue > dealerValue) 
    {
        Game::print_with_delay("Congratulations! You win.", 50);
        Puzzle::priest_puzzle_completed = true;
        write_line(" ");
        Game::print_with_delay("Priest: Ugh, get out of here!");
        write_line(" ");
        Location::display_church();
    } 
    else if (playerValue < dealerValue) 
    {
        Game::print_with_delay("Dealer wins. You lose.", 50);
    } 
    else 
    {
        Game::print_with_delay("It's a tie.", 50);
    }
}


void Puzzle::start_priest_blackjack() 
{
    #ifdef _WIN32 // For Windows
    system("cls");
    #else // For Unix-like systems (Linux, macOS)
        system("clear");
    #endif
    write_line("Welcome to the Priest's Blackjack Challenge!");

    bool is_priest_puzzle_completed = false;
    while (!is_priest_puzzle_completed) 
    {
        vector<string> deck = createDeck();
        shuffleDeck(deck);

        vector<string> playerHand;
        vector<string> dealerHand;

        dealCard(deck, playerHand);
        dealCard(deck, dealerHand);
        dealCard(deck, playerHand);
        dealCard(deck, dealerHand);

        write_line("Your hand: ");
        for (const string& card : playerHand) 
        {
            write(card + " ");
        }
        write_line("");

        write_line("Dealer's hand: ");
        write(dealerHand[0] + " [HIDDEN]");
        write_line("");

        playerTurn(deck, playerHand);
        dealerTurn(deck, dealerHand);
        determineWinner(playerHand, dealerHand);

        is_priest_puzzle_completed = Puzzle::priest_puzzle_completed;

        if (!is_priest_puzzle_completed) 
        {
            write_line("Do you want to try again? (y/n)");

            string choice = read_line();

            if (choice != "y") 
            {
                break;
            }
            else
            {
                // Clear hands for a new round
                playerHand.clear();
                dealerHand.clear();
                continue;  // Restart the loop for a new round
            }
        }
    }
}
