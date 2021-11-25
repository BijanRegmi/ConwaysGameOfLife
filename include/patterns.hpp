#ifndef PATTERN_H
#define PATTERN_H

#include <vector>
#include <string>
#include <map>

typedef std::vector<std::vector<bool>> pattern_array;
extern std::pair<std::string, std::string> pattern_names;

namespace Parser{

int getNum(int position, std::string str);

int digitCount(int number);

pattern_array parse_string(std::string str);
}




#endif // PATTERN_H