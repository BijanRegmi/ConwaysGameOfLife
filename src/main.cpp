#include "mapViewer.hpp"
#include <iostream>

int main(){
    const int FPS = 60;
    const int WIDTH = 600;
    const int HEIGHT = 600;

    sf::RenderWindow win(sf::VideoMode(WIDTH, HEIGHT), "GOL", sf::Style::Default);
    win.setFramerateLimit(FPS);
    sf::Event ev;

    MapViewer mv(WIDTH, HEIGHT);
    mv.CreateMap(8, 8);

    while(win.isOpen()){
        while(win.pollEvent(ev)){
            mv.handleInput(&ev, &win);
            if (ev.type == sf::Event::KeyPressed){
                if(ev.key.code == sf::Keyboard::Escape)
                    win.close();
                else if(ev.key.code == sf::Keyboard::Space)
                    mv.Update();
            }
        }

        mv.Draw();

        win.clear();
        win.draw(mv);
        win.display();
    }
}
