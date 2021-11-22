#include <SFML/Graphics.hpp>
#include "map.hpp"

class MapViewer: public sf::Sprite{
private:
    sf::RenderTexture _texture;
    
    map* map_obj;

    void CreateTexture(int w, int h);

    int rows, cols, width, height;

    void grid();
public:
    MapViewer(int width, int height);
    void CreateMap(int x, int y);
    void Update();
    void Draw();
};
