#include "map.hpp"
#include <iostream>

map::map(int x, int y){
    // Create map array
    for (int row=0; row<y; ++row){
        std::vector<cell*> horiz;
        for (int col=0; col<x; ++col){
            cell* c = new cell;
            horiz.push_back(c);
        }
        map_array.push_back(horiz);
    }

    // Add Neighbors
    for (int row=0; row<y; ++row){
        for (int col=0; col<x; ++col){
            for (int i=-1; i<2; ++i){
                for (int j=-1; j<2; ++j){
                    if (!i && !j) continue;
                    int r = (row+i+y)%y;
                    int c = (col+j+x)%x;
                    map_array[row][col]->AddNeighbor(map_array[r][c]);
                }
            }
        }
    }
}

map::~map(){
    for (int i=0, j=map_array.size(); i<j; ++i){
        for (int k=0, l=map_array[i].size(); k<l; ++k){
            delete map_array[i][k];
        }
    }
}

void map::Calc(){
    for (auto x: map_array)
        for (auto y: x)
            y->calc();
}

void map::fill(int r, int c){
    map_array[r][c]->Alive.oldgen ^= true;
}

bool map::isAlive(int r, int c){
    return map_array[r][c]->Alive.oldgen;
}

void map::Update(){
    Calc();
    for (auto x: map_array)
        for (auto y: x)
            y->Update();
}