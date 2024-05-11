#include "utils.h"
#include "splashkit.h"
#include <string>
#include <sstream>
#include <vector>

std::string read_string(const std::string& prompt)
{
    std::string result;
    write(prompt);
    result = read_line();
    return result;
}

int read_integer(const std::string& prompt)
{
    while (true)
    {
        try
        {
            write(prompt);
            std::string input = read_line();
            return std::stoi(input);
        }
        catch (const std::invalid_argument&)
        {
            write_line("Invalid input. Please enter a valid integer.");
        }
    }
}



// Split a string into substrings based on a delimiter
std::vector<std::string> split(const std::string& s, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}