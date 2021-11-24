#include "mapViewer.hpp"
#include "controller.hpp"
#include <iostream>

int main(){
    const int FPS = 60;
    const int WIDTH = 600;
    const int HEIGHT = 600;

    sf::RenderWindow win(sf::VideoMode(WIDTH, HEIGHT), "GOL", sf::Style::Default);
    win.setFramerateLimit(FPS);
    sf::Event ev;

    MapViewer mv(WIDTH, HEIGHT);
    controller ct(WIDTH, HEIGHT, mv, win);
    mv.CreateMap(40, 40);

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

        // mv.Draw();
        ct.render();

        win.clear();
        // win.draw(mv);
        win.draw(ct);
        win.display();
    }
}
