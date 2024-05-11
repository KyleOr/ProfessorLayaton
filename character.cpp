#include "character.h"
#include "splashkit.h"
#include "locations.h"
#include "utils.h"
#include "game.h"
#include "puzzle.h"





void Character::display_conductor()
{
    // Display the dialogue and actions of the conductor character
    write_line("           _A               ");
    write_line("         .'`""`.            "); 
    write_line("        /   , , \           ");
    write_line("       |   <\^/> |          ");
    write_line("       |  < (_) >|          ");
    write_line("       /====\               ");
    write_line("      (.--._ _.--.)         ");
    write_line("       |\  -`\- /|          ");
    write_line("       |(_.- >-.)|          ");
    write_line("       \__.-'^'._/          ");
    write_line("        |\   .  /           ");
    write_line("     _.'\ '----'|'-.        ");
    write_line(" _.-'  O ;-.__.' \O `o.     ");
    write_line("/o \      \/-.-\/|     \    ");
    write_line("|    ;,     '.|\| /         ");
    write_line(" ");
    Game::print_with_delay("You are greeted by the conductor.",50);
    write_line(" ");

    if (Puzzle::train_puzzle_completed)
    {
        Game::print_with_delay("Conductor: Welcome back! Thanks to your efforts, the trains are running smoothly again.", 50);
        write_line(" ");
        Game::print_with_delay("Conductor: How may I assist you today?", 50);
    }

    else
    {
        Game::print_with_delay("You notice a shiny gem on the conductor's helmet.", 50);
        write_line(" ");
        Game::print_with_delay("Conductor: Welcome, traveler! I apologize, but our train system is experiencing an issue", 50);
        write_line(" ");
        Game::print_with_delay("Conductor: Either way, how may I assist you today?", 50);    
        write_line(" ");
    }
    
    write_line(" ");

        int choice = 0;

    while (choice != 5)
    {
        // Display user options
        write_line("1. Inquire about the town's history");
        write_line("2. Ask about the memory loss phenomenon");
        write_line("3. Seek advice on solving the puzzles");
        write_line("4. Train system issue?");
        write_line("5. Return to Oakmont Station");
        
        // Get user's choice
        int choice = read_integer("Enter your choice: ");
        
        // Process user's choice
        switch (choice)
        {
            case 1:
                Game::print_with_delay("You: Can you tell me more about the town's history?",50);
                write_line(" ");
                Game::print_with_delay("Conductor: Ah, the history of this place is fascinating. The town of Oakmont has a rich past, filled with tales of ancient civilizations, hidden treasures, and forgotten rituals. Sadly, with the memory loss, much of the town's history has been obscured. But perhaps, by exploring the forgotten areas and solving the puzzles, you can piece together the fragments and rediscover the lost stories.",50);
                // Add further dialogue and actions related to the town's history
                break;
                
            case 2:
                Game::print_with_delay("You: What can you tell me about the memory loss phenomenon?",50);
                write_line(" ");
                Game::print_with_delay("Conductor: The memory loss has plagued our town for months now. It's a baffling enigma that has affected everyone here except me because I was out of town. People wake up not knowing who they are or what happened yesterday. As an archaeologist with a talent for solving puzzles, you may hold the key to unlocking this mystery. I suggest starting your investigation by speaking with the townsfolk and gathering any clues you can find. Together, we can restore the lost memories and bring back the essence of Oakmont.",50);
                // Add further dialogue and actions related to the memory loss phenomenon
                break;
                
            case 3:
                Game::print_with_delay("You: I need some advice on solving the puzzles I've encountered.",50);
                write_line(" ");
                Game::print_with_delay("Conductor: Ah, puzzles can be quite tricky, can't they? Fear not, my friend. Solving them requires a combination of logic, observation, and sometimes a touch of creativity. Remember to examine your surroundings closely, as even the smallest detail can hold a clue. If you're ever stuck, don't hesitate to seek help from the townsfolk or explore different areas for new insights. I believe in your puzzle-solving prowess!",50);
                // Add further dialogue and actions related to puzzle-solving advice
                break;

            case 4:
            {
                if (Puzzle::train_puzzle_completed)
                {
                    Game::print_with_delay("Conductor: I can't appreciate how much you've helped me.",50);
                    write_line(" "); 
                    Game::print_with_delay("Conductor: I trust that you save this town soon with that amulet.",50);
                    write_line(" "); 
                }
                            
                else
                {
                    Game::print_with_delay("You: I'm curious as to why your trains have stopped working?",50);
                    write_line(" ");
                    Game::print_with_delay("Conductor: Ah, well I am currently in a conundrum as the trains have parked in the wrong order.",50);
                    write_line(" ");
                    Game::print_with_delay("Conductor: The trains can't operate again until I solve the issue.",50);
                    write_line(" ");
                    Game::print_with_delay("Conductor: Actually, I recognise that top hat you're wearing, you seem like a smart fellow, if anything, would you like to help me get the trains back on track?.",50);
                    write_line(" ");

                    string confirmation = read_string("The first of many puzzle begins. Are you ready to take on the challenge? (Y/N): ");
                    if (confirmation == "Y" || confirmation == "y")
                    {
                        // Start the Train Schedule Conundrum puzzle
                        Puzzle trainPuzzle;
                        trainPuzzle.start_train_puzzle();
                    }
                    else
                    {
                        Game::print_with_delay("Conductor: No problem. Let me know if you change your mind. Good luck!",50);
                    }
                }

                break;

            case 5:
            {
                Game::print_with_delay("You waved goodbye to the conductor...");
                write_line(" ");
                Location::display_train();
                break;
            }

            }
            default:
                Game::print_with_delay("You: I'm sorry, I didn't catch that.",50);
                Game::print_with_delay("Conductor: No worries, take your time and let me know if you need any assistance.",50);
                // Add dialogue and actions for an invalid choice
                break;
        }
        
        // Add any additional dialogue or actions here
        write_line(" ");

    }
        
}

bool Character::memory_flask_dialogue_played = false;

void Character::display_drunkard()
{
    write_line("                                         d$$S$S$S$S$S$SSb                           ");
    write_line("                                      :$$S^S$S$S$S$S$S^S$$;                         ");
    write_line("                                      SSP    `^$S$S$^'   TSS                        ");
    write_line("                                     $$        `'         $$                        ");
    write_line("                                    _SS ,-             -   SS_                      ");
    write_line("                                     :-.|  _    - .-   _  |.-;                      ");
    write_line("                                    :\ (; '  - _ '._.-  ` |)/;                      ");
    write_line("                                      \ |  , o       o .  | /                       ");
    write_line("                                        :     -'   `-     ;                         ");
    write_line("                                         ;.              :                          ");
    write_line("                                         : `    ._.    ' ;                          ");
    write_line("                                       .sSb   ._____.   dSs.                        ");
    write_line("                                    _.d8dSSb.   ._.   .SSbT8b._                     ");
    write_line("                                _.oOPd88SSSS T.     .P SSSS888OOo.                  ");
    write_line("                            _.mMMOOPd888SSSSb TSqqqSP dSSSS88OMOOOMm._              ");
    write_line("                       .oOMMMOMOOM8O8OSSSSSb TSSSP dSSSSS8OOMMOOMMOOOo._            ");
    write_line("                      .OOMMOOOMMOOMOOOO   ^SSSTSSP dSSS^ OOOOMMOOMMMOOMMMb.         ");
    write_line("                     dOOOMMMOMMOOOMOOOO       ^SSSS^    :OOO8MMMOOMMOOMMOMMb        ");
    write_line("                    :MMMOOMMOMMOOMMO8OS         `P       8O8OPdMMOOMMOMMOMMMM;      ");
    write_line("                    MMMMOOMMMMMOOMbTO8S;                :8888MMMMMOMMOMMOMMMMM      ");
    write_line("                    OMMMMOOMMMMOOOMMOOOS         S      :O8OPdMOMMMOMOMMOOMMMMO     ");
    write_line("                    :OMMMMOOMMOMMOOMbTObTb.     :S;   .PdOPdMOOMMMMMOMMOMMMMMO;     ");
    write_line("                    MOOMMMMOMMOMMOOMMMOObTSSg._.SSS._.PdOPdMOOMMMMOMMMMOMMMMOOM     ");
    write_line("                    MMOMMMMOMMMOMMOOMMbT8bTSSSSSSSSSPd8OPdOOOMMMMOOMMMMOMMMOOMM     ");
    write_line("                    MMOMMMOMMMMMOMMOOMMMbT8bTSSSSSPd88PdOOOOMMMMOOMMMMMMMMOOMMM     ");

    write_line(" ");
    
        Game::print_with_delay("A disheveled man stumbles out of the door, looking lost and confused.", 50);
        write_line(" ");
    if (Puzzle::drunk_puzzle_completed && !Character::memory_flask_dialogue_played)
    {
        Game::print_with_delay("Drunkard: Hey, it's you! I remember you from the game!", 50);
        write_line(" ");
        Game::print_with_delay("Drunkard: *burp* The conductor from the train station brought me back to my bed last night", 50);
        write_line(" ");
        Game::print_with_delay("Drunkard: *Trips* Ouch, anyway, I got this Memory Flask to give to you", 50);
        write_line(" ");
        Game::print_with_delay("Your left hand is now occupied with a fragile flask you must carry around for the rest of your journey at Oakmont...", 50);
        write_line(" ");
        Game::print_with_delay("Drunkard: *Slurs*, Anyway, you put liquid into that flask and swish it around and it doubles in volume!", 50);
        write_line(" ");
        Game::print_with_delay("Drunkard: *Vomits*, If you can't tell, thats how I got drunk in the first place, today I will commit to becoming sober", 50);
        write_line(" ");
        // Set the flag to indicate that the dialogue has been played
        Character::memory_flask_dialogue_played = true;
    } 
    else 
    {
        Game::print_with_delay("Drunkard: Hey, you! You seem different from the others.", 50);
        write_line(" ");
    }

    int choice = 0;
    
    while (choice != 5) 
    {
        // Display user options
        write_line("1. Ask the drunkard about his past.");
        write_line("2. Inquire about any clues he may have.");
        write_line("3. Ignore the drunkard and continue exploring.");
        write_line("4. Offer whiskey");
        write_line("5. Point out a butterfly on his door and hide behind a tree.");
        
        // Get user's choice
        choice = read_integer("Enter your choice: ");
        
        // Process user's choice
        switch (choice) {
            case 1:
                write_line(" ");
                Game::print_with_delay("You: What happened to you? Who were you before losing your memories?", 50);
                write_line(" ");
                Game::print_with_delay("Drunkard: Ah, the memories... I used to be somebody important in this town.", 50);
                write_line(" ");
                Game::print_with_delay("Drunkard: But now... it's all a blur. Fragments of a forgotten life.", 50);
                write_line(" ");
                Game::print_with_delay("Even though you have the amulet, it appears he is too drunk anyway...", 50);
                write_line(" ");
                // Continue the conversation based on the player's choice
                break;
                
            case 2:
                write_line(" ");
                Game::print_with_delay("You: Do you have any clues that could help me with the investigation?", 50);
                write_line(" ");
                Game::print_with_delay("Drunkard: Clues, you say? Hm... I might have a thing or two up my sleeve.", 50);
                write_line(" ");
                Game::print_with_delay("Drunkard: But remember, not everything is as it seems. Trust your instincts and dig deeper.", 50);
                write_line(" ");
                // Continue the conversation based on the player's choice
                break;
                
            case 3:
                write_line(" ");
                Game::print_with_delay("You decide to ignore the drunkard for now and continue exploring.", 50);
                write_line(" ");
                Game::print_with_delay("Drunkard: Hey I'm talkin' to ya! ", 50);
                write_line(" ");
                Game::print_with_delay("The drunk furrows his brows against you...", 50);
                write_line(" ");
                // ouch
                break;
                
            case 4:
                write_line(" ");
                Game::print_with_delay("You: I got some good whiskey behind that tree, wanna try some?", 50);
                write_line(" ");
                
                if (Puzzle::drunk_puzzle_completed)
                {
                    write_line(" ");
                    Game::print_with_delay("Drunkard: Oh sure, thanks buddy!", 50);
                    write_line(" ");
                    Game::print_with_delay("The drunkard follows you as you walk towards the tree... You both drink the whiskey and get drunk.", 50);
                    write_line(" ");
                    Game::print_with_delay("Drunkard: Hic! Let's play that game again, mate!", 50);
                    write_line(" ");
                    // Start the drunk game
                    Puzzle drunkPuzzle;
                    drunkPuzzle.start_drunk_imitation();
                    break;
                }
                else
                {
                    Game::print_with_delay("Drunkard: Oh sure thanks buddy!", 50);
                    write_line(" ");
                    Game::print_with_delay("The drunkard follows you as you walk towards the tree... you drink the whiskey yourself and now you're both drunk.", 50);
                    write_line(" ");
                    // Start the drunk game
                    Puzzle drunkPuzzle;
                    drunkPuzzle.start_drunk_imitation();
                    // Handle the additional option
                    break;
                }
                
            case 5:
                write_line(" ");
                Game::print_with_delay("You expertly showcase your sharp awareness of your surroundings by pointing at a nonexistent butterfly on the doorknob...", 50);
                write_line(" ");
                Game::print_with_delay("The drunk's curiosity makes him turn around, in which you make a run for it behind a tree...", 50);
                write_line(" ");
                Game::print_with_delay("How did that work?", 50);
                write_line(" ");
                Game::print_with_delay("You wait for the drunkard to go back in", 50);
                write_line(" ");
                Location::display_house();
                // Return to front of house 
                break;
                
            default:
                write_line(" ");
                Game::print_with_delay("Drunkard: What was that? I didn't catch that.", 50);
                write_line(" ");
                // Handle invalid choices or unrecognized input
                break;
        }
    }
}

bool Character::enigma_key_dialogue_played = false;

void Character::display_priest()
{

    
    write_line("                    .---.       ");
    write_line("                   /.' '.\      ");
    write_line("                   \\   ||      ");
    write_line("           /^\    ,_),-','      ");
    write_line("         .'_|_'.     ()`        ");
    write_line("        <   |   >    ||         ");
    write_line("         \_____/     ||         ");
    write_line("          /a a\      ||         ");
    write_line("         /-.^.-\    (_|         ");
    write_line("       .'(  `  )'-._/|;\        ");
    write_line("      /  (     )  /; || |       ");
    write_line("     /`'-(     )-';  || |       ");
    write_line("    ; `'=|(   )|=' _/|| |       ");
    write_line("    |   \| |~| |  |/ || |       ");
    write_line("    |\   \ | | |  ;  || |       ");
    write_line("    | \   ||=| |=<\  || |       ");
    write_line("    | /\_/\| | |  \`-||_/       ");
    write_line("    '-| `;'| | |  |  ||         ");
    write_line("      |  |+| |+|  |  ||         ");
    write_line("      |  | | | |  |  ||         ");
    write_line("      |  """ """  |  ||         ");
    write_line("      |           |  ||         ");
    write_line("      |_ _ _ _ _ _|  ||         ");
    write_line("      |,;,;,;,;,;,|  ||         ");
    write_line("      `|||||||||||`  ||         ");
    write_line("       |||||||||||   ||         ");


    // Display initial dialogue
    if (Puzzle::priest_puzzle_completed && !Character::enigma_key_dialogue_played)
    {
        Game::print_with_delay("Priest: I can't believe you beat me at blackjack!",50);
        write_line(" ");
        Game::print_with_delay("Priest: Either way, here is the Enigma Key. From your performance against me the best BlackJack player, I'm sure you can rid of these town's memory loss.");
        write_line(" ");
        Game::print_with_delay("Priest: Don't tell anyone about BlackJack either",50);
        write_line(" ");
        Game::print_with_delay("You didn't even know the Priest had an Enigma Key or something alike");
        write_line(" ");
        Character::enigma_key_dialogue_played = true;
    }

    else if (Puzzle::priest_puzzle_completed)
    {
        Game::print_with_delay("Priest: Good game last time, what may I help you with this time?",50);
        write_line(" ");
    }
    else
    {
        Game::print_with_delay("You: Excuse me, Father. I've come seeking answers in this town of lost memories.", 50);
        write_line(" ");
        Game::print_with_delay("Priest: Ah, my child. I sense a heavy burden upon your shoulders. Speak, and I shall do my best to guide you.", 50);
        write_line(" ");
    }

    int choice = 0;

    while (choice != 5) 
    {
        // Display user options
        write_line("1. Ask the priest about the cause of the memory loss.");
        write_line("2. Inquire about the artifacts and their role in restoring memories.");
        write_line("3. Seek advice on how to navigate the town's mysteries.");
        write_line("4. Lie to the priest?");
        write_line("5. Leave the Church");
        write_line(" ");

        // Get user's choice
        choice = read_integer("Enter your choice: ");

        // Process user's choice
        switch (choice) 
        {
            case 1:
                Game::print_with_delay("You: Father, what do you believe is the cause of the memory loss in this town?", 50);
                write_line(" ");
                // Priest's response
                Game::print_with_delay("Priest: My child, the memory loss that afflicts this town is a manifestation of a deeper spiritual disturbance. It is a consequence of forgotten secrets and unhealed wounds that have plagued our community for generations.", 50);
                write_line(" ");
                break;

            case 2:
                Game::print_with_delay("You: Father, I've come across various artifacts in my investigation. How do these artifacts contribute to restoring the lost memories?", 50);
                write_line(" ");
                // Priest's response
                Game::print_with_delay("Priest: The artifacts you have encountered hold fragments of forgotten stories and the essence of our shared history. By uncovering the secrets they hold and piecing them together, you can initiate the process of memory restoration.", 50);
                write_line(" ");
                break;

            case 3:
                Game::print_with_delay("You: Father, I feel lost and overwhelmed by the mysteries of this town. Could you offer me some guidance on how to navigate through them?", 50);
                write_line(" ");
                // Priest's response
                Game::print_with_delay("Priest: In times of uncertainty, my child, turn to your intuition and the wisdom gained from your own experiences. Trust in the journey and allow the threads of destiny to weave their path. Seek solace within the silence of your heart, and the path shall be revealed.", 50);
                write_line(" ");
                break;

            case 4:

                if (Puzzle::priest_puzzle_completed)
                {
                    Game::print_with_delay("Priest: Don't accuse me like that again, lets just play another game of blackjack",50);
                    write_line(" ");
                    Game::print_with_delay("Before you could respond, the Priest has already shuffled and dealth your hand...");
                    write_line(" ");
                    Puzzle priestPuzzle;
                    priestPuzzle.start_priest_blackjack();
                }
                
                else
                {
                    Game::print_with_delay("You: Through my investigation, I suspect that you are the culprit of the town's memory loss!", 50);
                    write_line(" ");
                    Game::print_with_delay("Priest: You are making a fool of yourself, I would never do such a thing!", 20);
                    write_line(" ");
                    Game::print_with_delay("You: I have my doubts... in fact, I am willing to take this gamble and pin you as a fraud!");
                    write_line(" ");  
                    Game::print_with_delay("Priest: So you are willing to gamble? fine!", 20);
                    write_line(" ");
                    Puzzle priestPuzzle;
                    priestPuzzle.start_priest_blackjack();
                }
                break;

            case 5:
                Game::print_with_delay("You: Im gonna go think a bit...", 50);
                write_line(" ");
                Game::print_with_delay("Priest: Alright, take care.", 50);
                write_line(" ");
                Game::print_with_delay("You waved goodbye and left the church, this time the rug wasn't upside down.");
                write_line(" ");
                Location::display_church();
                // Additional dialogue or actions related to receiving the Enigma Key can be added here
                break;

            default:
                write_line(" ");
                Game::print_with_delay("Priest: What was that? I didn't catch that.", 50);
                write_line(" ");
                // Handle invalid choices or unrecognized input
                break;
        }
    
    }

    // Continue the rest of the conversation and interactions with the priest as desired

}