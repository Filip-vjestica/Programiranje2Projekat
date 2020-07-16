#ifndef FUELEDSPRITE_H_INCLUDED
#define FUELEDSPRITE_H_INCLUDED

#include <SDL2/SDL.h>
#include <iostream>
#include<fstream>

#include "drawable.h"
#include "movable.h"
#include "keyboardeventlistener.h"
#include "sprite.h"

class FueledSprite : public Drawable, public Movable, public KeyboardEventListener {
public:
    Sprite *sprite;
    FueledSprite(Sprite *sprite);
    int fuel=300;
    virtual void draw(SDL_Renderer *renderer);
    virtual void move();
    virtual void move(int dx, int dy);
    virtual void listen(SDL_KeyboardEvent &event);

};


#endif // FUELEDSPRITE_H_INCLUDED
