#ifndef TILE_H_INCLUDED
#define TILE_H_INCLUDED

#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

class Tile {
private:
    SDL_Rect *tileRect;
public:
    Tile(int x, int y, int w, int h);
    Tile(istream &inputStream);
    SDL_Rect* getRect();
    int x();
    int y();
    int w();
    int h();
    virtual ~Tile();
};

#endif // TILE_H_INCLUDED
