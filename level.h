#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED

#include <iostream>
#include <vector>

#include "drawable.h"
#include "tileset.h"

using namespace std;


class Level : public Drawable {
public:
    typedef vector<vector<char> > LevelMatrix;
    typedef vector<char> LevelRow;
private:
    Tileset *tileset;
    LevelMatrix level;
public:

    Level(istream &inputStream, Tileset *tileset);

    virtual void draw(SDL_Renderer * renderer);

    const LevelMatrix& getLevelMatrix() const;

    ~Level();

    friend ostream& operator<<(ostream&, const Level&);
};

#endif // LEVEL_H_INCLUDED
