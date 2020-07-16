#ifndef TILESET_H_INCLUDED
#define TILESET_H_INCLUDED

#include <iostream>
#include <map>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "tile.h"

using namespace std;

class Tileset {
private:
    map<char, Tile*> tileset;
    SDL_Texture *texture;
    SDL_Rect *dest;
public:
    Tileset(istream &inputStream, SDL_Renderer *renderer);
    void drawTile(char code, int x, int y, SDL_Renderer *renderer);
};

#endif // TILESET_H_INCLUDED
