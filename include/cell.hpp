#include <vector>

class cell
{
public:
    struct State
    {
        bool oldgen = false;
        bool newgen = false;
    }Alive;
private:
    std::vector<cell*> neighbors;
    
    int getPopulation();
public:
    cell(){};
    
    void AddNeighbor(cell* neighbor);
    void calc();
    void Update();
    
    // ~cell();
};
