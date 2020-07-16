#include "fueledsprite.h"

FueledSprite::FueledSprite(Sprite *sprite) : Drawable(), Movable(), KeyboardEventListener() {
    this->sprite = sprite;
}

void FueledSprite::draw(SDL_Renderer *renderer) {
    sprite->draw(renderer);
}

void FueledSprite::move() {
    sprite->move();
}

void FueledSprite::move(int dx, int dy) {
    sprite->move(dx, dy);
}

void FueledSprite::listen(SDL_KeyboardEvent &event) {
    ofstream file_("informacije.txt");
    if(file_.is_open()){
        file_ << sprite->spriteRect->x << " "<< sprite->spriteRect->y << " " << fuel;
    }
    file_.close();
    if(event.type == SDL_KEYDOWN) {
        if(event.keysym.sym == SDLK_LEFT) {
            if(fuel >= 1){
                sprite->setState(sprite->getState()|Sprite::LEFT);
                fuel-=1;
                cout<<fuel<<endl;
            } else {
                cout<<"nemate dovoljno goriva"<<endl;
                sprite->setState(sprite->getState()&~Sprite::LEFT);
            }
        } else if(event.keysym.sym == SDLK_RIGHT) {
            if(fuel >= 1){
                sprite->setState(sprite->getState()|Sprite::RIGHT);
                fuel-=1;
                cout<<fuel<<endl;
            } else {
                cout<<"nemate dovoljno goriva"<<endl;
                sprite->setState(sprite->getState()&~Sprite::RIGHT);
            }
        } else if(event.keysym.sym == SDLK_UP) {
            if(fuel >= 1){
                sprite->setState(sprite->getState()|Sprite::UP);
                fuel-=1;
                cout<<fuel<<endl;
            } else {
                cout<<"nemate dovoljno goriva"<<endl;
                sprite->setState(sprite->getState()&~Sprite::UP);
            }
        } else if(event.keysym.sym == SDLK_DOWN) {
            if(fuel >= 1){
                sprite->setState(sprite->getState()|Sprite::DOWN);
                fuel-=1;
                    cout<<fuel<<endl;
                } else {
                    cout<<"nemate dovoljno goriva"<<endl;
                    sprite->setState(sprite->getState()&~Sprite::DOWN);
                }
        }
    } else if (event.type == SDL_KEYUP) {
        if(event.keysym.sym == SDLK_LEFT) {
            sprite->setState(sprite->getState()&~Sprite::LEFT);
        } else if(event.keysym.sym == SDLK_RIGHT) {
            sprite->setState(sprite->getState()&~Sprite::RIGHT);
        } else if(event.keysym.sym == SDLK_UP) {
            sprite->setState(sprite->getState()&~Sprite::UP);
        } else if(event.keysym.sym == SDLK_DOWN) {
            sprite->setState(sprite->getState()&~Sprite::DOWN);
        }
    }

}
