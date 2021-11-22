#include <vector>

class cell
{
private:
    struct State
    {
        bool oldgen = false;
        bool newgen = false;
    }Alive;
    
    std::vector<cell*> neighbors;
public:
    cell();
    void AddNeighbor(cell* neighbor);
    int getPopulation();
    void calc();
    void Update();
    ~cell();
};
