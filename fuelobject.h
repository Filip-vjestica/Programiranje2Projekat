#ifndef FUELOBJECT_H_INCLUDED
#define FUELOBJECT_H_INCLUDED

#include <SDL2/SDL.h>

#include "drawable.h"
#include "movable.h"
#include "sprite.h"

class FuelObject : public Drawable, public Movable {
public:
    Sprite *sprite;
    FuelObject(Sprite *sprite);
    int plusfuel=100;
    virtual void draw(SDL_Renderer *renderer);
    virtual void move();
    virtual void move(int dx, int dy);

};

#endif // FUELOBJECT_H_INCLUDED
