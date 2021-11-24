#include "mapViewer.hpp"
#include "controller.hpp"
#include <iostream>

int main(){
    const int FPS = 10;
    const int WIDTH = 1200;
    const int HEIGHT = 800;

    sf::RenderWindow win(sf::VideoMode(WIDTH, HEIGHT), "GOL", sf::Style::Default);
    win.setFramerateLimit(FPS);
    sf::Event ev;

    MapViewer mv(WIDTH, 0.9*HEIGHT);
    controller ct(WIDTH, 0.1*HEIGHT, mv, win);
    mv.setPosition(0, 0.1*HEIGHT);

    while(win.isOpen()){
        while(win.pollEvent(ev)){
            mv.handleInput(&ev, &win);
            ct.handleInputs(ev);
            if (ev.type == sf::Event::KeyPressed){
                if(ev.key.code == sf::Keyboard::Escape)
                    win.close();
                else if(ev.key.code == sf::Keyboard::Space)
                    mv.Update();
            }
        }

        mv.render();
        ct.render();

        win.clear();
        win.draw(mv);
        win.draw(ct);
        win.display();
    }
}
