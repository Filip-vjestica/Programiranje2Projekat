#include <iostream>
#include <fstream>

#include "engine.h"
#include "level.h"
#include "sprite.h"

using namespace std;

int main(int argc, char** argv)
{
    Engine *eng = new Engine("RPG Game");
    eng->addTileset("resources/tilesets/grass_tileset.txt", "default");

    ifstream levelStream("resources/levels/mapa1.txt");
    eng->addDrawable(new Level(levelStream, eng->getTileset("default")));


    eng->run();
    delete eng;
    return 0;
}
