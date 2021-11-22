#include <vector>
#include "cell.hpp"

class map{
public:
    map(int x, int y);
    void Update();
    void PrintMap();
    ~map();
private:
    std::vector<std::vector<cell*>> map_array;
    void Calc();
};