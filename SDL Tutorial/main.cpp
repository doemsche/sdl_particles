#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

int main(int argc, char *argv[]){
    
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;
    
    if(SDL_Init(SDL_INIT_VIDEO) < 0 ){
        cout << "SDL init failed" << endl;
        return 1;
    }
    
    SDL_Window *window = SDL_CreateWindow("Particle Fire Explosion",SDL_WINDOWPOS_UNDEFINED  , SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    
    if(window == NULL){
        SDL_Quit();
        return 2;
    }
    
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
    
    if(renderer == NULL){
        cout << "Could not create renderer" << endl;
        return 3;
    }
    
    if(texture == NULL){
        cout << "Could not create renderer" << endl;
        return 4;
    }
    
    Uint32 *buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
    
    memset(buffer, 0 ,SCREEN_WIDTH* SCREEN_HEIGHT*sizeof(Uint32));
    
//    buffer[30000] = 0xFFFFFFFF;

    for(int i = 0; i < SCREEN_WIDTH*SCREEN_HEIGHT;i++){
        buffer[i] = 0x00FF00FF;
    }
    bool quit = false;
    
    SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH * sizeof(Uint32));
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
    
    SDL_Event event;
    
    while(!quit){
        // Update
        // Draw
        // Check for messages/events
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                quit = true;
            }
        }
    }
    
    delete []buffer;
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    
    cout << "SDL Init succeeded" << endl;
    
    SDL_Quit();
    return 0;
}
