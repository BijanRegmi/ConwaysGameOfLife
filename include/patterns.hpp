#ifndef PATTERN_H
#define PATTERN_H

#include <vector>
#include <string>
#include <map>

typedef std::vector<std::vector<bool>> pattern_array;

extern std::map<std::string, pattern_array> pattern_list;
extern std::vector<std::string> pattern_names;


#endif // PATTERN_H