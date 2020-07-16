#ifndef SPRITETREE_H_INCLUDED
#define SPRITETREE_H_INCLUDED

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "drawable.h"

#include "spritesheet.h"

using namespace std;

class SpriteTree : public Drawable {
public:
    enum State:short int {LIVE=0, DEATH=1};
private:
    short int state;
    SpriteSheet *sheet;
    int currentFrame;
    int frameCounter;
    int frameSkip;
public:
    SpriteTree(SpriteSheet *sheet, int width=128, int height=128);
    SDL_Rect *spriteRect;
    int getFrameSkip();
    void setFrameSkip(int frameSkip);
    short int getState();
    void setState(short int state);
    virtual void draw(SDL_Renderer *renderer);
};


#endif // SPRITETREE_H_INCLUDED
