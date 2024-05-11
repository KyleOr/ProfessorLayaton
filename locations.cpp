#include "locations.h"
#include "splashkit.h"
#include "game.h"
#include <string>
#include "utils.h"
#include <random>
#include "character.h"
#include "puzzle.h"
#ifdef _WIN32 // For Windows
#include <cstdlib>
#define CLEAR_COMMAND "cls"
#define EXIT_COMMAND "exit"
#else // For Unix-like systems (Linux, macOS)
#include <cstdlib>
#define CLEAR_COMMAND "clear"
#define EXIT_COMMAND "exit"
#endif


using namespace std;

void end_game() 
{
    // Game ending logic...

    // Clear the terminal
    system(CLEAR_COMMAND);

    // Display the final message
    write_line("Game Over");

    // Add the terminal exit command
    system(EXIT_COMMAND);
}

void print_with_delay(const string& text, int delay)
{
    for (char c : text)
    {
        write(c);
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
}




void Location::display_town_square()
{
    print_with_delay("Travelling to the Town Square...",50);
    write_line(" ");
    std::this_thread::sleep_for(std::chrono::seconds(2));  // Delay for 2 seconds
    write_line("                                                           |>>>                 ");
    write_line("                   _                      _                |                    ");
    write_line("    ____________ .' '.    _____/----/-\ .' './========\   / \                   ");
    write_line("   //// ////// /V_.-._\  |.-.-.|===| _ |-----| u    u |  /___\                  ");
    write_line("  // /// // ///==\ u |.  || | ||===||||| |T| |   ||   | .| u |_ _ _ _ _ _       ");
    write_line(" ///////-\////====\==|:::::::::::::::::::::::::::::::::::|u u| U U U U U        ");
    write_line(" |----/\  |--|++++|..|'''''''''''::::::::::::::''''''''''|+++|+-+-+-+-+-+       ");
    write_line(" |u u|u | |u ||||||..|              '::::::::'           |===|>=== _ _ ==       "); 
    write_line(" |===|  |u|==|++++|==|              .::::::::.           | T |....| V |..       ");
    write_line(" |u u|u | |u ||HH||         \|/    .::::::::::.                                 ");
    write_line(" |===|_.|u|_.|+HH+|_              .::::::::::::.              _                 ");   
    write_line("                __(_)___         .::::::::::::::.         ___(_)__              ");
    write_line("---------------/  / \  /|       .:::::;;;:::;;:::.       |\  / \  \-------      ");
    write_line("______________/_______/ |      .::::::;;:::::;;:::.      | \_______\________    ");
    write_line("|       |     [===  =] /|     .:::::;;;::::::;;;:::.     |\ [==  = ]   |        ");
    write_line("|_______|_____[ = == ]/ |    .:::::;;;:::::::;;;::::.    | \[ ===  ]___|____    ");
    write_line("     |       |[  === ] /|   .:::::;;;::::::::;;;:::::.   |\ [=  ===] |          ");
    write_line("_____|_______|[== = =]/ |  .:::::;;;::::::::::;;;:::::.  | \[ ==  =]_|______    ");
    write_line(" |       |    [ == = ] /| .::::::;;:::::::::::;;;::::::. |\ [== == ]      |     ");
    write_line("_|_______|____[=  == ]/ |.::::::;;:::::::::::::;;;::::::.| \[  === ]______|_    ");
    write_line("   |       |  [ === =] /.::::::;;::::::::::::::;;;:::::::.\ [===  =]   |        ");
    write_line(" ");
    print_with_delay("The wind rustles through the trees",50);
    write_line(" ");

    while (true)
    {
        write_line("\n=== Town Square ===");
        write_line("1. Explore the Town Square");
        write_line("2. Go to Oakmont Station");
        write_line("3. Go to Strange House");
        write_line("4. Go to Oakmont Church");
    
    int choice = read_integer("Enter your choice: ");

        if (choice == 1)
        {
            if (Puzzle::priest_puzzle_completed && Character::enigma_key_dialogue_played == true)
            {
            Game::print_with_delay("You notice the amulet is glowing...", 20);
            write_line(" ");
            Game::print_with_delay("You: Something must be triggering the amulet around here.", 20);
            write_line(" ");
            Game::print_with_delay("Curious, you take out the memory flask and use it as a magnifying glass to get a closer look at the amulet.", 50);
            write_line(" ");
            Game::print_with_delay("To your surprise, as you bring the flask closer, the amulet starts emitting intense heat.", 50);
            write_line(" ");
            Game::print_with_delay("Suddenly, the amulet explodes into a colorful gas that envelops the entire town square.", 50);
            write_line(" ");
            Game::print_with_delay("As the gas spreads, you see the residents of Oakmont gasping in amazement.", 50);
            write_line(" ");
            Game::print_with_delay("In an instant, the gas clears, and the town is filled with a renewed sense of life and memories.", 50);
            write_line(" ");
            Game::print_with_delay("The townspeople rejoice as their forgotten memories flood back, and the town is once again vibrant and lively.", 50);
            write_line(" ");
            Game::print_with_delay("Congratulations! You have successfully restored the memories of Oakmont and brought back its colorful history.", 50);
            write_line(" ");
            Game::print_with_delay("You hear the conductor running towards you...",50);
            write_line(" ");
            Game::print_with_delay("Conductor: THAT TOP HAT I KNEW IT!",10);
            write_line(" ");
            Game::print_with_delay("You quickly remember that you are not a detective of sort, but that you are a con artist and have stolen the Conductor's Train Schedule",50);
            write_line(" ");
            end_game();
            }
            else
            {
                // Perform actions specific to exploring the Town Square
                write_line("You explore the Town Square.");
                write_line(" ");
                std::vector<std::string> townsquare_ambience_messages = {
                    "A kid compliments your top hat.",
                    "You hear the sound of a street performer playing the violin.",
                    "The smell of freshly baked pastries wafts through the air.",
                    "You spot a stray cat napping under a bench.",
                    "The fountain in the center of the square sparkles under the sunlight."
                };
                std::random_device rd;
                std::mt19937 generator(rd());
                std::uniform_int_distribution<int> distribution(0, townsquare_ambience_messages.size() - 1);
                int randomIndex = distribution(generator);
                print_with_delay(townsquare_ambience_messages[randomIndex], 50);
                write_line(" ");
                
            }
        }
        else if (choice == 2)
        {
            // Go to Location 2
            print_with_delay("You decide to visit Oakmont Station ",50);
            display_train();
            break;  // Exit the loop to go to Location 2
        }
        else if (choice == 3)
        {
            // Go to Location 3
            write_line("You decide to visit the Strange House.");
            display_house();
            break;  // Exit the loop to go to Location 3
        }
        else if (choice == 4)
        {
            // Go to Location 4
            write_line("You decide to visit Oakmont Church.");
            display_church();
            break;  // Exit the loop to go to Location 4
        }
        else
        {
            write_line("Invalid choice. Please try again.");

        }
    }

}

void Location::display_train()
{
    write_line(" ");
    print_with_delay("walking to Oakmont Station...",50);
    write_line(" ");
    std::this_thread::sleep_for(std::chrono::seconds(2));  // Delay for 2 seconds
    write_line("                                              ___..--'  .`.                   ");
    write_line("                                     ___...--'     -  .` `.`.                ");
    write_line("                            ___...--' _      -  _   .` -   `.`.                 ");
    write_line("                   ___...--'  -       _   -       .`  `. - _ `.`.               ");
    write_line("            __..--'_______________ -         _  .`  _   `.   - `.`.             ");
    write_line("            .   _ /\    -        .`      _     .`__________`. _  -`.`.        ");
    write_line("        .` -   _ /  \_     -   .`  _         .`   |Train Depot|`.   - `.`.        ");
    write_line("        .`-  _  /   /\   -   .`        _   .`   |___________|  `. _   `.`.    ");
    write_line("    .`________ /__ /_ \____.`____________.`     ___       ___  - `._____`|      ");
    write_line("        |   -  __  -|    | - |  ____  |   | | _  |   |  _  |   |  _ |           ");
    write_line("        | _   |  |  | -  |   | |.--.| |___| |    |___|     |___|    |           ");
    write_line("        |     |--|  |    | _ | |'--'| |---| |   _|---|     |---|_   |           ");
    write_line("        |   - |__| _|  - |   | |.--.| |   | |    |   |_  _ |   |    |           ");
    write_line("    ---``--._       |    |   |=|'--'|=|___|=|====|___|=====|___|====|            ");
    write_line("    -- . ''  ``--. _| _  |  -|_|.--.|_______|_______________________|            ");
    write_line("    `--._           '--- |_  |:|'--'|:::::::|:::::::::::::::::::::::|           ");
    write_line("    _____`--._ ''      . '---'``--._|:::::::|:::::::::::::::::::::::|           ");
    write_line("    ----------`--._          ''      ``--.._|:::::::::::::::::::::::|           ");
    write_line("    `--._ _________`--._'        --     .   ''-----..............   '           ");
    write_line("        `--._----------`--._.  _           -- . :''           -    ''           ");
    write_line("            `--._ _________`--._ :'              -- . :''      -- . ''          ");
    write_line("    -- . ''       `--._ ---------`--._   -- . :''                               ");
    write_line("            :'        `--._ _________`--._:'  -- . ''      -- . ''              ");
    write_line("    -- . ''     -- . ''    `--._----------`--._      -- . ''     -- . ''        ");
    write_line("                                `--._ _________`--._                            ");
    write_line("    -- . ''           :'              `--._ ---------`--._-- . ''    -- . ''    ");
    write_line("            -- . ''       -- . ''         `--._ _________`--._   -- . ''        ");
    write_line("    :'                 -- . ''          -- . ''  `--._----------`--._           ");
    write_line(" ");
    print_with_delay("You are at Oakmont Station.",50);
    write_line(" ");

    while (true)
    {
        write_line("\n=== Oakmont Station ===");
        write_line("1. Explore the station");
        write_line("2. Meet the conductor");
        write_line("3. Return to the Town Square");

        int choice = read_integer("Enter your choice: ");
        
        if (choice == 1)
        {
            // Perform actions specific to exploring the station
            write_line("You explore the station.");
            write_line(" ");

        std::vector<std::string> train_ambience_messages = {
            "You hear the sound of a train arriving at the platform.",
            "The hustle and bustle of passengers fills the air.",
            "The station announcements echo through the corridors.",
            "You see a group of travelers huddled together, studying a map.",
            "The scent of coffee wafts from the station cafe."
        };

        std::random_device rd;
        std::mt19937 generator(rd());
        std::uniform_int_distribution<int> distribution(0, train_ambience_messages.size() - 1);
        int randomIndex = distribution(generator);
        print_with_delay(train_ambience_messages[randomIndex], 50);
            // Add your code here for exploring the station
        write_line(" ");
        }

        else if (choice == 2)
        {
            write_line(" ");
            print_with_delay("You call out for the conductor...",50);
            write_line(" ");
            Character::display_conductor(); 
        }
        else if (choice == 3)
        {

            // Perform actions to return to the Town Square
            display_town_square();
        }
        else
        {
            write_line("Invalid choice. Please try again.");
        }
    }


// Display other information or interactions specific to Location 2

}


void Location::display_house()
{
    write_line(" ");
    print_with_delay("walking to the Strange House...",50);
    write_line(" ");
    std::this_thread::sleep_for(std::chrono::seconds(2));  // Delay for 2 seconds
    write_line("                    (                                             ");
    write_line("                    )                                             ");
    write_line("               (            ./\.                                  ");
    write_line("            |^^^^^^^^^|   ./LLLL\.                                ");   
    write_line("            |`.'`.`'`'| ./LLLLLLLL\.                              ");
    write_line("            |.'`'.'`.'|/LLLL/^^\LLLL\.                            ");
    write_line("            |.`.''``./LLLL/^ () ^\LLLL\.                          ");
    write_line("            |.'`.`./LLLL/^  =   = ^\LLLL\.                        ");
    write_line("            |.`../LLLL/^  _.----._  ^\LLLL\.                      ");
    write_line("            |'./LLLL/^ =.' ______ `.  ^\LLLL\.                    ");
    write_line("            /LLLL/^   /|--.----.--|\ =  ^\LLLL\.                  ");
    write_line("          ./LLLL/^  = |=|__|____|__|=|    ^\LLLL\.                ");
    write_line("        ./LLLL/^=     |*|~~|~~~~|~~|*|   =  ^\LLLL\.              ");
    write_line("      ./LLLL/^        |=|--|----|--|=|        ^\LLLL\.            ");
    write_line("    ./LLLL/^      =   `-|__|____|__|-' =        ^\LLLL\.          ");
    write_line("    /LLLL/^   =         `------------'        =   ^\LLLL\         ");
    write_line("   ~~|.~       =        =      =          =          ~.|~~        ");
    write_line("     ||     =      =      = ____     =         =      ||          ");
    write_line("     ||  =               .-'    '-.        =          ||          ");
    write_line("     ||     _..._ =    .'  .-()-.  '.  =   _..._  =   ||          ");
    write_line("     || = .'_____`.   /___:______:___\   .'_____`.    ||          ");
    write_line("     || .-|---.---|-.   ||  _  _  ||   .-|---.---|-.  ||          ");
    write_line("     || |=|   |   |=|   || | || | ||   |=|   |   |=|  ||          ");
    write_line("     || |=|___|___|=|=  || | || | ||=  |=|___|___|=|  ||          ");
    write_line("     || |=|~~~|~~~|=|   || | || | ||   |=|~~~|~~~|=|  ||          ");
    write_line("     || |*|   |   |*|   || | || | ||  =|*|   |   |*|  ||          ");
    write_line("     || |=|---|---|=| = || | || | ||   |=|---|---|=|  ||          ");
    write_line("     || |=|   |   |=|   || | || | ||   |=|   |   |=|  ||          ");
    write_line("     || `-|___|___|-'   ||o|_||_| ||   `-|___|___|-'  ||          ");
    write_line("     ||  '---------`  = ||  _  _  || =  `---------'   ||          ");
    write_line("     || =   =           || | || | ||      =     =     ||          ");
    write_line("     ||  %@&   &@  =    || |_||_| ||  =   @&@   %@ =  ||          ");
    write_line("     || %@&@% @%@&@    _||________||_   &@%&@ %&@&@   ||          ");
    write_line("     ||,,\\V//\\V//, _|___|------|___|_ ,\\V//\\V//,, ||          ");
    write_line("     |--------------|____/--------\____|---------------|          ");
    write_line("     /- _  -  _   - _ -  _ - - _ - _ _ - _  _-  - _ - _ \         ");
    write_line("    /____________________________________________________\        ");

    while (true)
    {
        write_line("\n=== Strange House ===");
        write_line("1. Explore around the house");
        write_line("2. Knock on the door");
        write_line("3. Return to the Town Square");

        int choice = read_integer("Enter your choice: ");
        
        if (choice == 1)
        {
            // Perform actions specific to exploring the Strange House
            write_line("You explore the Strange House.");
            write_line(" ");

            std::vector<std::string> house_ambience_messages = {
                "The air feels heavy and cold around the house.",
                "You hear creaking sounds coming from the old wooden floors.",
                "A mysterious draft brushes against your skin.",
                "There's an eerie silence that fills the rooms.",
                "You notice a flickering candle in a dimly lit corner.",
                "The walls of the house are adorned with peculiar paintings."
            };

            std::random_device rd;
            std::mt19937 generator(rd());
            std::uniform_int_distribution<int> distribution(0, house_ambience_messages.size() - 1);
            int randomIndex = distribution(generator);
            print_with_delay(house_ambience_messages[randomIndex], 50);

            // Add your code here for exploring the Strange House
            write_line(" ");

        }

        else if (choice == 2) {
            if (Puzzle::train_puzzle_completed) {
                write_line(" ");
                print_with_delay("You knock on the door three times...", 50);
                write_line(" ");
                Character::display_drunkard();
            } else {
                write_line(" ");
                print_with_delay("You knock on the door three times...", 50);
                write_line(" ");
                print_with_delay("No response...", 50);
                write_line(" ");
                // Handle the response when the puzzle is not completed
                // ...
            }
        }

        else if (choice == 3)
        {
            display_town_square();
        }
        else
        {
            write_line("Invalid choice. Please try again.");
        }
    }


    // Display other information or interactions specific to Location 3
}

void Location::display_church()
{
    write_line(" ");
    print_with_delay("walking to Oakmont Church...",50);
    write_line(" ");
    std::this_thread::sleep_for(std::chrono::seconds(2));  // Delay for 2 seconds
    write_line("                                    .' '.                               ");
    write_line("                                  .'  |  `.                             ");
    write_line("                                .'    |    `.                           ");
    write_line("                              .`---.._|_..---'.                         ");
    write_line("                               ||    |=|    ||                          ");
    write_line("                               ||_.-'|=|`-._||                          ");
    write_line("                               ||`-._|=|_.-'||                          ");
    write_line("                          _____||    |=|    ||__                        "); 
    write_line("            ____________.'     `-.   |=|  .'_.'\/`.                     ");
    write_line("          .'       _  .' _______  `-.|_|.' .'\\.'./`.                   ");
    write_line("        .'     _   _.'      _   _        .'\\.' `._./`.                 ");
    write_line("      .' _       _.' __        __     .'\\.'  ___`._ `./`.                 ");
    write_line("    .'        _ .'   _____           .'\\.'         `._`./`.             ");
    write_line("  .'  _  _    .'     ______       .'\\.'  __          `._`./`.             ");
    write_line(".'`--...__ _.'            ______ .'\\.'           __    `._`./`.         ");
    write_line("`--...__ .'   ____            .'\\.'           _          `._`./`.        ");
    write_line("|      .`--...__            .'\\.'     _               ____ `._`./`.      ");
    write_line("| /`-._ `--...__`--...___ .'\\.'              _______       _ `._`./`.    ");
    write_line("| | ) ( |       `--...____\\.'     _     _  .'      .`.         `._`./    ");
    write_line("| |)   (| /`-._             |            .'      .'   `.       _ |        ");
    write_line("| |(--| | | )( |  /`-._`--._|____       /      .'       `.       |        ");
    write_line("| | ) `.| |(  )|  | )( |    | _      _ /      /    .---.  `\\    |        ");
    write_line("| `--._ | |/  \\|  |(  )|`- |         /`--.._/    /     \  ' _   |        ");
    write_line("| `-.   | |)-.(|  |/  \\|   |       __|      |_  | `-    |  |  _ |        ");
    write_line("|    `-.| |) |(|  |)-.(|    |  ___  _ |  __  | __|  `\\- |  |    |        ");
    write_line("'-._    | `--._/  |) |(|    |      __ |      |   | `\\-  |  | _  |        ");
    write_line("    `-._| `--.    `--._/    |  ___    | _    |   | `\\-  |  |   '|        ");
    write_line("        |      `--._        |       _ |    ' |   |O|`\\- | _| _  |        ");
    write_line("        '--._         `--._ |         | _    |_ \" |`\\- |. |  __|        ");
    write_line("             `--._          |       __|      |   | |`\\- |. | __ |        ");
    write_line("                  `--._     |__       |   _  |\" | |`\\- |  |___ |        ");
    write_line("                       `--._|_________|_     | _ |  `\\- |_ |____|        ");
    write_line("                                        '--._|___|       |__|             ");
    
    while (true)
        {
            write_line("\n=== Oakmont Church ===");
            write_line("1. Explore around the church");
            write_line("2. Enter the holy doors");
            write_line("3. Return to the Town Square");

            int choice = read_integer("Enter your choice: ");
            
            if (choice == 1)
            {
                // Perform actions specific to exploring the Strange House
                // Perform actions specific to exploring the Church
                write_line("You explore the Church.");
                write_line(" ");

                std::vector<std::string> church_ambience_messages = 
                {
                    "The sound of a distant choir echoes through the hallways.",
                    "The stained glass windows cast colorful patterns on the floor.",
                    "You feel a sense of tranquility and reverence in the air.",
                    "The scent of incense lingers, creating a peaceful atmosphere.",
                    "Shafts of sunlight illuminate the pews, creating a serene ambiance.",
                    "You notice intricate carvings and sculptures adorning the walls."
                };

                std::random_device rd;
                std::mt19937 generator(rd());
                std::uniform_int_distribution<int> distribution(0, church_ambience_messages.size() - 1);
                int randomIndex = distribution(generator);
                print_with_delay(church_ambience_messages[randomIndex], 50);


                // Add your code here for exploring the Strange House
                write_line(" ");

            }

            else if (choice == 2)
            {
                if (Puzzle::drunk_puzzle_completed)
                {
                    write_line(" ");
                    print_with_delay("You noticed the rug is upside down as you enter...",50);
                    Character::display_priest();

                }
                else
                {
                write_line(" ");
                print_with_delay("You dust your feet on the heavy rug as you enter...",50);
                write_line(" ");
                write_line("                                    \\\\,                       ");
                write_line("                                    /  \\                       ");
                write_line("                                    '<' )                       ");
                write_line("                                    \- /                        ");
                write_line("                                    _)_(_                       ");
                write_line("                                  .'\___/'.                     ");
                write_line("                                 /.-.___.-.\                    ");
                write_line("                                 [_________]                    ");
                write_line("                                  |       |                     ");
                write_line("                            (     |   ,   |       (\/)          ");
                write_line("                         ) _\)_   |  -|-  |      <_@__>         ");
                write_line("                       _(/_ ||    |   |   |       (/\) (\/)     ");
                write_line("                        ||  ||    |       |      (\/) <_@_>     ");
                write_line("                        ||  ||    |       |     <_@_> (/\)      ");
                write_line("                        ||  ||    |       |      (/\|/|-.       ");
                write_line("                        ||  ||   .---------.       _|_|_        ");
                write_line("                        ||  ||_,-'---------'-,__  |WWWWW|       ");
                write_line("                       ____|____________________|_\_____/__     ");
                write_line("                                             __                 ");
                write_line("                          .-.               /  \                ");
                write_line("                         //)\\             |    |               ");     
                write_line("                         ||(||     .-.     (\__/)               ");
                write_line("                        .//\\\.   //|\\    _)__(_               ");
                write_line("                       / `   ` \  )|||(   /      \              ");
                write_line("                .=======================================.       ");
                write_line("                |                                        |      "); 
                write_line("                |                                        |      ");
                write_line("                |                                        |      ");
                write_line(" ");
                print_with_delay("You notice that the priest is pretty young...",50);
                write_line(" ");
                print_with_delay("You end up listening to the sermon and left when it was over",50);
                write_line(" ");
                print_with_delay("You forgot what you were supposed to do...",50);
                write_line(" ");
                }
            }

            else if (choice == 3)
            {
                // Perform actions to return to the Town Square
                display_town_square();
            }
            else
            {
                write_line("Invalid choice. Please try again.");
            }
        }


    // Display other information or interactions specific to Location 3
}


