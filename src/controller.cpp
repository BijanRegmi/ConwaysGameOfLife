#include "controller.hpp"

controller::controller(int width, int height, MapViewer& m, sf::RenderWindow& w):mv(m), win(w){
    _texture.create(width, height);
    this->setTexture(_texture.getTexture());

    font.loadFromFile("Font.ttf");

    // Buttons
    int b_count = 4;
    sf::Vector2f but_size(0.5*width/b_count, height);
    int charSize = width/50;

    start.Init("Start", but_size, charSize, 0x000000ff, font);
    stop.Init("Stop", but_size, charSize, 0x000000ff, font);
    step.Init("Step", but_size, charSize, 0x000000ff, font);
    pattern_btn.Init("Blank", but_size, charSize, 0x000000ff, font);
    create.Init("Create", but_size, charSize, 0x000000ff, font);

    start.setPosition(sf::Vector2f(0*width+but_size.x/2, height/2));
    stop.setPosition(sf::Vector2f(0.2*width+but_size.x/2, height/2));
    step.setPosition(sf::Vector2f(0.4*width+but_size.x/2, height/2));
    pattern_btn.setPosition(sf::Vector2f(0.6*width+but_size.x/2, height/2));
    create.setPosition(sf::Vector2f(0.8*width+but_size.x/2, height/2));

    grid_col.setString("20");
    grid_row.setString("20");
    grid_col.setLimit(100, 10);
    grid_row.setLimit(100, 10);
    grid_col.setFont(font);
    grid_row.setFont(font);
    grid_col.setCharacterSize(charSize);
    grid_row.setCharacterSize(charSize);
    grid_col.setPosition(width-but_size.x/2, 0);
    grid_row.setPosition(width-but_size.x/2, height/2);
}

void controller::handleInputs(sf::Event& ev){
    grid_row.eventHandler(ev, win);
    grid_col.eventHandler(ev, win);
    if (!(ev.type == sf::Event::MouseButtonPressed && ev.mouseButton.button == sf::Mouse::Left)) return;
    if (start.isClicked(win)) onStart();
    if (stop.isClicked(win)) onStop();
    if (step.isClicked(win)) onStep();
    if (create.isClicked(win)) onCreate();
    if (pattern_btn.isClicked(win)) onPattern();
}

void controller::onCreate(){
    mv.CreateMap(grid_row.getNum(), grid_col.getNum());
    mv.loadPattern("bob$2bo$3o!");
    isRunning = false;
}

void controller::onStop(){
    isRunning = false;
}

void controller::onStart(){
    isRunning = true;
}

void controller::onStep(){
    mv.Update();
}

void controller::onPattern(){
    
}

void controller::render(){
    if (isRunning) mv.Update();
    _texture.clear();

    start.draw(_texture);
    stop.draw(_texture);
    create.draw(_texture);
    step.draw(_texture);
    pattern_btn.draw(_texture);
    _texture.draw(grid_row);
    _texture.draw(grid_col);

    _texture.display();

}