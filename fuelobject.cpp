#include "fuelobject.h"

FuelObject::FuelObject(Sprite *sprite) : Drawable(), Movable() {
    this->sprite = sprite;
}

void FuelObject::draw(SDL_Renderer *renderer) {
    sprite->draw(renderer);
}

void FuelObject::move() {
    sprite->move();
}

void FuelObject::move(int dx, int dy) {
    sprite->move(dx, dy);
}

