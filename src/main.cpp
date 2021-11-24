#include "mapViewer.hpp"
#include "controller.hpp"
#include <iostream>

int main(){
    sf::VideoMode def = sf::VideoMode::getDesktopMode();
    const int FPS = 10;
    const int WIDTH = def.width;
    const int HEIGHT = def.height;
    const int CONTROLLER_H = 0.1*HEIGHT;

    sf::RenderWindow win(sf::VideoMode(WIDTH, HEIGHT), "Conway's Game Of Life", sf::Style::Fullscreen);
    win.setFramerateLimit(FPS);
    sf::Event ev;

    MapViewer mv(WIDTH, HEIGHT-CONTROLLER_H);
    controller ct(WIDTH, CONTROLLER_H, mv, win);
    mv.setPosition(0, CONTROLLER_H);

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
