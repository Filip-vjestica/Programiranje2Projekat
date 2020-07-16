#include "engine.h"

ostream& operator<<(ostream& out, const Level& l) {
    int rows = l.getLevelMatrix().size();
    int cols = 0;
    if(rows > 0) {
        cols = l.getLevelMatrix()[0].size();
    }
    out << rows << " " << cols << endl;

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++) {
            out << l.getLevelMatrix()[i][j] << " ";
        }
        out << endl;
    }

    return out;
}

Engine::Engine(string title) {
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED, 640, 768, SDL_WINDOW_RESIZABLE);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void Engine::addTileset(Tileset *tileset, const string &name) {
    tilesets[name] = tileset;
}

void Engine::addTileset(istream &inputStream, const string &name) {
    addTileset(new Tileset(inputStream, renderer), name);
}

void Engine::addTileset(const string &path, const string &name) {
    ifstream tilesetStream(path);
    addTileset(tilesetStream, name);
}

Tileset* Engine::getTileset(const string &name) {
    return tilesets[name];
}

void Engine::addDrawable(Drawable *drawable) {
    drawables.push_back(drawable);
}

void Engine::run() {
    int maxDelay = 1000/frameCap;
    int frameStart = 0;
    int frameEnd = 0;
    int points = 0;
    bool running = true;
    SDL_Event event;

    cout << (*dynamic_cast<Level*>(drawables[0])) << endl;

    ifstream spriteSheetStream("resources/creatures/sheep_sheet.txt");
    SpriteSheet *sheet = new SpriteSheet(spriteSheetStream, renderer);
    ifstream spriteSheetStream2("resources/creatures/drvo_sheet.txt");
    SpriteSheet *sheet2 = new SpriteSheet(spriteSheetStream2, renderer);
    ifstream spriteSheetStream5("resources/creatures/drvo_sheet.txt");
    SpriteSheet *sheet5 = new SpriteSheet(spriteSheetStream5, renderer);
    ifstream spriteSheetStream6("resources/creatures/drvo_sheet.txt");
    SpriteSheet *sheet6 = new SpriteSheet(spriteSheetStream6, renderer);
    ifstream spriteSheetStream3("resources/creatures/bridge_sheet.txt");
    SpriteSheet *sheet3 = new SpriteSheet(spriteSheetStream3, renderer);
    ifstream spriteSheetStream4("resources/creatures/wave_sheet.txt");
    SpriteSheet *sheet4 = new SpriteSheet(spriteSheetStream4, renderer);
    ifstream spriteSheetStream7("resources/creatures/win_sheet.txt");
    SpriteSheet *sheetwin = new SpriteSheet(spriteSheetStream7, renderer);
    ifstream spriteSheetStream8("resources/creatures/lose_sheet.txt");
    SpriteSheet *sheetlose = new SpriteSheet(spriteSheetStream8, renderer);

    Sprite *sp = new Sprite(sheet);
    sp->setFrameSkip(3);

    Sprite *spwin = new Sprite(sheetwin);
    spwin->spriteRect->w=128;
    spwin->spriteRect->h=64;
    spwin->spriteRect->x=510;
    spwin->spriteRect->y=641;

    Sprite *splose = new Sprite(sheetlose);
    splose->spriteRect->w=128;
    splose->spriteRect->h=64;
    splose->spriteRect->x=510;
    splose->spriteRect->y=641;

    Sprite *sp2 = new Sprite(sheet2);
    sp2->setFrameSkip(1);
    sp2->spriteRect->x=120;
    sp2->spriteRect->y=80;
    sp2->spriteRect->h=128;
    sp2->spriteRect->w=64;

    Sprite *sp7 = new Sprite(sheet5);
    sp7->setFrameSkip(1);
    sp7->spriteRect->x=340;
    sp7->spriteRect->y=500;
    sp7->spriteRect->h=128;
    sp7->spriteRect->w=64;

    Sprite *sp8 = new Sprite(sheet6);
    sp8->setFrameSkip(1);
    sp8->spriteRect->x=500;
    sp8->spriteRect->y=140;
    sp8->spriteRect->h=128;
    sp8->spriteRect->w=64;

    Sprite *sp3 = new Sprite(sheet3);
    sp3->spriteRect->h=224;
    sp3->spriteRect->w=96;
    sp3->spriteRect->x=352;
    sp3->spriteRect->y=256;

    Sprite *sp4 = new Sprite(sheet4);
    sp4->spriteRect->h=160;
    sp4->spriteRect->w=32;
    sp4->spriteRect->x=0;
    sp4->spriteRect->y=288;

    Sprite *sp5 = new Sprite(sheet4);
    sp5->spriteRect->h=160;
    sp5->spriteRect->w=32;
    sp5->spriteRect->x=210;
    sp5->spriteRect->y=288;

    Sprite *sp6 = new Sprite(sheet4);
    sp6->spriteRect->h=160;
    sp6->spriteRect->w=32;
    sp6->spriteRect->x=420;
    sp6->spriteRect->y=288;

    ///Player *player = new Player(sp);
    Player *player2 = new Player(sp2);
    Player *player3 = new Player(sp3);
    Player *player4 = new Player(sp4);
    Player *player5 = new Player(sp5);
    Player *player6 = new Player(sp6);
    Player *player7 = new Player(sp7);
    Player *player8 = new Player(sp8);

    drawables.push_back(player4);
    drawables.push_back(player5);
    drawables.push_back(player6);
    drawables.push_back(player3);

    FueledSprite *fueledsprite = new FueledSprite(sp);
    ifstream file_("informacije.txt");
    int posX;
    int posY;
    int curentFuel;
    if (file_.is_open()){
        while(file_ >> posX >> posY >> curentFuel){
            fueledsprite->sprite->spriteRect->x = posX;
            fueledsprite->sprite->spriteRect->y = posY;
            fueledsprite->fuel = curentFuel;
        }
    }
    drawables.push_back(fueledsprite);
    movables.push_back(fueledsprite);
    eventListeners.push_back(fueledsprite);

///    drawables.push_back(player);
///    movables.push_back(player);
///    eventListeners.push_back(player);
    drawables.push_back(player2);
    movables.push_back(player2);
    drawables.push_back(player7);
    movables.push_back(player7);
    drawables.push_back(player8);
    movables.push_back(player8);


    while(running) {
        sp4->move(1,0);
        sp5->move(1,0);
        sp6->move(1,0);

        int x1 = sp->spriteRect->x;
        int y1 = sp->spriteRect->y;
        int w1 = sp->spriteRect->w;
        int h1 = sp->spriteRect->h;
        int xw1 = x1 + w1;
        int yh1 = y1 + h1;

        int x2 = sp2->spriteRect->x;
        int y2 = sp2->spriteRect->y;
        int w2 = sp2->spriteRect->w;
        int h2 = sp2->spriteRect->h;
        int xw2 = x2 + w2;
        int yh2 = y2 + h2;

        int x3 = sp7->spriteRect->x;
        int y3 = sp7->spriteRect->y;
        int w3 = sp7->spriteRect->w;
        int h3 = sp7->spriteRect->h;
        int xw3 = x3 + w3;
        int yh3 = y3 + h3;

        int x4 = sp8->spriteRect->x;
        int y4 = sp8->spriteRect->y;
        int w4 = sp8->spriteRect->w;
        int h4 = sp8->spriteRect->h;
        int xw4 = x4 + w4;
        int yh4 = y4 + h4;

        if(points == 3) {
            cout << "WIN" << endl;
            drawables.push_back(spwin);
            ofstream file_("informacije.txt");
            if(file_.is_open()){
                file_ << 0 << " "<< 0 << " " << 300;
            }
            SDL_Delay(600);
        }
        if(fueledsprite->fuel == 0){
            cout << "LOSE" << endl;
            drawables.push_back(splose);
            ofstream file_("informacije.txt");
            if(file_.is_open()){
                file_ << 0 << " "<< 0 << " " << 300;
            }
            SDL_Delay(600);
        }
        if((((xw2 >= x1) && (x2 <= xw1)) && (yh2 >= y1) && (y2 <= yh1))){
           cout<<"Doslo je do kolizije"<<endl;
           cout<<" "<<endl;
           fueledsprite->fuel +=150;
           sp2->spriteRect->x=0;
           sp2->spriteRect->y=641;
           points += 1;
           }

        if((((xw3 >= x1) && (x3 <= xw1)) && (yh3 >= y1) && (y3 <= yh1))){
           cout<<"Doslo je do kolizije"<<endl;
           cout<<" "<<endl;
           fueledsprite->fuel +=150;
           sp7->spriteRect->x=140;
           sp7->spriteRect->y=641;
           points += 1;
           }

        if((((xw4 >= x1) && (x4 <= xw1)) && (yh4 >= y1) && (y4 <= yh1))){
           cout<<"Doslo je do kolizije"<<endl;
           cout<<" "<<endl;
           fueledsprite->fuel +=150;
           sp8->spriteRect->x=280;
           sp8->spriteRect->y=641;
           points += 1;
           }

        if(sp4->spriteRect->x>=608){
            sp4->spriteRect->x=0;
        }
        if(sp5->spriteRect->x>=608){
            sp5->spriteRect->x=0;
        }
        if(sp6->spriteRect->x>=608){
            sp6->spriteRect->x=0;
        }
        if(sp->spriteRect->y<=0){
            sp->spriteRect->y+=1;
        }
        if(sp->spriteRect->y>=590){
            sp->spriteRect->y-=1;
        }
        if(sp->spriteRect->x<=0){
            sp->spriteRect->x+=1;
        }
        if(sp->spriteRect->x>=590){
            sp->spriteRect->x-=1;
        }
        if(sp->spriteRect->y >= 224&&sp->spriteRect->y<416&&sp->spriteRect->x<=320){
            sp->spriteRect->y-=1;
        }
        if(sp->spriteRect->y >= 224&&sp->spriteRect->y<416&&sp->spriteRect->x>=416){
            sp->spriteRect->y-=1;
        }
        if(sp->spriteRect->y > 224&&sp->spriteRect->y<=416&&sp->spriteRect->x<=320){
            sp->spriteRect->y+=1;
        }
        if(sp->spriteRect->y > 224&&sp->spriteRect->y<=416&&sp->spriteRect->x>=416){
            sp->spriteRect->y+=1;
        }
        if(sp->spriteRect->y>224&&sp->spriteRect->y<416&&sp->spriteRect->x<=345){
            sp->spriteRect->x+=1;
        }
        if(sp->spriteRect->y>224&&sp->spriteRect->y<416&&sp->spriteRect->x>=410){
            sp->spriteRect->x-=1;
        }

        frameStart = SDL_GetTicks();
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) {
                running = false;
            } else {
                for(size_t i = 0; i < eventListeners.size(); i++) {
                    eventListeners[i]->listen(event);
                }
            }
        }

        for(size_t i = 0; i < movables.size(); i++) {
            movables[i]->move();
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        for(size_t i = 0; i < drawables.size(); i++) {
            drawables[i]->draw(renderer);
        }

        SDL_RenderPresent(renderer);

        frameEnd = SDL_GetTicks();
        if(frameEnd - frameStart < maxDelay) {
            SDL_Delay(maxDelay - (frameEnd - frameStart));
        }
    }
}

Engine::~Engine() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
