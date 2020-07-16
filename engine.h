#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED

#include <fstream>
#include <string>
#include <vector>
#include <map>

#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "drawable.h"
#include "movable.h"
#include "tileset.h"
#include "level.h"
#include "spritesheet.h"
#include "sprite.h"
#include "fueledsprite.h"
#include "spritetree.h"
#include "eventlistener.h"

#include "player.h"

using namespace std;

class Engine {
private:
    map<string, Tileset*> tilesets;
    vector<Drawable*> drawables;
    vector<Movable*> movables;
    vector<EventListener*> eventListeners;
    SDL_Window *window;
    SDL_Renderer *renderer;
    int frameCap = 60;
public:
    Engine(string title);
    void addTileset(Tileset *tileset, const string &name);
    void addTileset(istream &inputStream, const string &name);
    void addTileset(const string &path, const string &name);
    Tileset* getTileset(const string &name);
    void addDrawable(Drawable* drawable);
    void run();
    virtual ~Engine();
};

#endif // ENGINE_H_INCLUDED
