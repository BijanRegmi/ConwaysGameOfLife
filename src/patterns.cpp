#include "patterns.hpp"

pattern_array blank{
    {0}
};

pattern_array glider{
    {0, 1, 0},
    {0, 0, 1},
    {1, 1, 1}
};

std::map<std::string, pattern_array> pattern_list = {
    {"Blank", blank},
    {"Glider", glider}
};

std::vector<std::string> pattern_names = {"Blank", "Glider"};