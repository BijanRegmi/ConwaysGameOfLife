#include "Button.hpp"
#include <iostream>

void Button::Init(std::string str, sf::Vector2f size, int charSize, uint32_t color, sf::Font& f) {
    font = f;

    button.setSize(size);
    button.setFillColor(sf::Color(color));
    button.setOutlineColor(sf::Color(0x002461ff));

    // Change origin for box
    sf::FloatRect rect = button.getLocalBounds();
    button.setOrigin(rect.left+rect.width/2, rect.top+rect.height/2);

    text.setString(str);
    text.setFont(font);
    text.setCharacterSize(charSize);

    // Change origin for text
    sf::FloatRect trect = text.getLocalBounds();
    text.setOrigin(trect.left+trect.width/2, trect.top+trect.height/2);
}

void Button::setPosition(sf::Vector2f point) {
    button.setPosition(point);
    text.setPosition(point);
}

void Button::draw(sf::RenderTexture& texture){
    texture.draw(button);
    texture.draw(text);
}

bool Button::isMouseOver(sf::RenderWindow& window) {
    sf::FloatRect rect = button.getGlobalBounds();
    sf::Vector2i mPos = sf::Mouse::getPosition(window);
    if (rect.contains(mPos.x, mPos.y)){
        button.setOutlineThickness(1);
        return true;
    } else {
        button.setOutlineThickness(0);
        return false;
    }
}

bool Button::isClicked(sf::RenderWindow& window){
    return (isMouseOver(window) && sf::Mouse::isButtonPressed(sf::Mouse::Left));
}
