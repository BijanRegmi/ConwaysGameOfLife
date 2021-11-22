#include "cell.hpp"

void cell::AddNeighbor(cell* neighbor){
    neighbors.push_back(neighbor);
}

int cell::getPopulation(){
    int pop = 0;
    for (auto x: neighbors)
        if (x->Alive.oldgen) pop++;
    return pop;
}

void cell::calc(){
    int population = getPopulation();
    if (Alive.oldgen)
        Alive.newgen = !(population<2 || population>3);
    else
        Alive.newgen = (population == 3);
}

void cell::Update(){
    Alive.oldgen = Alive.newgen;
    Alive.newgen = false;
}