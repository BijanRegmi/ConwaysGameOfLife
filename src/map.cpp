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
            if (row>0)              map_array[row][col]->AddNeighbor(map_array[row-1][col]);      // Top
            if (row<y-1)            map_array[row][col]->AddNeighbor(map_array[row+1][col]);      // Bottom
            if (col>0)              map_array[row][col]->AddNeighbor(map_array[row][col-1]);      // Left
            if (col<x-1)            map_array[row][col]->AddNeighbor(map_array[row][col+1]);      // Right
            if (row>0&&col>0)       map_array[row][col]->AddNeighbor(map_array[row-1][col-1]);    // TopLeft
            if (row>0&&col<x-1)     map_array[row][col]->AddNeighbor(map_array[row-1][col+1]);    // TopRight
            if (row<y-1&&col>0)     map_array[row][col]->AddNeighbor(map_array[row+1][col-1]);    // BottomLeft
            if (row<y-1&&col<x-1)   map_array[row][col]->AddNeighbor(map_array[row+1][col+1]);    // BottomRight
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

void map::Update(){
    Calc();
    for (auto x: map_array)
        for (auto y: x)
            y->Update();
}

void map::PrintMap(){
    for (auto x: map_array){
        for (auto y: x)
            std::cout << ((y->Alive.oldgen) ? "*" : " ");
        std::cout << std::endl;
    }
}