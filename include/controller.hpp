#pragma once

#include "Button.hpp"
#include "ScrollableNum.hpp"
#include "mapViewer.hpp"
#include <SFML/Graphics.hpp>

class controller: public sf::Sprite{
private:
    bool isRunning=false;

    sf::RenderTexture _texture;
    
    Button start;
    Button stop;
    Button create;
    Button step;
    Button pattern_btn;

    ScrollNum grid_row;
    ScrollNum grid_col;

    MapViewer& mv;

    sf::RenderWindow& win;
    sf::Font font;

    int pattern_idx=0;

    void onStart();
    void onStop();
    void onStep();
    void onCreate();
    void onPattern();

public:
    controller(int width, int height, MapViewer& mapViewer, sf::RenderWindow& window);
    void handleInputs(sf::Event& ev);
    void render();
};