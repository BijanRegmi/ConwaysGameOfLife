#pragma once

#include <SFML/Graphics.hpp>

class ScrollNum: sf::Text{
private:
    int upper_Limit, lower_Limit;
public:
    void setLimit(int upper_Limit, int lower_Limit);
    void eventHandler(sf::Event& ev, sf::Window& win);
};