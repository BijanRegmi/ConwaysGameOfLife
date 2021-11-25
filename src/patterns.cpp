#include "patterns.hpp"

pattern_array glider{
    {0, 1, 0},
    {0, 0, 1},
    {1, 1, 1}
};

std::map<std::string, pattern_array> pattern_list = {
    {"Glider", glider}
};