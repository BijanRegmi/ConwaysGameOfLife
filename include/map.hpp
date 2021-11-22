#include <vector>
#include "cell.hpp"

class map{
public:
    map(int x, int y);
    void Update();
    void PrintMap();
    void fill(int row, int col);
    bool isAlive(int row, int col);
    ~map();
private:
    std::vector<std::vector<cell*>> map_array;
    void Calc();
};