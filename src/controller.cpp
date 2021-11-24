#include "controller.hpp"

controller::controller(int width, int height, MapViewer& m, sf::RenderWindow& w):mv(m), win(w){
    _texture.create(width, height);
    this->setTexture(_texture.getTexture());

    sf::Font font;
    font.loadFromFile("Font.ttf");

    // Buttons
    int b_count = 4;
    sf::Vector2f but_size(0.5*width/b_count, height);
    int charSize = width/50;

    start.Init("Start", but_size, charSize, 0x000000ff, font);
    stop.Init("Stop", but_size, charSize, 0x000000ff, font);
    create.Init("Create", but_size, charSize, 0x000000ff, font);
    step.Init("Step", but_size, charSize, 0x000000ff, font);

    start.setPosition(sf::Vector2f(0*width+but_size.x/2, height/2));
    stop.setPosition(sf::Vector2f(0.25*width+but_size.x/2, height/2));
    create.setPosition(sf::Vector2f(0.5*width+but_size.x/2, height/2));
    step.setPosition(sf::Vector2f(0.75*width+but_size.x/2, height/2));
}

void controller::handleInputs(sf::Event& ev){
    if (!(ev.type == sf::Event::MouseButtonPressed && ev.mouseButton.button == sf::Mouse::Left)) return;
    if (start.isClicked(win)) onStart();
    if (stop.isClicked(win)) onStop();
    if (step.isClicked(win)) onStep();
    if (create.isClicked(win)) onCreate();
}

void controller::onCreate(){
    std::cout << "Create clicked" << std::endl;
}

void controller::onStop(){
    std::cout << "Stop clicked" << std::endl;
}

void controller::onStart(){
    std::cout << "Start clicked" << std::endl;
}

void controller::onStep(){
    std::cout << "Step clicked" << std::endl;
}

void controller::render(){
    _texture.clear();

    start.draw(_texture);
    stop.draw(_texture);
    create.draw(_texture);
    step.draw(_texture);

    _texture.display();

}