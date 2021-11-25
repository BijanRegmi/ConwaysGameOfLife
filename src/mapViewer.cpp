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
    if (map_created) delete map_obj;
    rows = x;
    cols = y;
    map_obj = new map(x, y);
    map_created = true;
}

void MapViewer::Update(){
    if (map_created) map_obj->Update();
}

void MapViewer::handleInput(sf::Event* ev, sf::RenderWindow* win){
    if (!map_created) return;
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        sf::IntRect rect = this->getTextureRect();
        sf::Vector2i mPos = sf::Mouse::getPosition(*win);
        sf::Vector2f deviation = this->getPosition();
        sf::Vector2i actualMPos(mPos.x-deviation.x, mPos.y-deviation.y);

        if (rect.contains(actualMPos)){
            float dx = width/cols, dy = height/rows;
            int  col = actualMPos.x/dx, row = actualMPos.y/dy;
            map_obj->fill(row, col);
        }
    }
}

void MapViewer::loadPattern(std::string p_name){
    pattern_array p = pattern_list.at(p_name);
    int r = p.size();
    int c = p[0].size();
    
    // Expand size if the map is too small else clear the map
    if (rows < r || cols < c) CreateMap(r*2, c*2);
    else CreateMap(rows, cols);

    for (int i=0; i<r; ++i){
        for (int j=0; j<r; ++j){
            if (p[i][j]) map_obj->fill(i, j);
        }
    }
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

void MapViewer::drawAliveCells(){
    for (int i=0; i<rows; ++i){
        for (int j=0; j<cols; ++j){
            if (map_obj->isAlive(i, j)){
                sf::RectangleShape rect(sf::Vector2f(width/cols, height/rows));
                rect.setPosition(j*width/cols, i*height/rows);
                _texture.draw(rect);
            }
        }
    }
}

void MapViewer::render(){
    if (!map_created) return;
    _texture.clear();
    grid();
    drawAliveCells();
    _texture.display();
}