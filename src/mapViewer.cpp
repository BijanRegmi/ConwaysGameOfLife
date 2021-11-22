#include "mapViewer.hpp"
#include <iostream>

MapViewer::MapViewer(int w, int h){
    CreateTexture(w, h);
}

void MapViewer::CreateTexture(int w, int h){
    width = w;
    height = h;
    _texture.create(w, h);
    this->setTexture(_texture.getTexture());
}

void MapViewer::CreateMap(int x, int y){
    rows = x;
    cols = y;
    map_obj = new map(x, y);
}

void MapViewer::Update(){
    map_obj->Update();
}

void MapViewer::grid(){
    int numLines = cols+rows-2;
    sf::VertexArray grid(sf::Lines, 2*(numLines));
    
    for(int i=0; i < rows-1; i++){
        int r = i+1;
        float rowY = height/rows*r;
        grid[i*2].position = {0, rowY};
        grid[i*2+1].position = {width, rowY};
    }
    
    for(int i=rows-1; i < numLines; i++){
        int c = i-rows+2;
        float colX = width/cols*c;
        grid[i*2].position = {colX, 0};
        grid[i*2+1].position = {colX, height};
    }

    _texture.draw(grid);
}

void MapViewer::Draw(){
    _texture.clear();
    grid();
    _texture.display();
}