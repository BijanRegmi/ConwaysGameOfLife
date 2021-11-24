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

    ScrollNum grid_row;
    ScrollNum grid_num;

    MapViewer& mv;

    sf::RenderWindow& win;

    void onStart();
    void onStop();
    void onStep();
    void onCreate();

public:
    controller(int width, int height, MapViewer& mapViewer, sf::RenderWindow& window);
    void handleInputs(sf::Event& ev);
    void render();
};