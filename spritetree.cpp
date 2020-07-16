#include "spritetree.h"

SpriteTree::SpriteTree(SpriteSheet *sheet, int width, int height) : Drawable() {
    state = SpriteTree::LIVE;
    this->sheet = sheet;
    currentFrame = 0;
    frameCounter = 0;
    frameSkip = 1;



    spriteRect = new SDL_Rect();
    spriteRect->x = 0;
    spriteRect->y = 0;
    spriteRect->w = width;
    spriteRect->h = height;
}

int SpriteTree::getFrameSkip() {
    return frameSkip;
}

void SpriteTree::setFrameSkip(int frameSkip) {
    if(frameSkip < 0) {
        frameSkip = 0;
    }

    this->frameSkip = frameSkip+1;
}

short int SpriteTree::getState() {
    return state;
}

void SpriteTree::setState(short int state) {
    this->state = state;
}

void SpriteTree::draw(SDL_Renderer *renderer) {
    if(state&DEATH) {
        sheet->drawFrame("death", currentFrame, spriteRect, renderer);
    } else if(state == LIVE) {
        sheet->drawFrame("live", 0, spriteRect, renderer);
    }

    frameCounter++;
    if(frameCounter%frameSkip == 0) {
        currentFrame++;
        if(currentFrame >= 1) {
            currentFrame = 0;
        }
        frameCounter = 0;
    }
}
