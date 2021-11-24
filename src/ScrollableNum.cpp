#include "ScrollableNum.hpp"

void ScrollNum::setLimit(int u, int l){
    upper_Limit = u;
    lower_Limit = l;
}

void ScrollNum::eventHandler(sf::Event& ev, sf::Window& win){
    if (ev.type == sf::Event::MouseWheelScrolled){
        // If mouse is scrolled
        sf::FloatRect rect = this->getGlobalBounds();
        sf::Vector2i mPos = sf::Mouse::getPosition(win);
        if (rect.contains(mPos.x, mPos.y)){
            // If mouse is over the text
            std::string curr = this->getString();
            int next;

            if (ev.mouseWheelScroll.delta > 0){
                // If mouse is scrolled in positive direction
                next = std::stoi(curr)+1;
                if (next>upper_Limit) next = upper_Limit;
            }
            else{
                // If mouse is scrolled in negative direction
                next = std::stoi(curr)-1;
                if (next<lower_Limit) next = lower_Limit;
            }
            this->setString(std::to_string(next));
        }
    }
}