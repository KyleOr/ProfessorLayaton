#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>
#include <sstream>

std::string read_string(const std::string& prompt);
int read_integer(const std::string& prompt);
std::vector<std::string> split(const std::string& s, char delimiter);

#endif
